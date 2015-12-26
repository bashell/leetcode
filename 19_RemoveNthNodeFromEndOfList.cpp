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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return head;
        ListNode *first = head, *second = head, *first_pre = nullptr;
        for(int i = 0; i != n; ++i)  // 使second指针领先first指针n个结点
            second = second -> next;
        while(second) {  // 当second指向末尾的NULL时, first指向待删除的结点
            first_pre = first;
            first = first -> next;
            second = second -> next;
        }
        if(first_pre == nullptr)  // 在头结点删除时
            head = head -> next;
        else 
            first_pre -> next = first -> next;  // 不在头结点删除时
        return head;
    }
};
