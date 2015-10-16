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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL)
            return head;
        vector<int> ivec1, ivec2;
        for(ListNode *ptr = head; ptr; ptr = ptr -> next) {
            if(ptr -> val < x) 
                ivec1.push_back(ptr -> val);    // ivec1中存放的值 < x
            else
                ivec2.push_back(ptr -> val);    // ivec2中存放的值 >= x
        }
        // 链表中所有结点的值全都大于或者全都小于x时，不需要进行操作
        if(ivec1.size() == 0 || ivec2.size() == 0)
            return head;
        // 对链表中的值按要求重新赋值
        int i = 0, j = 0;
        for(ListNode *ptr = head; ptr; ptr = ptr -> next) {
            if(i < ivec1.size()) {
                ptr -> val = ivec1[i];
                ++i;
            } else {
                ptr -> val = ivec2[j];
                ++j;
            }
        }
        return head;
    }
};
