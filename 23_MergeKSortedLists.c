/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    struct ListNode *head = NULL, *head_ptr = NULL;

    if(l1 -> val <= l2 -> val) {
        head = l1;
        l1 = l1 -> next;
    } else {
        head = l2;
        l2 = l2 -> next;
    }
    head_ptr = head;
    while(l1 && l2) {
        if(l1 -> val <= l2 -> val) {
            head_ptr -> next = l1;
            l1 = l1 -> next;
        } else {
            head_ptr -> next = l2;
            l2 = l2 -> next;
        }
        head_ptr = head_ptr -> next;
    }
    head_ptr -> next = (l1 ? l1 : l2);
    return head;
}

struct ListNode* merge(struct ListNode** lists, int beg, int end) {
    if(beg > end)
        return NULL;
    else if(beg == end)
        return lists[beg];
    else {
        int mid = (end - beg) / 2 + beg;
        struct ListNode* left = merge(lists, beg, mid);
        struct ListNode* right = merge(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(0 == listsSize)
        return NULL;
    return merge(lists, 0, listsSize - 1);
}
