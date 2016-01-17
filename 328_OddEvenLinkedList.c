/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *second_node = head -> next;
    struct ListNode *ptr_odd = head, *ptr_even = head -> next;
    while(1) {
        if(ptr_even -> next == NULL) {  
            ptr_odd -> next = NULL;
            break;
        }
        ptr_odd -> next = ptr_even -> next;
        ptr_odd = ptr_odd -> next;
        if(ptr_odd -> next == NULL) {
            ptr_even -> next = NULL;
            break;
        }
        ptr_even -> next = ptr_odd -> next;
        ptr_even = ptr_even -> next;
    }
    ptr_odd -> next = second_node;
    return head;
}
