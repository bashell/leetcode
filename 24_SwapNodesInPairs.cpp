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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)  // base cases
            return head;
        ListNode *newHead = head -> next, *remHead = head -> next -> next;
        newHead -> next = head;
        head -> next = swapPairs(remHead);
        return newHead;
    }
};

/* iterative version */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *pre = dummy, *cur = head;
        while(cur && cur -> next) {
            ListNode *temp = cur -> next;
            cur -> next = temp -> next;
            temp -> next = cur;
            pre -> next = temp;
            pre = cur;
            cur = cur -> next;
        }
        head = dummy -> next;
        delete dummy;
        return head;
    }
};
