# 指针与函数
## A部分：指针
## 一.深入 C++ 的"地址魔法"—— 指针

* **指针是什么？—— 内存地址的"门牌号"**

类比：

>如果变量是存放数据的"房间"，

- 则：
      -  **变量的值是"房间里的东西"**
      -  **变量的地址是"房间的门牌号"**
      -  **指针就是专门用来"存放门牌号"的变量**

## 二.指针的三个核心操作：

>1.取地址(&): 获取变量的内存地址

```cpp
int num = 10;
int* ptr = &num;  // ptr存放num的地址
```

>2.声明指针(*): 创建一个指针变量

```cpp
int* ptr;  // 声明一个指向整数的指针
double* dptr;  // 声明一个指向浮点数的指针
```

>3.解引用(*): 通过地址访问对应的值

```cpp
int num = 10;
int* ptr = &num;
*ptr = 20;  // 通过ptr修改num的值
cout << num << endl;  // 输出20
```

完整示例：

```cpp
#include <iostream>
using namespace std;

int main() {
    int num = 10;  // 普通整型变量

    int* ptr = &num;  // ptr指向num

    cout << "num的值: " << num << endl;
    cout << "num的地址: " << &num << endl;
    cout << "ptr存储的地址: " << ptr << endl;
    cout << "ptr指向的值: " << *ptr << endl;

    *ptr = 20;  // 通过指针修改num的值
    cout << "修改后num的值: " << num << endl;

    return 0;
}
```

## 三.指针的重要用法

### 1.指针与数组

* 在 C++ 中，**数组名实际上是指向数组第一个元素的指针：**

```cpp
int numbers[5] = {10, 20, 30, 40, 50};
int* ptr = numbers;  // ptr指向numbers[0]

cout << *ptr << endl;  // 输出10
cout << *(ptr + 1) << endl;  // 输出20
cout << *(ptr + 2) << endl;  // 输出30

// 通过指针遍历数组
for(int i = 0; i < 5; i++) {
    cout << *(ptr + i) << " ";  // 输出 10 20 30 40 50
}
```

### 2.空指针
>空指针表示"不指向任何地址"，用于初始化或重置指针：

```cpp
int* ptr = nullptr;  // C++11标准
// int* ptr = NULL;  // 旧标准，但仍然常用

if(ptr == nullptr) {
    cout << "这是一个空指针" << endl;
}

// 危险操作！不要解引用空指针
// *ptr = 10;  // 程序会崩溃
```

### 四.指针陷阱与注意事项
1.**野指针**
（未初始化指针）

```cpp
int* ptr;  // 未初始化，指向随机位置！
*ptr = 10;  // 可能覆盖重要数据或导致程序崩溃

-------------------------------------------------------

正确做法： 始终初始化指针！
int* ptr = nullptr;  // 安全的初始化
// 或
int num = 10;
int* ptr = &num;  // 指向明确的变量
```

2.**悬挂指针**
指针指向已被释放或已失效的内存：

```cpp
int* createAndReturn() {
    int local = 10;
    return &local;  // 危险！函数结束后local不再存在
}

int main() {
    int* ptr = createAndReturn();
    cout << *ptr << endl;  // 不确定的行为，可能崩溃
    return 0;
}
```

3.**内存泄漏**
使用`new`分配的内存必须用`delete`释放：

```cpp
// 正确的内存管理
int* ptr = new int;  // 分配内存
*ptr = 10;
// 使用ptr...
delete ptr;  // 释放内存
ptr = nullptr;  // 避免悬挂指针

// 内存泄漏
int* leakPtr = new int;
leakPtr = new int;  // 第一次分配的内存无法访问，造成泄漏
```

---
## B部分：函数
想象一下，如果你要在程序中多次计算两个数的和，不用函数你可能需要这样：

```c++
// 第一次计算 5+3
int result1 = 5 + 3;
cout << result1 << endl;

// 第二次计算 10+20
int result2 = 10 + 20;
cout << result2 << endl;

// 第三次计算 7+8
int result3 = 7 + 8;
cout << result3 << endl;

// ...可能还有更多次计算
```

如果使用函数，代码会变成这样：

```c++
// 定义一个计算两数之和的函数
int add(int a, int b) {
    return a + b;
}

// 使用这个函数多次
cout << add(5, 3) << endl;
cout << add(10, 20) << endl;
cout << add(7, 8) << endl;
```

>看出区别了吗？使用函数让代码更简洁，而且如果计算方式需要修改（比如改为乘法），只需要修改函数定义处的一行代码，而不是到处寻找并修改。

* 函数就像是手机里的应用： 比如计算器 App，你只需要知道如何使用它（输入两个数字），它就能给你结果（计算结果），而不需要知道它内部是如何工作的。

