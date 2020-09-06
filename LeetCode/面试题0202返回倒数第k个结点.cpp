/*************************************************************************
	> File Name: 面试题0202返回倒数第k个结点.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 21时24分35秒
 ************************************************************************/
int kthToLast(struct ListNode* head, int k){
    struct ListNode *p, *q, ret;
    ret.next = head;
    p = q = &ret;
    while (k--) p = p->next;
    p = p->next;
    while (p != NULL) {
        p = p->next;
        q = q->next;
    } 
    p = q->next;
    return p->val;
}
