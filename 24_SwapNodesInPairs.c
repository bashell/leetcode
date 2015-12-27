/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/* recursive version */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)  // base cases
        return head;
    struct ListNode *newHead = head -> next, *remHead = head -> next -> next;
    newHead -> next = head;
    head -> next = swapPairs(remHead);
    return newHead;
}

/* iterative version */
struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *pre = NULL, *cur = head, *temp = NULL;
    while(cur && cur -> next) {
        temp = cur -> next;
        cur -> next = temp -> next;
        temp -> next = cur;
        if(pre == NULL)
            head = temp;
        else
            pre -> next = temp;
        pre = cur;
        cur = cur -> next;
    }
    return head;
}
