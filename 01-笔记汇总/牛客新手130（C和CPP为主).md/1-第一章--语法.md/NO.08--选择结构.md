# 选择结构
## 一.基本概念
>选择结构是程序中的条件判断语句，根据条件的真假选择不同的执行路径，有点类似于电路图中的开关，可以根据不同的条件执行不同的代码，进而帮助我们让代码在不同情况下进行不同的功能。

比如说，如果我要写一个自动抢课脚本，这个脚本的大致思路就可以描述为，不断地判断需要抢的课是否已经开放抢课，然后：

• 如果这节课已经开放抢课，就执行抢课的操作；
• 如果这节课还没有开放抢课，就等待一段时间，然后再次判断是否开放抢课。

在这个例子中，我们通过判断条件“需要抢的课已经开放抢课”这个命题的真假来决定接下来要执行的操作，这就是一种典型的选择结构。

### C++ 中提供了三种选择结构，分别是：
>• if 分支语句系列
>• switch 分支语句
>• 三目运算符

但是，switch 和三目运算符的功能其实都可以用 if 分支语句来实现，所以我们只介绍 if 分支语句。感兴趣的话，您可以自行了解 switch 和三目运算符的用法。
C++ 简单 if 分支语句
>1.在C++中，if 分支语句的语法如下：
if (条件) {
    // 如果条件为真，执行这里的代码
}

```cpp
例如：
int a = 10;
if (a > 5) {
    cout << "a 大于 5" << endl;
}

在这个例子中，我们定义了一个变量 a，然后使用 if 分支语句判断 a 是否大于 5。如果 a 大于 5，就会输出 a is greater than 5。
C++ if-else 分支语句
```

>2.在C++中，if-else 分支语句的语法如下：
if (条件) {
    // 如果条件为真，执行这里的代码
} else {
    // 如果条件为假，执行这里的代码
}

```cpp
例如：
int a = 10;
if (a > 5) {
    cout << "a 大于 5" << endl;
} else {
    cout << "a 小于等于 5" << endl;
}

在这个例子中，我们定义了一个变量 a，然后使用 if-else 分支语句判断 a 是否大于 5。如果 a 大于 5，就会输出 a 大于 5；否则，就会输出 a 小于等于 5。
C++ if-else if-else 分支语句
```

>3.在C++中，if - else if  - else 分支语句的语法如下：
if (条件1) {
    // 如果条件1为真，执行这里的代码
} else if (条件2) {
    // 如果条件1为假，条件2为真，执行这里的代码
} else {
    // 如果条件1和条件2都为假，执行这里的代码
}

```cpp
例如：
int a = 10;
if (a > 5) {
    cout << "a 大于 5" << endl;
} else if(a==5){
    cout << "a 等于 5" << endl;
}else{
    cout << "a 小于 5" << endl;
}

在这个例子中，我们定义了一个变量 a，然后使用 if-else if-else 分支语句判断 a 是否大于 5。如果 a 大于 5，就会输出 a 大于 5；否则，如果 a 等于 5，就会输出 a 等于 5；如果前面的条件都不满足，则说明 a 小于 5，此时直接输出 a 小于 5 即可。
此外，else if 这一项其实是可以反复使用多次的，比如：
if (条件1) {
    // 如果条件1为真，执行这里的代码
} else if (条件2) {
    // 如果条件1为假，条件2为真，执行这里的代码
}  else if (条件3) {
    // 如果条件1，2为假，条件3为真，执行这里的代码
}  else if (条件4) {
    // 如果条件1，2，3为假，条件4为真，执行这里的代码
} else {
    // 如果条件1，2，3，4都为假，执行这里的代码
} 
```

## 二.补充：三目运算符+Switch用法
想了解 `switch` 语句和三目运算符（条件运算符）的具体用法，会从基础定义、使用场景、代码示例和核心区别几个方面，帮把这两个知识点讲清楚。

### C++ 中的三目运算符（条件运算符）
C++ 的三目运算符语法和 Java 基本一致，但支持更多数据类型（如指针、自定义类型等），核心仍是处理**简单二选一**逻辑。

#### 1. 基本语法

```cpp
条件表达式 ? 表达式1 : 表达式2;
```

- 逻辑规则：条件为 `true` 执行表达式1，为 `false` 执行表达式2，**有返回值**可直接赋值；
- C++ 特性：表达式1和表达式2的类型需兼容（或可隐式转换），支持嵌套但不推荐复杂嵌套。

