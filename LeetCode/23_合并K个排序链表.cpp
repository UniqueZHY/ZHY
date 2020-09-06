/*************************************************************************
	> File Name: 23_合并K个排序链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年05月16日 星期六 23时01分38秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    typedef pair<int, ListNode *> PIL;//第一个维度放链表节点中的数值，第二个维度放链表的地址
    typedef pair<int, PIL> PIP;
    set<PIP> s;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (int i = 0; i < lists.size(); i++) {
            //将有序链表的当前头部结点存在set中
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));                             
                           //值          第几个链表中的值

            lists[i] = lists[i]->next;
        }
        ListNode ret, *p = &ret;
        ret.next = NULL;
        while (s.size()) {
            PIP temp = *s.begin();//找到set中最小的
            s.erase(s.begin());//从set中删除待插入到结果链表的结点
            p->next = temp.second.second;//在对应链表中找到值并插入到结果链表中
            p = p->next;
            int i = temp.second.first;
            if (lists[i] == NULL) continue;
            s.insert(PIP(lists[i]->val, PIL(i, lists[i])));//插入后在将插入结点所在链表的下一个加入到set中
            lists[i] = lists[i]->next;
        }
        return ret.next;
    }
};
