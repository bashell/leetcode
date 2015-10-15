/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 /* iterative version */
struct ListNode* reverseList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *pre = NULL, *cur = NULL;
    while(head -> next != NULL) {
        cur = head;
        head = head -> next;
        cur -> next = pre;
        pre = cur;
    }
    head -> next = cur;
    return head;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(k == 1)
        return head;
    struct ListNode *pre = NULL, *cur = head, *head_temp = head;;
    for(int i = k; i > 0; --i) {
        if(cur) {
            pre = cur;
            cur = cur -> next;
        }
        else
            return head;    // 剩余结点个数不足K个时，不需要进行反转，直接返回即可
    }
    if(cur == NULL)    // 正好剩下了K个结点
        return reverseList(head);
    else {    // 剩下的结点数大于K个
        pre -> next = NULL;    // 执行此步是为了执行下一步的reverseList()
        head = reverseList(head);
        head_temp -> next = reverseKGroup(cur, k);    // 递归进行余下操作
    }
    return head;
}
