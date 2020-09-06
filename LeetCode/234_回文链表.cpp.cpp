/*************************************************************************
	> File Name: 234.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 15时24分15秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode *head) {
    int len = 0;
    while (head) len += 1, head = head->next;
    return len;
}

struct ListNode *getNode (struct ListNode *head, int ind) {
    while (ind--) head = head->next;
    return head;
}

struct ListNode *reverse(struct ListNode *head) {
    struct ListNode *p = head, *q, ret;
    ret.next = NULL;
    while (p) {
        q = p->next;
        p->next = ret.next;
        ret.next = p;
        p = q;
    }
    return ret.next;
}
bool isPalindrome(struct ListNode* head){
    int len = length(head);
    struct ListNode *p = head, *q = reverse(getNode(head, (len + 1) / 2));
    while (q) {
        if (p->val - q->val) return false;
        p = p->next;
        q = q->next;
    }
    return true;
}
