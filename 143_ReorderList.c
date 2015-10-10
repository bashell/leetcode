/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
// 链表反转函数
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)    // 0 or 1 node
        return head;
    struct ListNode *pre = NULL, *cur = NULL;
    // reverse iteratively
    while(head -> next != NULL) {
        cur = head;
        head = head -> next;
        cur -> next = pre;
        pre = cur;
    }
    head -> next = cur;
    return head;
}

void reorderList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
        return;
    struct ListNode *lhead = head, *rhead = head;
    struct ListNode *lpre = NULL, *rpre = NULL, *cur = head;
    int temp;
    
    // 求出链表总结点数
    int nodeNums = 0;
    for(rhead = head; rhead != NULL; rhead = rhead -> next)
        ++nodeNums;
    
    if(nodeNums % 2) {  // 链表中有奇数个结点
        temp = (nodeNums - 1) / 2;
        while(temp-- > 0)
            cur = cur -> next;
        rhead = reverseList(cur);   // 反转链表的后半部分, 并用rhead指向起始结点
        // 进行结点处理
        while(lhead != cur) {
            lpre = lhead;
            lhead = lhead -> next;
            rpre = rhead;
            rhead = rhead -> next;
            lpre -> next = rpre;
            rpre -> next = lhead;
        }
    } else {    // 链表中有偶数个结点
        temp = nodeNums / 2;
        while(temp-- > 0)
            cur = cur -> next;
        rhead = reverseList(cur);   // 反转链表的后半部分, 并用rhead指向起始结点
        // 进行结点处理
        while(lhead -> next != cur) {
            lpre = lhead;
            lhead = lhead -> next;
            rpre = rhead;
            rhead = rhead -> next;
            lpre -> next = rpre;
            rpre -> next = lhead;
        }
    }
}
