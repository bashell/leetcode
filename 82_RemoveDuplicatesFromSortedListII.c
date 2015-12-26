/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *pre = NULL, *cur = NULL, *work = NULL;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(dummy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    dummy -> val = 0;
    dummy -> next = head;
    pre = dummy;
    cur = head;
    work = head -> next;
    
    while(work) {
        if(work -> val != cur -> val) {  // 不相等时继续遍历
            pre = cur;
            cur = work;
            work = work -> next;
        } else {  // 相等时进行处理
            while(work && work -> val == cur -> val) 
                work = work -> next;
            if(work == NULL) {  // 由于遍历到链表末尾而终止
                pre -> next = NULL;
                break;
            } else {  // 将相同元素移除链表
                pre -> next = work;
                cur = work;
                work = work -> next;
            }
        }
    }
    head = dummy -> next;
    free(dummy);
    return head;
}
