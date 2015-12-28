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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        int cnt = 0;
        ListNode *end = head;
        for(; end -> next; end = end -> next)
            ++cnt;
        ++cnt;
        if(k % cnt == 0)    // we do nothing when k is multiple of cnt
            return head;
        ListNode *pre = nullptr, *ptr_head = head;
        for(int i = cnt - k % cnt; i > 0; --i) {
            pre = ptr_head;
            ptr_head = ptr_head -> next;
        }
        pre -> next = nullptr;
        end -> next = head;
        head = ptr_head;
        return head;
    }
};
