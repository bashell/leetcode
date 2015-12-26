/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/* reversive version */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode *head;
        if(l1 -> val <= l2 -> val) {
            head = l1;
            head -> next = mergeTwoLists(l1 -> next, l2);
        } else {
            head = l2;
            head -> next = mergeTwoLists(l1, l2 -> next);
        }
        return head;
    }
};

/* iterative version */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode *head = nullptr;
        // 设置头结点
        if(l1 -> val <= l2 -> val) {
            head = l1;
            l1 = l1 -> next;
        } else {
            head = l2;
            l2 = l2 -> next;
        }
        ListNode *head_ptr = head;  // head_ptr用于遍历
        while(l1 && l2) {
            if(l1 -> val <= l2 -> val) {
                head_ptr -> next = l1;
                l1 = l1 -> next;
            } else {
                head_ptr -> next = l2;
                l2 = l2 -> next;
            }
            head_ptr = head_ptr -> next;
        }
        head_ptr -> next = (l1 ? l1 : l2);  // 链接最后的非空者
        return head;
    }
};
