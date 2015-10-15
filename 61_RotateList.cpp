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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head -> next == NULL)
            return head;
        ListNode *ptr = head, *ptrHead = NULL, *pre = NULL;
        int cnt = 0;
        while(ptr) {    // 求出链表总结点数
            ++cnt;
            ptr = ptr -> next;
        }
        if(k % cnt == 0)    // k为cnt整数倍时, 链表结构不需要调整
            return head;
        ptr = head;
        for(int i = cnt - k % cnt; i > 0; --i) {
            pre = head;
            head = head -> next;
        }
        pre -> next = NULL;
        for(ptrHead = head; ptrHead -> next != NULL; ptrHead = ptrHead -> next)
            ;
        ptrHead -> next = ptr;
        return head;
    }
};
