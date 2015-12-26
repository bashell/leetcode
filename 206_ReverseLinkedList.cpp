/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* iterative version */
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
};

/* recursive version */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)  // 0 or 1 node
            return head;
        ListNode* rhead = reverseList(head -> next);  // revrese recursively
        head -> next -> next = head;
        head -> next = nullptr;
        return rhead;
    }
};
