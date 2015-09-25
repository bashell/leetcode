/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /* iterative version */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL, *cur = NULL;
    if(head == NULL || head -> next == NULL)
        return head;
    
    // reverse iteratively
    while(head -> next != NULL)
    {
        cur = head;
        head = head -> next;
        cur -> next = pre;
        pre = cur;
    }
    head -> next = cur;    // reverse completed !
    
    return head;
}

/* recursive version */
struct ListNode* reverseList(struct ListNode* head){
    if(head == NULL || head -> next == NULL)    // base case
        return head;
        
    // reverse recursively
    struct ListNode *rhead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    
    return rhead;
}
