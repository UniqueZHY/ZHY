/*************************************************************************
	> File Name: 326_3的幂.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月29日 星期六 16时15分44秒
 ************************************************************************/
bool isPowerOfThree(int n){
    while (n) {
        if (n % 3 == 0) {
            n /= 3;
        } else {
            break;
        }
    }
    if (n == 1) return true;
    else return false;
}
