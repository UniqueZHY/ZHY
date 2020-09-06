/*************************************************************************
	> File Name: 264_丑数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 23时10分16秒
 ************************************************************************/
class Solution {
public:
//丑数为质因数只为235的数所以可以235每个分别成235，一直乘下去，构造丑数，分别插入到集合中.set 会自己去重
//高效做法，例2*3也3*2，所以当最小质因子为3时就乘上3,5,最小质因子为5时就只乘以5
    set<long long> s;
    int nthUglyNumber(int n) {
        s.clear();
        s.insert(1);
        for (int i = 1; i < n; i++) {
            long long val = *s.begin();
            s.erase(s.begin());
            s.insert(val * 2);
            s.insert(val * 3);
            s.insert(val * 5);
        }
        return *s.begin();
    }
};
