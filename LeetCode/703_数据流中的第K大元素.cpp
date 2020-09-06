/*************************************************************************
	> File Name: 703_数据流中的第K大元素.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 23时05分08秒
 ************************************************************************/

public:
    typedef pair<int, int> PII;
    set<PII> s;
    int k, t;//为了防止set自动去重
    KthLargest(int k, vector<int>& nums) {
        this->t = 0;
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
        return ;
    }
    
    int add(int val) {
        if (s.size() < k) {
            s.insert(PII(val, t++));
        } else if (val > s.begin()->first){
            s.erase(s.begin());
            s.insert(PII(val, t++));
        }
        return s.begin()->first;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
