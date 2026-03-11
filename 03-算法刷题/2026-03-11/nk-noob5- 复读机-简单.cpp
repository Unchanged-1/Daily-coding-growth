#include <bits/stdc++.h>
using namespace std;
int main () {
    int a;
    long long b;
    double c;
    char d;
    string e;

    cin >> a >> b >> c >> d >> e;
    cout << a << endl << b << endl << fixed << setprecision(
             1) << c << endl << d << endl << e << endl;
    return 0;
}
/*
cout << defaultfloat;
//清空以前对小数输出格式的设置
cout << fixed << setprecision(n) << 待输出变量名;

1.defaultfloat 不是必写的，核心作用是把浮点数输出格式重置为默认状态（自动选小数 / 科学计数法，控制有效数字）；
2.仅当你需要在 fixed/scientific 格式后，切换回默认格式输出浮点数时，才需要写；
3.如果全程只用 fixed + setprecision 输出浮点数（比如你之前的代码），完全不用写 defaultfloat。
*/

/*C：

#include <stdio.h>
int main (){
    int a;
    long long b;
    double c;
    char d;
    char e[1000];

    scanf("%d %lld %lf %c %s",&a,&b,&c,&d,e);
    printf("%d\n%lld\n%.1f\n%c\n%s\n",a,b,c,d,e); ;
    return 0;
}


*/