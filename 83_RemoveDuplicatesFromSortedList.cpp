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
        set<int> elements;
        if(head == nullptr)
            return nullptr;
        ListNode *pre = nullptr, *cur = head;
        while(cur){  // 若val未出现在set容器中,将val加入set中
            if(0 == elements.count(cur -> val)){
                elements.insert(cur -> val);    
                pre = cur;
                cur = cur -> next;
            } else {  // 若val已经出现在set容器中,跳过这个元素
                pre -> next = cur -> next;
                cur = cur -> next;
            }
        }
        return head;
    }
};
