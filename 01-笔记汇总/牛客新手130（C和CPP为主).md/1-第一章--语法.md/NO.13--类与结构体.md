# 类与结构体

* 引言：为啥要有结构体/类？

>想象一下，学校让你统计期末考试成绩（可以点开对应链接获取题面）。每个同学都有好几项信息：姓名、语文分、数学分、英语分。

如果让你处理 3 个同学的信息，你可能会写出类似这样的代码（伪代码）：

```cpp
// 同学1
string name1 = "shy";
int chinese1 = 114;
int math1 = 51;
int english1 = 4;

// 同学2
string name2 = "re0hg";
int chinese2 = 114;
int math2 = 10;
int english2 = 23;

// 同学3
string name3 = "hgcode";
int chinese3 = 51;
int math3 = 42;
int english3 = 60;
```

才 3 个同学就有点乱了，对吧？如果 N=100 个同学呢？变量名得起飞了！而且，name1 和 chinese1、math1、english1 明显是属于同一个同学的，它们应该“待在一起”。

💡 **结构体**（C++ 里常用 struct）和**类**（C++、Java、Python 里都用 class）就是为了解决这个问题而生的！它们就像一个自定义的“数据收纳盒”，**可以把描述同一个事物（比如一个学生）的所有相关信息（姓名、各科成绩）打包在一起**。这样，我们就可以把一个学生当作一个整体来处理，代码会清晰、有条理得多。

接下来，我们就来看看他们具体该如何使用。

## 结构体/类的声明与使用 (基础篇)

* 目标： 定义一个“学生”数据类型，并创建具体的学生对象。

****C++ (struct/class)****
**在 C++中我们用 `struct` 关键字定义一个结构体类型，用`class`关键字来定义一个类。大括号 {} 内部是它的成员变量（它包含哪些信息）。别忘了结尾的分号 ;（千万不要忘记）**。

```cpp
#include <string>

// 定义 Student 结构体
struct Student {
    std::string name; // 姓名
    int chinese;      // 语文
    int math;         // 数学
    int english;      // 英语
}; // <-- 注意分号

class Student{

public:
    std::string name; // 姓名
    int chinese;      // 语文
    int math;         // 数学
    int english;      // 英语
}
这样我们就定义号了我们的学生结构体了，定义好类型后，就可以像使用 int, double 一样，创建该类型的变量（我们称之为“对象”或“实例”）。

// 在 main 函数或其他地方创建 Student 对象
Student s1; // 创建了一个名为 s1 的学生对象
Student s2; // 可以创建多个，这样就解决了我们遇到的代码冗余的问题

对于结构体和类我们使用点运算符 . 来访问或修改对象的成员变量（前提是成员变量和函数是public的）。

// 给 s1 对象的成员赋值
s1.name = "senpai";
s1.chinese = 114;
s1.math = 51;
s1.english = 4;

// 访问 s1 对象的信息并打印
#include <iostream>
std::cout << "姓名: " << s1.name << std::endl;
std::cout << "语文: " << s1.chinese << std::endl;
此外，对于结构体/类的指针，我们还可以通过->来访问或修改对象的成员变量

Student * s = new Student();
// 给 s 对象的成员赋值
s->name = "senpai";
s->chinese = 114;
s->math = 51;
s->english = 4;

// 访问 s 对象的信息并打印
#include <iostream>
std::cout << "姓名: " << s->name << std::endl;
std::cout << "语文: " << s->chinese << std::endl;
```

>温馨小提示：C++ 的 struct 默认成员是 public（公开的），可以直接访问。class 默认是 private（私有的），需要特殊方式访问，初学算法用 `struct` 或 `public class` 更方便。

---
## 构造函数：创建对象时的初始化工作

* 在每次创建学生对象时，我们如果都要手动设置姓名、成绩，那也是很麻烦的。能不能在创建对象的那一刻，就直接把这些信息传进去呢？
  **接下来为大家介绍的构造函数就是干这个的！**

>在 c++中构造函数是一个特殊的成员函数，它的名字和结构体/类名完全相同，并且没有返回值类型（连 void 都不写）。

```cpp
  struct Student {
      std::string name;
      int chinese, math, english, total_score;

      // 构造函数，接收初始值
      Student(std::string n, int c, int m, int e) {
          name = n;
          chinese = c;
          math = m;
          english = e;
          total_score = c + m + e;
      }
  };
```

此外，我更推荐使用“初始化列表”的方式来初始化成员，写在函数名和 {} 之间，用冒号 : 开始，这对于 const 成员或引用成员是必须的。

```cpp
  struct Student {
      // ... 成员变量同上 ...

      // 使用初始化列表的构造函数
      Student(std::string n, int c, int m, int e) : name(n), chinese(c), math(m), english(e) {
          total_score = chinese + math + english; // 可以在函数体内做其他事
      }
  };
```

当我们使用带参数的构造函数创建对象时，需要在类型名后的括号里传入对应的参数。

```cpp
// 使用构造函数创建并初始化 s1
 Student s1("senpai", 114, 51, 4);

 std::cout << s1.name << " 的总分是: " << s1.total_score << std::endl;
```

**有了构造函数，我们在创建和初始化对象是不是一步到位，清爽多了**？

---

## 让对象学会“比较”：运算符重载 / 接口实现
>现在我们有了学生对象，但怎么比较两个学生谁更“厉害”呢？比如，我们要按总分给学生排序，或者找出总分最高的学生。程序需要知道如何判断 studentA 是不是比 studentB “更好”（或“更大”、“更小”），在我们的题目中是总分高的更厉害。

```cpp
C++ 允许我们重载（重新定义）标准运算符（如 <, >, == 等）的行为，让它们能用于我们自定义的 Student 类型。
- 这对于使用标准库的排序 (std::sort) 或优先队列 (std::priority_queue) 非常方便。
```

* `bool operator<(const Student& other) const { ... }`是重载 < 的标准形式。我们需要在函数体内部实现你的比较逻辑。返回 `true` 表示当前对象 (this) 小于 other 对象。
  
```cpp  
struct Student {
      // ... (成员变量和构造函数同上) ...
      
      int getTotalScore() const { return total_score; } // 获取总分的方法

      // 重载小于号 (<) 运算符
      // const Student& other: 传入另一个对象的常量引用，高效且安全
      // 末尾的 const: 表示这个函数不修改当前对象的状态
      bool operator<(const Student& other) const {
          // 定义比较规则：按总分比较。总分低的算“小于”
          return this->getTotalScore() < other.getTotalScore();
          
          // 如果总分相同，可以加次要比较条件，例如按姓名
          // if (this->getTotalScore() != other.getTotalScore()) {
          //     return this->getTotalScore() < other.getTotalScore();
          // }
          // return this->name < other.name; // 总分相同比姓名
      }
  };
```

```cpp
-定义了operator<后，就可以直接用<比较两个Student对象
-或者将它们用于需要比较大小的标准库函数（如 std::sort, std::priority_queue）。
- ps：std::sort 默认使用 operator< 来排序。
```

```cpp
    Student s1("senpai", 114, 51, 4);  // 169
    Student s2("lxl", 114, 10, 23);     // 147

    if (s2 < s1) { // 这里就会调用我们定义的 operator<
        std::cout << s2.name << " 的总分低于 " << s1.name << std::endl;
    } 
```