### 编程世界的"小模块"
**函数的英文是 function，这个词在这里应该被翻译为`功能`，但是由于各种历史遗留问题，大家都采用了更有逼格的数学翻译**`函数`.
实际上`功能`这个翻译似乎更能反映函数的作用: 实现一个功能。

>函数可以将复杂问题分解成小模块，就像把大象装进冰箱分三步走：

* 1.打开冰箱门
* 2.把大象放进去
* 3.关上冰箱门

>每一步都可以是一个函数，让程序清晰易读，便于多人协作。

## 函数的基础
### 函数的定义与声明
>函数就像一个"食谱"，需要有：

* 食谱名（函数名）
* 需要的食材（参数）
* 制作步骤（函数体）
* 最终成品（返回值）
  
### 函数定义的基本结构

```c++
返回值类型 函数名(参数类型1 参数名1, 参数类型2 参数名2, ...) {
    // 函数体（一系列语句）
    return 返回值; // 可选，如果函数返回值类型不是void
}

// 例如
int add(int a, int b) {
    return a + b;
}
```

### 函数的调用与参数传递
**函数调用基础**
调用函数时，需要写出函数名和传递的参数，格式很简单：

```cpp
函数名(参数1, 参数2, ...)
```

```cpp
例如：
int result = add(5, 3);  // 调用add函数，传递参数5和3
```

**参数与实参**的区别

* 参数(Parameter): 函数定义时使用的变量名，相当于"占位符"
* 实参(Argument): 函数调用时传递的具体值

>例如在 int add(int a, int b)中，a和b是参数；而在add(5, 3)中，5和3是实参。

**参数传递方式**
这里是新手最容易混淆的概念，也是面试中经常考察的点。

C++ 有三种传递方式，影响"食材"（参数）是否会被函数修改：

| 传递方式   | 语法           | 效果                               | 示例                                |
| ---------- | -------------- | ---------------------------------- | ----------------------------------- |
| 按值传递   | `func(int a)`  | 函数内修改不影响原变量（复印件）   | `void increase(int x) { x++; }`     |
| 按指针传递 | `func(int* a)` | 函数内可通过解引用修改原变量       | `void increase(int* x) { (*x)++; }` |
| 按引用传递 | `func(int& a)` | 函数内修改会影响原变量（直接操作） | `void increase(int& x) { x++; }`    |

**补充说明**

* 按值传递：相当于给原变量做了一份 “副本”，函数里改的是副本，原变量不受影响。
* 按指针传递：把变量的地址传进去，通过 *x 解引用就能直接修改原变量。
* 按引用传递：本质和指针一样，但语法更简洁，直接用 x 就能操作原变量，是 C++ 更推荐的写法。

```cpp
示例：

#include <iostream>
using namespace std;

void byValue(int x) {
    x = x + 10;  // 只修改复印件
    cout << "函数内 x = " << x << endl;
}

void byPointer(int* x) {
    *x = *x + 10;  // 通过地址修改原值
    cout << "函数内 *x = " << *x << endl;
}

void byReference(int& x) {
    x = x + 10;  // 直接修改原值
    cout << "函数内 x = " << x << endl;
}

int main() {
    int a = 5;

    cout << "原始值 a = " << a << endl;

    byValue(a);
    cout << "按值传递后 a = " << a << endl;  // a 不变

    byPointer(&a);  // 传递a的地址
    cout << "按指针传递后 a = " << a << endl;  // a 变了

    byReference(a);
    cout << "按引用传递后 a = " << a << endl;  // a 变了

    return 0;
}
```

**参数传递的统一理解**： 所有语言中，传递的都是"值"，区别在于传递的是"数据的值"还是"引用/地址的值"。理解这一点对笔面试题至关重要！

### 函数的返回值
>函数可以（也可以不）给调用者返回一个结果：

返回值的基本用法:

```cpp
int multiply(int a, int b) {
    return a * b;  // 返回两数乘积
}

void printHello() {
    cout << "Hello!" << endl;
    // 无需return语句（也可以写return;）
}
```

>返回值的注意事项:

* C++/Java: 返回值类型必须与函数声明中的类型匹配
* 如型果函数声明了返回类型（非 void/None），必须有return语句
* 可以返回多种类的数据：基本类型、数组、对象等
* Python 可通过元组返回多个值：return a, b, c
* Java 和 C++ 可使用数组、对象或特殊的容器类返回多个值

### 函数的作用域与生命周期
**作用域基础**
作用域决定了变量在哪些区域可见、可用：

>1.局部变量:

* 在函数内部定义的变量
* 只在定义它的函数内部可见
* 函数执行结束后变量消失

>2.全局变量:

