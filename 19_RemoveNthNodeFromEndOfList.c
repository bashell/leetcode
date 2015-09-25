/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(head == NULL)
        return NULL;
        
    struct ListNode *first = head, *second = head, *first_pre = NULL;
    int i;
    for(i = 0; i != n; ++i)    // 使second指针领先first指针n个结点
        second = second -> next;
    while(second != NULL) {    // 当second指向末尾的NULL时, first指向待删除的结点
        first_pre = first;
        first = first -> next;
        second = second -> next;
    }
    if(first_pre == NULL)    // 在头结点删除时
        return head -> next;
    else {
        first_pre -> next = first -> next;    // 不在头结点删除时
        return head;
    }
}
