/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
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

void reorderList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL || head -> next -> next == NULL)
        return;
    struct ListNode *lhead = head, *rhead = head;
    struct ListNode *lpre = NULL, *rpre = NULL, *cur = head;
    int mid;  // the mid position
    int nodeNums = 0;  // the total numbers of nodes
    
    for(; rhead; rhead = rhead -> next)
        ++nodeNums;
    if(nodeNums % 2) {  // odd
        mid = (nodeNums - 1) / 2;
        while(mid-- > 0)
            cur = cur -> next;
        rhead = reverseList(cur);   // reverse the right half
        while(lhead != cur) {
            lpre = lhead;
            lhead = lhead -> next;
            rpre = rhead;
            rhead = rhead -> next;
            lpre -> next = rpre;
            rpre -> next = lhead;
        }
    } else {    // even
        mid = nodeNums / 2;
        while(mid-- > 0)
            cur = cur -> next;
        rhead = reverseList(cur);   // reverse the right half
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
