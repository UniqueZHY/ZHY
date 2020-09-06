/*************************************************************************
	> File Name: 349_两个数组的交集.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月19日 星期二 13时26分32秒
 ************************************************************************/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> h;
        vector<int> ret;
        for (int i = 0; i < nums1.size(); i++) {
            h[nums1[i]] = 1;//降低一个数组都添加2进哈希表中
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (h.find(nums2[i]) == h.end()) continue;//num2[i]不存在,以为着不是交集中的
            if (h[nums2[i]] == 0) continue;//num2[i]存在,是交集,但是结果数组中已经添加过了
            ret.push_back(nums2[i]);
            h[nums2[i]] = 0;
        }
        return ret;
    }
};
