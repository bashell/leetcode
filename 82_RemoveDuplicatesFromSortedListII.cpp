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
