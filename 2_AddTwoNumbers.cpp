/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
 ** 生成额外的链表
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 || l2 || carry) {
            if(l1) {
                carry += l1 -> val;
                l1 = l1 -> next;
            }
            if(l2) {
                carry += l2 -> val;
                l2 = l2 -> next;
            }
            cur -> next = new ListNode(carry % 10);
            cur = cur -> next;
            carry /= 10;
        }
        return dummy -> next;
    }
};
