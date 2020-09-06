/*************************************************************************
	> File Name: 1_两数之和.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 23时33分29秒
 ************************************************************************/
//第一种方法
/*
class Solution {
public:
    unordered_map<int, int> h;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for (int i = 0; i < nums.size(); i++) {
            if (h.find(target - nums[i]) == h.end()) {//例target为15 num[i]为当前待处理元素11，所以要在前面找4，如果等于end索命没找到4
                h[nums[i]] = i;//就直接将哈希表的第11为存i表示11在数组中的下标
                continue;
            }
            ret.push_back(h[target - nums[i]]);//说明找到了，就直接存到结果数组中就行
            ret.push_back(i);
            break;
        }
        return ret;
    }
};*/
//第二种方法
/*class Solution {
public:

    typedef pair<int, int> PII;
    unordered_map<int, int> h;
    int bs(vector<PII>& nums, int l, int r, int x) {
        int mid = 0;
        while (l <= r) {
            mid = (l + r) >> 1;
            if (nums[mid].first == x) return mid;
            if (nums[mid].first > x) r = mid - 1;
            else l = mid + 1;
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(PII(nums[i], i));//arr数组用来存放数组的值和下标
        }
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            int ind = bs(arr, i + 1, arr.size() - 1, target - arr[i].first);//用二分查找从arr[i]到数组结尾查找target-arr[i]的值是否存在
            if (ind == -1) continue;
            int ind1 = arr[i].second, ind2 = arr[ind].second;
            if (ind1 > ind2) swap(ind1, ind2);
            ret.push_back(ind1);
            ret.push_back(ind2);
        }
        return ret;
    }
};*/
//第三种方法
class Solution {
public:

    typedef pair<int, int> PII;
    unordered_map<int, int> h;
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        vector<PII> arr;
        for (int i = 0; i < nums.size(); i++) {
            arr.push_back(PII(nums[i], i));
        }
        sort(arr.begin(), arr.end());
        int p = 0, q = arr.size() - 1;
        do {//用两个指针分别指向数组的头尾
            int temp = arr[p].first + arr[q].first;//temp为两个指针相加
            if (temp == target) break;//等于target就是找到了
            if (temp < target) p += 1;//前面指针后走一步，相当于让temp大一点
            else  q -= 1;//后面指针前走一步，相当于让temp小一点
        } while(1);
        int ind1 = arr[p].second, ind2 = arr[q].second;
        if (ind1 > ind2) swap(ind1, ind2);
        ret.push_back(ind1);
        ret.push_back(ind2);
        return ret;
    }
};
