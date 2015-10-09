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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ptr1 = headA, *ptr2 = headB;
        int lenA = 0, lenB = 0;
        
        // 分别计算两个单链表的长度
        while(ptr1) {
            ++lenA;
            ptr1 = ptr1 -> next;
        }
        while(ptr2) {
            ++lenB;
            ptr2 = ptr2 -> next;
        }
        
        // 将表头指针挪到适合比较的位置(两个指针后面的结点个数相同)
        while(lenA > lenB) {
            --lenA;
            headA = headA -> next;
        }
        while(lenB > lenA) {
            --lenB;
            headB = headB -> next;
        }
        
        // 逐个结点比较
        while(headA != headB) {
            headA = headA -> next;
            headB = headB -> next;
        }
        return headA;
    }
};
