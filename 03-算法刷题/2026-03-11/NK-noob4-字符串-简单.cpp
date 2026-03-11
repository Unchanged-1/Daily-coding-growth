#include <bits/stdc++.h>
using namespace std;
int main () {
    string s;
    cin >> s;
    cout << s;
    return  0;
}


/*C语言：
#include <stdio.h>
int main (){
    char a[10004];
    scanf("%s",a);   或者根据题目最大数scanf("%10000s",a)
    printf("%s",a);
    return 0;
}
*/

/*   %10000s是 C 语言中读取字符串的一种安全写法，核心作用是「读取用户输入的字符串并存入 字符数组 s，同时限制最多读取 10000 个字符
*/