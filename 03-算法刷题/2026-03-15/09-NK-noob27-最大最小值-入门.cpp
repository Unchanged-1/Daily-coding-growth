/*
 * 题目：最大最小值
 * 来源：牛客网（noob27）
 * 知识类型：C++基础语法 | 条件判断（多轮比较） | 最值求解（手动比较/库函数） | 输出格式严格匹配 | 数据范围适配
 * 题目原文：
 *   描述：给定三个整数a,b,c（1≦a,b,c≦10⁶），输出它们的最大值和最小值。
 *   输入描述：一行输入三个整数a,b,c，空格隔开。
 *   输出描述：
 *     第一行：The maximum number is : X（X为最大值）；
 *     第二行：The minimum number is : Y（Y为最小值）。
 *   示例1：输入1 2 3 → 输出最大值3、最小值1。
 *   难度：入门，通过率44.10%，时间限制1秒，空间限制256M。
 * 核心要求：
 *   1. 正确求解三个数的最大值和最小值；
 *   2. 输出格式严格匹配题目要求（固定字符串+空格+冒号+空格+数值）。
 * 解题思路（手动比较法，新手友好）：
 *   1. 用int接收a,b,c（10⁶范围，int足够）；
 *   2. 初始化max为a，依次和b、c比较，更新最大值；
 *   3. 初始化min为a，依次和b、c比较，更新最小值；
 *   4. 按固定格式输出最大值和最小值。
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    
    // 求解最大值：先初始化max=a，再依次和b、c比较
    int max=a;
    if(max<b) max=b;
    if(max<c) max=c;

    // 求解最小值：先初始化min=a，再依次和b、c比较
    int min=a;
    if(min>b) min=b;
    if(min>c) min=c;

    // 严格匹配输出格式：固定字符串+空格+冒号+空格+数值
    cout<<"The maximum number is : "<<max<<endl;
    cout<<"The minimum number is : "<<min<<endl;

    return 0;
}

/* 可选优化写法（库函数法，更简洁）：
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int max_val = max({a, b, c});  // C++11及以上支持初始化列表传参
    int min_val = min({a, b, c});
    cout<<"The maximum number is : "<<max_val<<endl;
    cout<<"The minimum number is : "<<min_val<<endl;
    return 0;
}
*/

/*
======= 核心重点 & 易错点 =======
【重点】
1. 最值求解逻辑：
   - 手动比较：初始化最值为第一个数，依次和剩余数比较更新（逻辑直观，新手易理解）；
   - 库函数法：max/min({a,b,c}) 更简洁，竞赛常用（需注意C++版本支持）；
2. 输出格式：必须严格匹配「The maximum number is : X」（冒号前后各1个空格，字符串无拼写错误）；
3. 数据范围：a,b,c≤10⁶ < int最大值（2³¹-1≈2e9），无需long long。

【易错点】
1. 输出格式错误（通过率低的核心原因）：
   - 字符串拼写错误（如max写成maxmum、minimum写成minmum）；
   - 空格/冒号错误（如少空格："The maximum number is: "<<max，或多空格）；
   - 输出顺序错误（先输出最小值再输出最大值）；
2. 初始化错误：max/min未初始化（直接用int max; 会取随机值，结果错误）；
3. 比较逻辑错误：把max<b写成max>b（更新逻辑颠倒，求成最小值）；
4. 变量名冲突：用max/min作为变量名后，无法使用std::max/std::min库函数（建议换max_val/min_val）。
*/