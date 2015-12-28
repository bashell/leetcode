/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
 ** use multiset
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        std::multiset<int> iset;
        for(int i = 0; i < lists.size(); ++i)
            for(ListNode *ptr = lists[i]; ptr; ptr = ptr -> next)
                iset.insert(ptr -> val);
        if(iset.size() == 0)  // all the lists are empty
            return nullptr;
        ListNode *head = new ListNode(*iset.cbegin());
        ListNode *cur = head;
        for(auto iter = ++iset.cbegin(); iter != iset.cend(); ++iter) {
            ListNode *tmp = new ListNode(*iter);
            cur -> next = tmp;
            cur = cur -> next;
        }
        return head;
    }
};

/*
 ** use vector
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ivec;
        for(int i = 0; i < lists.size(); ++i)
            for(ListNode *ptr = lists[i]; ptr; ptr = ptr -> next)
                ivec.push_back(ptr -> val);
        if(ivec.size() == 0)  // all the lists are empty
            return NULL;
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
};
