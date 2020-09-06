/*************************************************************************
	> File Name: 295_数据流中的中位数.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 23时03分07秒
 ************************************************************************/
class MedianFinder {
public:
    typedef pair<int, int> PII;
    set<PII> s1, s2;//对顶堆，一个是大顶堆一个是小顶堆
    int t;
    /** initialize your data structure here. */
    MedianFinder() {
        t = 0;
    }
    
    void addNum(int num) {
        if (s1.size() == 0 || num <= -(s1.begin()->first)) {
            //向左边集合插入
            s1.insert(PII(-num, t++));//大顶堆取负号
        } else {
            s2.insert(PII(num, t++));
        }
        //调整中间位置
        if (s1.size() + 2 == s2.size()) {//说明小顶堆中多
            PII temp = *s2.begin();
            temp.first = -(temp.first);
            s1.insert(temp);
            s2.erase(s2.begin());
        }
        if (s2.size() + 2 == s1.size()) {
            PII temp = *s1.begin();
            temp.first = -(temp.first);
            s2.insert(temp);
            s1.erase(s1.begin());
        }
        return ;
    }
    
    double findMedian() {
        //中间值三种情况，大顶堆中最大值或小顶堆中最小值，或最大值和最小值的平均值
        double val1 = s1.size() == 0 ? 0 : -(s1.begin()->first);
        double val2 = s2.size() == 0 ? 0 : s2.begin()->first;
        if (s1.size() == s2.size()) return (val1 + val2) / 2.0;
        return s1.size() > s2.size() ? val1 : val2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
