/*************************************************************************
	> File Name: 202_快乐数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时20分09秒
 ************************************************************************/
int solve(int n) {
    int sum = 0;
    while (n) {
        sum += (n % 10) * (n % 10);
        n /= 10;
    }
    return sum;
}

bool isHappy(int n){
    int a = n, b = n;
    while (b != 1) {
        a = solve(a);
        b = solve(solve(b));
        if (a == b) break;
    }
    return (b == 1);
}
