class Solution {
public:
    int reverse(int x) {
        int flag = 0;
        if (x < 0) flag = 1; 
        long long a = x, ans = 0;
        while (x != 0) {
            ans *= 10;
            a = x % 10;
            x /= 10;
            ans += a;
        }
        if (flag == 1) {
            ans -= 0;
        }
        if (ans >= INT_MAX || ans <= INT_MIN) //C中常量INT_MAX和INT_MIN分别表示最大、最小整数，定义在头文件limits.h中。
            ans = 0;
        return ans;
    }
};
