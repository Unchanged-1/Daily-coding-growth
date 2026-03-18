/*
 * 题目：最大的差
 * 来源：牛客网（noob34）
 * 知识类型：C++基础语法 | 数组操作 | 最值求解（单次遍历优化） | 数据范围适配 | 输入输出效率
 * 题目原文：
 *   描述：给定n个整数（2≦n≦10⁵），选出两个数使差值最大，输出该最大差（本质=最大值-最小值）。
 *   输入描述：
 *     第一行输入整数n；
 *     第二行输入n个整数（-10⁵≦a_i≦10⁵），空格隔开。
 *   输出描述：输出最大差值（整数）。
 *   示例1：输入3、1 2 1 → 输出1；示例2：输入5、5 3 8 1 4 → 输出7。
 *   难度：入门，通过率47.53%，时间限制1秒，空间限制256M。
 * 核心要求：
 *   1. 高效求解最大值和最小值（n≤10⁵，需O(n)时间复杂度）；
 *   2. 计算并输出最大值-最小值。
 * 解题思路（单次遍历法，最优解）：
 *   1. 初始化数组第一个元素为初始最值；
 *   2. 遍历剩余元素，同步更新最大值和最小值；
 *   3. 输出最大值-最小值。
 */
#include <bits/stdc++.h>
using namespace std;
int a[100005]; // 数组大小适配n≤10⁵的要求
int main()
{
    int n;
    cin >> n;
    cin >> a[0];
    int min_val = a[0], max_val = a[0]; // 初始化最值为第一个元素
    // 遍历剩余n-1个元素，同步更新最值
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        if (min_val > a[i])
            min_val = a[i]; // 更新最小值
        if (max_val < a[i])
            max_val = a[i]; // 更新最大值
    }
    cout << max_val - min_val << endl; // 最大差=最大值-最小值
    return 0;
}

/* 可选优化写法（省数组空间，无需存储所有元素）：
#include<bits/stdc++.h>
using namespace std;
int main() {
   int n, num;
   cin>>n;
   cin>>num;
   int min_val = num, max_val = num;
   // 无需数组，读一个数处理一个数，节省10⁵大小的数组空间
   for(int i=1;i<n;i++){
    cin>>num;
    if(min_val > num) min_val = num;
    if(max_val < num) max_val = num;
   }
   cout<<max_val - min_val<<endl;
   return 0;
}

// 进阶优化（输入量大时提升效率，竞赛常用）：
// #include<bits/stdc++.h>
// using namespace std;
// int main() {
//    ios::sync_with_stdio(false); // 关闭同步，加速cin/cout
//    cin.tie(0);
//    int n, num;
//    cin>>n;
//    cin>>num;
//    int min_val = num, max_val = num;
//    for(int i=1;i<n;i++){
//     cin>>num;
//     min_val = min(min_val, num); // 用库函数简化最值更新
//     max_val = max(max_val, num);
//    }
//    cout<<max_val - min_val<<endl;
//    return 0;
// }
*/

/*
======= 核心重点 & 易错点 =======
【重点】
1. 核心逻辑（通过率低的关键认知）：
   - 最大差值 = 数组最大值 - 数组最小值（无需枚举所有数对，O(n)优于O(n²)）；
2. 效率优化：
   - 单次遍历：读元素时同步更新最值，仅遍历1次数组，时间复杂度O(n)（适配n=10⁵）；
   - 空间优化：无需存储所有元素，读一个处理一个，节省数组空间；
3. 数据范围：
   - 数组大小设为100005（适配n≤10⁵）；
   - a_i∈[-10⁵,10⁵]，max-min∈[0,2×10⁵]，int完全覆盖；
4. 初始化：必须用第一个元素初始化最值（不能初始化为0，否则负数数组会出错）。

【易错点】
1. 逻辑错误：
   - 枚举所有数对计算差值（双重循环O(n²)，n=10⁵时超时）；
   - 最值初始化错误（如int min=0;，数组全为负数时最小值判断错误）；
2. 空间/效率问题：
   - 数组开太小（如int a[1000];，n>1000时数组越界崩溃）；
   - 未关闭同步（n=10⁵时cin/cout慢，导致超时）；
3. 语法错误：
   - 变量名用min/max（和std::min/std::max库函数冲突，建议用min_val/max_val）；
   - 循环条件写错（i<=n，多遍历1次，读入多余数据导致结果错误）。
*/