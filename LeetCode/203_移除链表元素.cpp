/*************************************************************************
	> File Name: 203_移除链表元素.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时23分39秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    struct ListNode ret, *p = &ret, *q;
        ret.next = head;
        while (p && p->next) {
            if (p->next->val == val) {
                q = p->next;
                p->next = p->next->next;
                free(q);
            } else {
                p = p->next;
            }
        }
        return ret.next;
}
