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
        if(head == NULL || head -> next == NULL)
            return head;
        struct ListNode *ptr = NULL, *pre = NULL, *ptr_head = NULL;
        unordered_map<int, int> imap;
        for(ptr = head ; ptr != NULL; ptr = ptr -> next)
            ++imap[ptr -> val];
            
        // 找到符合条件的头结点
        while(head != NULL)
            if(imap[head -> val] == 1)
                break;
            else
                head = head -> next;
                
        ptr_head = head;
        pre = head;
        while(ptr_head != NULL) {
            if(imap[ptr_head -> val] > 1) {    
                // 元素出现多次时, 从链表上删除
                ptr_head = ptr_head -> next;
                pre -> next = ptr_head;
            } else {
                // 元素只出现一次时, 跳过
                pre = ptr_head;
                ptr_head = ptr_head -> next;
            }
        }
        return head;
    }
};
