/*************************************************************************
	> File Name: LK19.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月14日 星期五 11时53分59秒
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
    p = q = f;
    while (n--) p->next;
    p = p->next;
    while (p) {
        p = p->next;
        q = q->next;
    }
    p = q->next;
    q->next = p->next;
    free(p);
    return f.next;
}
