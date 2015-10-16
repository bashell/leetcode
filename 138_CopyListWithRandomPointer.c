/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     struct RandomListNode *next;
 *     struct RandomListNode *random;
 * };
 */
struct RandomListNode *copyRandomList(struct RandomListNode *head) {
    if(head == NULL)
        return NULL;
    struct RandomListNode *resHead = NULL;
    // 为每个结点a增加一个新结点a' : a -> a' -> b -> b' -> c -> c' -> ...
    for(struct RandomListNode *ptr = head; ptr;) {
        struct RandomListNode *tmp = (struct RandomListNode *)malloc(sizeof(struct RandomListNode));
        tmp -> label = ptr -> label;
        tmp -> random = NULL;
        tmp -> next = ptr -> next;
        ptr -> next = tmp;
        ptr = ptr -> next -> next;
    }
    // 为每个新结点设置random指针域
    for(struct RandomListNode *ptr = head; ptr; ptr = ptr -> next -> next) {
        if(ptr -> random != NULL) 
            ptr -> next -> random = ptr -> random -> next;    // 以前a的random指向c时，则设置a'的random指向c'
    }
    // 新增头结点resHead
    resHead = (struct RandomList *)malloc(sizeof(struct RandomListNode));
    resHead -> label = -1;
    resHead -> next = NULL;
    resHead -> random = NULL;
    // 拆分新旧结点
    for(struct RandomListNode *tmpHead = head, *tmpResHead = resHead; tmpHead; ) {
        tmpResHead -> next = tmpHead -> next;
        tmpResHead = tmpResHead -> next;
        tmpHead -> next = tmpHead -> next -> next;
        tmpHead = tmpHead -> next;
    }
    return resHead -> next;
}
