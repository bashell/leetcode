/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head->next == NULL)
        return head;
    struct ListNode *ptr = head;
    while(ptr->next) {
        if(ptr->next->val == ptr->val) 
            ptr->next = ptr->next->next;
        else
            ptr = ptr->next;
    }
    return head;
}
