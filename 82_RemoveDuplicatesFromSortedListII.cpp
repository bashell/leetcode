/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Solution1: T(n) = O(n), S(n) = O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;
        unordered_map<int, int> imap;
        for(ListNode *ptr = head ; ptr; ptr = ptr -> next)
            ++imap[ptr -> val];
        while(head) {  // 找到符合条件的头结点
            if(imap[head -> val] == 1)
                break;
            else
                head = head -> next;
        }
        ListNode *pre = head, *cur = head;
        while(cur) {
            if(imap[cur -> val] > 1) {  // 元素出现多次时, 从链表上删除
                cur = cur -> next;
                pre -> next = cur;
            } else {  // 元素只出现一次时, 跳过
                pre = cur;
                cur = cur -> next;
            }
        }
        return head;
    }
};

// Solution2: T(n) = O(n), S(n) = O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode *dummy = new ListNode(head->val - 1);
        dummy->next = head;
        ListNode *pre = dummy, *cur = head;
        int count;
        while(cur) {
            int val = cur->val;
            count = 0;
            while(cur && cur->val == val) {
                cur = cur->next;
                ++count;
            }
            if(count > 1) 
                pre->next = cur;  // 出现多次, 待下轮检查
            else 
                pre = pre->next;  // 仅出现一次, pre前进一步
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
