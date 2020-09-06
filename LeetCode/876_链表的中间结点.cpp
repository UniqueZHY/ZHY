/*************************************************************************
	> File Name: 876_链表的中间结点.cpp
	> Author: 
	> Mail: 
	> Created Time: 2020年03月04日 星期三 20时29分31秒
 ************************************************************************/

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode* p;
    struct ListNode* q;
    p = q = head;
    while(1)
    {
        if(p->next == NULL)//一个结点和剩一个结点
        {
            break;
        }
        else if(p->next->next == NULL)//两个结点
        {
            q = q -> next;
            break;
        }
        else
        {
            p = p->next ->next;
            q = q->next;
        }
    }
    return q;
}
