/*************************************************************************
	> File Name: 141.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月25日 星期二 21时23分55秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *a = head, *b = head;
    if (a == NULL) return false;
    do {
        a = a->next;
        b = b->next;
        if (b == NULL || b->next == NULL) return false;
        b = b->next;
    } while (a != b);
    return true;
}
