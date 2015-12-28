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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)  // 0 or 1 node
            return head;
        ListNode *pre = nullptr, *cur = nullptr;
        while(head -> next != nullptr) {  // reverse iteratively
            cur = head;
            head = head -> next;
            cur -> next = pre;
            pre = cur;
        }
        head -> next = cur;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *ptr_m = head;
        for(int i = 1; i < m; ++i) {  // let ptr_m point to location m
            pre = ptr_m;
            ptr_m = ptr_m -> next;
        }
        ListNode *tmp = ptr_m;
        for(int i = m; i < n; ++i)
            tmp = tmp -> next;
        ListNode *ptr_n = tmp -> next;  // let ptr_n point to location n
        tmp -> next = nullptr;
        pre -> next = reverseList(ptr_m);
        ptr_m -> next = ptr_n;
        head = dummy -> next;
        delete dummy;
        return head;
    }
};
