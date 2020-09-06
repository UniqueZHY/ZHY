/*************************************************************************
	> File Name: 2.cpp
	> Author: 
	> Mail: 
	> Created Time: 2019年12月12日 星期四 18时30分42秒
 ***********************************************************************/
 #include<stdio.h>
 #define MAX(a, b)({\
     __typeof(a) __a = (a);\
     __typeof(b) __b = (b);\
     __a > __b ? __a : __b;\
 }) 
 #define P(func) {\
    printf("%s = %d\n", #func, func);\
}

 int main() {
    int a = 7;
    P(MAX(2 ,3));
    P(5 + MAX(2 ,3));    
    P(MAX(2, MAX(3 ,4)));
    P(MAX(2 ,3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
     return 0;
 }
 /*#define MAX(a, b) (a > b ? a : b)
 int main() {
     int a = 7, b, ans;
     //cin >> a >> b;
     ans = MAX(2, 3);
     printf("%d\n", ans);
     ans = 5 + MAX(2, 3);
     printf("%d\n", ans);
     ans = MAX(2, MAX(3, 4));
     printf("%d\n", ans);
     ans = MAX(2, (3 > 4 ? 3 : 4));
     printf("%d\n", ans);   
     ans = MAX(a++, 6);
    printf("%d %d\n", a, ans);
 }
*/
