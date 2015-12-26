/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// 向前找最后一个比*cur结点值大的那个结点p，然后插在p前 <=> 从头向后找最后一个比*cur结点值小的那个结点q，然后插在q之后
struct ListNode* insertionSortList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;
    struct ListNode *pre = head, *cur = head -> next;
    struct ListNode *dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(dummy == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    dummy -> val = 0;
    dummy -> next = head;
    while(cur) {
        if(cur -> val < pre -> val) {  // 需要插入
            struct ListNode *ppre = dummy;
            // while结束后ppre指向最后一个比cur值小的那个结点
            // ppre -> next 一定不为NULL, 因为最差的情况是 ppre -> next 指向 pre
            while(ppre -> next -> val < cur -> val)  
                ppre = ppre -> next;
            // 插入操作
            pre -> next = cur -> next;
            cur -> next = ppre -> next;
            ppre -> next = cur;
            cur = pre -> next;
        } else {  // 不需要插入
            pre = cur;
            cur = cur -> next;
        }
    }
    head = dummy -> next;
    free(dummy);
    return head;
}
