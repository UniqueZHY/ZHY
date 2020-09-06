/*************************************************************************
	> File Name: 206_反转链表.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时22分01秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode ret, *p, *q;
    p = head;
    ret.next = NULL;
    while (p != NULL) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
    
}
