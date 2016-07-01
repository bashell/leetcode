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
        if(head == NULL)
            return NULL;
        while(head && head->val == val)
            head = head->next;
        if(head == NULL) return head;
        else {
            ListNode *ptr = head;
            while(ptr->next) {
                if(ptr->next->val == val)
                    ptr->next = ptr->next->next;
                else
                    ptr = ptr->next;
            }
        }
        return head;
    }
};
