/*************************************************************************
	> File Name: 142.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时25分52秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p, *q;
    q = p = head;
    if (head == NULL) return NULL;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return NULL;
        q = q->next;
    } while (q != p);
    int cnt = 0;
    do {
        cnt++;
        p = p->next;
    } while (p != q);
    q = p = head;
    while (cnt--) p = p->next;
    while (q != p) p = p->next, q = q->next;
    return p;
}


/*struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *p = head, *q = head;
    if (p == NULL) return NULL;
    do {
        p = p->next;
        q = q->next;
        if (q == NULL || q->next == NULL) return NULL;
        q = q->next;
    } while (p != q);
    int cnt = 0;
    do {
        cnt++;
        p = p->next;
    } while (p != q);
    p = head, q = head;
    while (cnt--) q = q->next;
    while (p != q) p = p->next, q = q->next;
    return p;
}*/
