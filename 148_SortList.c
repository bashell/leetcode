/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;
    struct ListNode *pre = NULL;
    if(left -> val <= right -> val) {
        left -> next = merge(left -> next, right);
    } else {
        pre = right;
        right = right -> next;
        pre -> next = left;
        left = pre;
        left -> next = merge(left -> next, right);
    }
    return left;
}

// mergeSort 
struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *ptr1 = head, *ptr2 = head -> next, *right = NULL;
    while(ptr2 && ptr2 -> next) {   // let ptr1 point to the mid node
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
    }
    right = ptr1 -> next;
    ptr1 -> next = NULL;
    head = sortList(head);
    right = sortList(right);
    head = merge(head, right);
    return head;
}
