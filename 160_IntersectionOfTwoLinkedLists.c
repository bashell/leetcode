/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *ptr1 = headA, *ptr2 = headB;
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
    
    // 将表头指针挪到适合比较的位置
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
