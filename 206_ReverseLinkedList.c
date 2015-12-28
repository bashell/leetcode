/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /* iterative version */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)    // 0 or 1 node
        return head;
    struct ListNode *pre = NULL, *cur = NULL;
    while(head -> next != NULL) {  // reverse iteratively
        cur = head;
        head = head -> next;
        cur -> next = pre;
        pre = cur;
    }
    head -> next = cur;
    return head;
}

/* recursive version */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)    /* 0 or 1 node */
        return head;
    struct ListNode *rhead = reverseList(head -> next);  // reverse recursively
    head -> next -> next = head;
    head -> next = NULL;
    return rhead;
}
