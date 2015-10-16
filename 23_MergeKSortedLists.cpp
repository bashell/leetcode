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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ivec;
        for(int i = 0; i < lists.size(); ++i) {
            for(ListNode *ptr = lists[i]; ptr; ptr = ptr -> next) {
                ivec.push_back(ptr -> val);
            }
        }
        if(ivec.size() == 0)    // K个链表均为空
            return NULL;
        else {
            std::sort(ivec.begin(), ivec.end());
            ListNode *head = new ListNode(ivec[0]);
            ListNode *ptr = head;
            for(int i = 1; i < ivec.size(); ++i) {
                ListNode *tmp = new ListNode(ivec[i]);
                ptr -> next = tmp;
                ptr = ptr -> next;
            }
            return head;
        }
    }
};
