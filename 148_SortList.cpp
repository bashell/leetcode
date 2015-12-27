/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* merge(ListNode* left, ListNode* right) {
        if(left == nullptr) return right;
        if(right == nullptr) return left;
        if(left -> val <= right -> val) {
            left -> next = merge(left -> next, right);
            return left;
        } else {
            right -> next = merge(left, right -> next);
            return right;
        }
    }
    
    // mergeSort
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *ptr1 = head, *ptr2 = head -> next;
        while(ptr2 && ptr2 -> next) {  // let ptr1 point to the mid node
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
        }
        ListNode *right = ptr1 -> next;
        ptr1 -> next = nullptr;
        head = sortList(head);
        right = sortList(right);
        head = merge(head, right);
        return head;
    }
};
