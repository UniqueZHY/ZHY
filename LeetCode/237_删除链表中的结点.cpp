/*************************************************************************
	> File Name: 237_删除链表中的结点.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年02月26日 星期三 16时08分26秒
 ************************************************************************/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *p, *q, ret;
    p = node->next;
    node->val = p->val;
    node->next = p->next;
    return node;
}
