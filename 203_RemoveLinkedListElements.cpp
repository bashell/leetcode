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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return nullptr;
        ListNode *pre = nullptr, *cur = head;
        while(cur) {
            if(cur -> val == val) {
                if(pre == nullptr) {
                    head = head -> next;
                    cur = head;
                } else {
                    pre -> next = cur -> next;
                    cur = cur -> next;
                }
            } else {
                pre = cur;
                cur = cur -> next;
            }
        }
        return head;
    }
};
