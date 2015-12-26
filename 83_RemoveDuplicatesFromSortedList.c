/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *pre = head, *cur = head;
    while(cur) {
        while(cur && cur -> val == pre -> val)
            cur = cur -> next;
        pre -> next = cur;
        pre = cur;
    }
    return head;
}