#### 2. 代码示例

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    // 示例1：判断数字奇偶
    int num = 8;
    string result = (num % 2 == 0) ? "偶数" : "奇数";
    cout << num << " 是 " << result << endl; // 输出：8 是 偶数

    // 示例2：比较两个数的最大值
    int a = 15, b = 9;
    int max_val = (a > b) ? a : b;
    cout << "最大值：" << max_val << endl; // 输出：最大值：15

    // 示例3：嵌套三目（慎用，可读性差）
    int score = 75;
    string grade = (score >= 90) ? "优秀" : 
                   (score >= 80) ? "良好" : 
                   (score >= 60) ? "及格" : "不及格";
    cout << "成绩等级：" << grade << endl; // 输出：成绩等级：及格

    // 示例4：C++ 特有的用法（指针判断）
    int* ptr = nullptr;
    int val = (ptr != nullptr) ? *ptr : 0; // 避免空指针解引用
    cout << "指针取值：" << val << endl; // 输出：指针取值：0

    return 0;
}
```

### C++ 中的 switch 语句
C++ 的 `switch` 语句核心逻辑和 Java 类似，但有一些语法细节差异（如不支持字符串，C++11 后支持枚举类），适合**多分支等值判断**。

#### 1.基本语法

```cpp
switch (表达式) {
    case 常量表达式1:
        // 执行代码
        break; // 可选，跳出switch
    case 常量表达式2:
        // 执行代码
        break;
    default: // 可选，所有case不匹配时执行
        // 执行代码
        break;
}
```

- 表达式类型：仅支持**整型/枚举类型**（char、short、int、long、枚举，C++ 不支持直接判断字符串）；
- `break`：省略会触发“case 穿透”（可利用穿透实现多 case 共用逻辑）；
- `default`：位置不固定，建议放最后，无匹配 case 时执行。

#### 2.代码示例

```cpp
#include <iostream>
#include <string>
using namespace std;

// 枚举类型示例（C++11 枚举类）
enum class Weekday {
    Monday, Tuesday, Wednesday, Thursday, Friday
};

int main() {
    // 示例1：根据数字判断星期
    int week_num = 2;
    string week_name;
    switch (week_num) {
        case 1:
            week_name = "星期一";
            break;
        case 2:
            week_name = "星期二";
            break;
        case 3:
            week_name = "星期三";
            break;
        default:
            week_name = "无效星期";
            break;
    }
    cout << week_name << endl; // 输出：星期二

    // 示例2：case 穿透（多case共用逻辑）
    int month = 4;
    int days;
    switch (month) {
        case 2:
            days = 28; // 简化示例，未考虑闰年
            break;
        case 4: case 6: case 9: case 11: // 多个case共用逻辑
            days = 30;
            break;
        default:
            days = 31;
            break;
    }
    cout << month << "月有" << days << "天" << endl; // 输出：4月有30天

    // 示例3：枚举类的switch用法（C++11+）
    Weekday day = Weekday::Wednesday;
    switch (day) {
        case Weekday::Monday:
            cout << "周一上班" << endl;
            break;
        case Weekday::Wednesday:
            cout << "周三开会" << endl; // 输出：周三开会
            break;
        default:
            cout << "正常上班" << endl;
            break;
    }

    return 0;
}
```

#### 补充：C++ 处理字符串的“伪 switch”方案
C++ 原生 `switch` 不支持字符串，若需按字符串分支，可结合 `if-else` 或哈希表实现：

```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string cmd = "start";
    if (cmd == "start") {
        cout << "程序启动" << endl;
    } else if (cmd == "stop") {
        cout << "程序停止" << endl;
    } else if (cmd == "restart") {
        cout << "程序重启" << endl;
    } else {
        cout << "未知命令" << endl;
    }
    return 0;
}
```

### C++ 中 switch vs 三目运算符 核心区别

| 特性     | 三目运算符               | switch 语句                 |
| -------- | ------------------------ | --------------------------- |
| 适用场景 | 简单二选一逻辑           | 多分支**整型/枚举**等值判断 |
| 返回值   | 有返回值，可直接赋值     | 无返回值，需手动赋值        |
| 支持类型 | 任意布尔条件，兼容多类型 | 仅整型/枚举（无字符串）     |
| 可读性   | 简单场景优，嵌套则差     | 多分支等值判断更清晰        |

### 总结

1. **C++ 三目运算符**：语法和 Java 一致，支持更多 C++ 特有类型（如指针、枚举），适合简单二选一，避免多层嵌套；
2. **C++ switch 语句**：仅支持整型/枚举，不支持字符串，需注意 `break` 避免穿透，处理字符串分支需用 `if-else`；
3. 选择原则：简单二选一用三目，多分支整型/枚举判断用 switch，字符串/复杂条件判断用 `if-else`。