- 在所有函数外部定义的变量
- 程序中大部分地方都可访问（有一些限制）
- 程序运行期间一直存在

```cpp
示例：

#include <iostream>
using namespace std;

int globalVar = 10;  // 全局变量

void testScope() {
    int localVar = 20;  // 局部变量
    cout << "在函数内部：" << endl;
    cout << "全局变量值: " << globalVar << endl;
    cout << "局部变量值: " << localVar << endl;

    globalVar = 15;  // 修改全局变量
}

int main() {
    cout << "函数调用前：" << endl;
    cout << "全局变量值: " << globalVar << endl;
    // cout << localVar << endl;  // 报错！局部变量在这里不可见

    testScope();

    cout << "函数调用后：" << endl;
    cout << "全局变量值: " << globalVar << endl;  // 变为15
    // cout << localVar << endl;  // 报错！局部变量在这里不可见

    return 0;
}
```

**变量生命周期**
>生命周期是指变量从创建到销毁的整个过程：

| 变量类型          | 生命周期                                   |
| ----------------- | ------------------------------------------ |
| 局部变量          | 从定义处开始，到包含它的代码块结束         |
| 全局变量          | 从程序开始到程序结束                       |
| 静态局部变量(C++) | 从第一次执行到该变量的代码开始，到程序结束 |

C++静态局部变量例子：

```cpp
void counter() {
    static int count = 0;  // 静态局部变量，只初始化一次
    count++;
    cout << "函数被调用了 " << count << " 次" << endl;
}

int main() {
    counter();  // 输出：函数被调用了 1 次
    counter();  // 输出：函数被调用了 2 次
    counter();  // 输出：函数被调用了 3 次
    return 0;
}
```


****变量作用域的常见问题****

* 1.**变量屏蔽**：

```cpp
int x = 10;  // 全局变量

void demo() {
    int x = 20;  // 局部变量，屏蔽了全局变量
    cout << x << endl;  // 输出20（局部变量）

    // 在C++中，可以使用::运算符访问被屏蔽的全局变量
    cout << ::x << endl;  // 输出10（全局变量）
}
```

* 2.**修改全局变量**：


>在 Python 中需要使用global关键字：

```python
total = 0  # 全局变量

def add_to_total(value):
    global total  # 声明要使用全局变量
    total += value  # 修改全局变量

add_to_total(5)
print(total)  # 输出: 5
```

>在 C++/Java 中直接使用即可（但 Java 中通常不推荐使用全局变量）。

---

## 搞定函数式交互题（核心代码题）

* 什么是"核心代码模式"？
****在笔试或在线编程平台，常见的一种考试模式是给你一个或多个函数的框架，你只需填写核心逻辑：****

```cpp
// 题目提供的函数框架
class Solution {
public:
    /**
     *
     * 实现求两个参数的和
     * @param Integer1 int整型
     * @param Integer2 int整型
     * @return int整型
     */
    int addTwoInteger(int Integer1, int Integer2) {
        // 在这里填写代码
    }
};
```

>通用解题步骤（"四步法"）
这里以 例题：A+B（函数） 为例。

* **步骤 1：读懂题意，明确目标**

    >认真阅读题目描述，理解：
      * 这个函数要实现什么功能？
      * 输入是什么？（参数类型、取值范围）
      * 输出是什么？（返回类型、格式要求）

* **步骤 2：分析接口，理解参数与返回值**
仔细研究函数接口：

```c++
class Solution {
public:
    /**
     *
     * 实现求两个参数的和
     * @param Integer1 int整型
     * @param Integer2 int整型
     * @return int整型
     */
    int addTwoInteger(int Integer1, int Integer2) {
        // 在这里填写代码
    }
};
````

不难分析出：
>函数名为`addTwoInteger`
    第一个参数是整数一
    第二个参数是整数二
    函数需要返回的是一个整数

* **步骤 3：设计算法，构思逻辑**
先用自然语言或伪代码思考解决方案，为之后代码实现作准备

* **步骤 4：编写代码，实现函数**
在提供的框架内填写代码：

```cpp
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 实现求两个参数的和
     * @param Integer1 int整型
     * @param Integer2 int整型
     * @return int整型
     */
    int addTwoInteger(int Integer1, int Integer2) {
        return Integer1 + Integer2;
    }
};

这样我们就完美的解决了函数交互题啦。
------------------------------------------------------------------------
补充：`调试技巧`

在做核心代码题时，你通常没有机会运行完整的程序。以下是一些有用的调试技巧：

* 边界检查： 特别注意函数开头处理特殊情况

* 手动模拟： 用纸笔跟踪简单测试用例的执行过程

* 打印调试： 某些平台允许在代码中添加打印语句

def find_max(nums):
    print(f"输入: {nums}")  # 调试信息
    # 实现...
