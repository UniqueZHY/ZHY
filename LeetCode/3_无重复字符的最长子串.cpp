/*************************************************************************
	> File Name: 3_无重复字符的最长子串.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月17日 星期日 00时25分32秒
 ************************************************************************/
/*class Solution {
public:

    bool check(string &s, int l) {
        int cnt = 0;//当期那滑动窗口中不同种类的数量
        int arr[256] = {0};//相关字符出现的次数
        for (int i = 0; s[i]; i++) {
            arr[s[i]] += 1;
            if (arr[s[i]] == 1) cnt += 1;//arr[[i]]=1说明第一次出现
            if (i >= l) {
                arr[s[i - l]] -= 1;//从滑动窗口中出去一个字符
                if (arr[s[i - l]] == 0) cnt -= 1;//少了一种字符
            }
            if (cnt == l) return 1;
        }
        return 0;
    }

    int bs(string &s, int l, int r) {
        if (l == r) return l;
        int mid = (l + r + 1) >> 1;//二分方法枚举长度
        if (check(s, mid)) return bs(s, mid, r);
        return bs(s, l, mid - 1);
    }

    int lengthOfLongestSubstring(string s) {
        if (s == "") return 0;
        return bs(s, 1, s.size());
    }
};*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ind[256] = {0};//每一种字符最后出现的位置
        int l = 0, ans = 0;//l表示以当前字符为结尾向前找到最长不重复字符的个数
        for (int i = 0; s[i]; i++) {
            l += 1;
            l = min(l, (i + 1) - ind[s[i]]);//可能s[i]上次出现的位置在l到s[i]之间,随意取最小值更新l
            ind[s[i]] = i + 1;//更新位置
            ans = max(ans, l);//最长的l
        }
        return ans;
    }
};
