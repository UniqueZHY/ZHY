/*************************************************************************
	> File Name: 19_删除链表中的倒数第N个节点.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时34分30秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
   struct ListNode f, *p, *q;
    f.next = head;
    p = q = &f;
    while (n--) p = p->next;
    p = p->next;
    while (p) {
        q = q->next;
        p = p->next;
    }
    p = q->next;
    q->next = p->next;
    free(p);
    return f.next;
}
