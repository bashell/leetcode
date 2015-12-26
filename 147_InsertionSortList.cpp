/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* recursive version */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *rhead = insertionSortList(head -> next);
        if(head -> val <= rhead -> val) {
            head -> next = rhead;
            return head;
        } else {
            ListNode *pre = rhead, *cur = rhead -> next;
            while(cur && cur -> val <= head -> val) {
                pre = cur;
                cur = cur -> next;
            }
            if(cur == nullptr) {
                pre -> next = head;
                head -> next = nullptr;
            } else {
                head -> next = pre -> next;
                pre -> next = head;
            }
            return rhead;
        }
    }
};
