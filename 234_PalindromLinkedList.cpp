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
    ListNode *reverseList(ListNode *head) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *pre = NULL, *cur = head;
        while(cur -> next) {
            ListNode *next = cur -> next;
            cur -> next = pre;
            pre = cur;
            cur = next;
        }
        cur -> next = pre;
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return true;
        ListNode *slow = head, *fast = head, *cur = head;
        while(fast -> next && fast -> next -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = reverseList(slow -> next);
        slow = slow -> next;
        while(slow) {
            if(slow -> val != cur -> val)
                return false;
            slow = slow -> next;
            cur = cur -> next;
        }
        return true;
    }
};
