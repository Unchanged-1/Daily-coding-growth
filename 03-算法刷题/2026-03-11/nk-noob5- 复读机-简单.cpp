/*
 * 题目：复读机
 * 来源：牛客网（noob5）
 * 题目原文：
 *   描述：无论输入什么，输出对应内容（每行换行）；浮点数需保留1位小数输出。
 *   输入描述：共5行，依次为：
 *     1. 整数a（-10⁹ ≤a≤10⁹）；
 *     2. 整数b（-10¹⁸ ≤b≤10¹⁸）；
 *     3. 浮点数c（-10⁹ ≤c≤10⁹）；
 *     4. 小写字母d；
 *     5. 无空格/换行的字符串e。
 *   输出描述：输出5行，对应输入内容；浮点数c保留1位小数。
 *   示例1：输入114、1145141919810、3.1415926、k、WangZai666! → 输出对应内容，其中3.1415926输出3.1。
 *   难度：入门，通过率31.63%，时间限制1秒，空间限制256M。
 * 核心要求：
 *   1. 按类型正确接收5类输入（注意b的范围需用long long）；
 *   2. 浮点数c强制保留1位小数输出；
 *   3. 每行输出对应输入内容，换行分隔。
 * 解题思路：
 *   1. 类型匹配：a(int)、b(long long)、c(double)、d(char)、e(string)；
 *   2. 输入：用cin依次读取5个数据；
 *   3. 输出：cout按行输出，浮点数用fixed+setprecision(1)保留1位小数。
 */
#include <bits/stdc++.h>
using namespace std;
int main () {
    int a;
    long long b;
    double c;
    char d;
    string e;

    cin >> a >> b >> c >> d >> e;
    cout << a << endl << b << endl << fixed << setprecision(1) << c << endl << d << endl << e << endl;
    return 0;
}

/*
======= 核心重点 & 易错点 =======
【重点】
1. 数据类型：b的范围是10¹⁸，必须用long long（int仅覆盖±2×10⁹）；
2. 浮点数输出：fixed+setprecision(1) 强制保留1位小数（核心要求）；
3. 输入输出：cin/cout可直接处理多类型数据，换行用endl分隔。

【易错点】
1. 类型错误：b用int定义（导致数值溢出，输出错误）；
2. 浮点数格式：漏写fixed（仅setprecision(1)会控制有效数字，而非小数位数）；
3. 输入读取：用cin读取char时，未跳过换行符（本题无空格，cin自动跳过，无需额外处理）；
4. 字符串存储：用char数组时未预留足够长度（string类型更安全）。



/*补充：
cout << defaultfloat;
//清空以前对小数输出格式的设置
cout << fixed << setprecision(n) << 待输出变量名;

1.defaultfloat 不是必写的，核心作用是把浮点数输出格式重置为默认状态（自动选小数 / 科学计数法，控制有效数字）；
2.仅当你需要在 fixed/scientific 格式后，切换回默认格式输出浮点数时，才需要写；
3.如果全程只用 fixed + setprecision 输出浮点数（比如你之前的代码），完全不用写 defaultfloat。
*/

