/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// recursive version
struct ListNode* swapPairs(struct ListNode head) {
    // base case
    if(head == NULL || head -> next == NULL)
        return head;

    struct ListNode *newHead = NULL, *remHead = NULL;
    newHead = head -> next;
    remHead = head -> next -> next;
    newHead -> next = head;
    head -> next = swapPairs(remHead);

    return newHead;
}

// iterative version
struct ListNode* swapPairs(struct ListNode head) {
    if(head == NULL || head -> next == NULL)
        return head;
    
    struct ListNode *pre = NULL, *temp = NULL, *cur = head;
    while(cur != NULL && cur -> next != NULL)
    {
        temp = cur -> next;
        cur -> next = temp -> next;
        temp -> next = cur;
        if(pre == NULL)    // 设置头结点
            head = temp;
        else
            pre -> next = temp;    // 更改上一对指针的指向
        pre = cur;
        cur = cur -> next;
    }
    return head;
    }
}
