/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    if(head == NULL || head -> next == NULL && head -> val == val)
        return NULL;
    struct ListNode *pre = NULL;
    struct ListNode *newHead = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(newHead == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newHead -> val = val - 1;
    newHead -> next = head;

    head = newHead;
    pre = newHead;
    while(head) {
        if(head -> val == val) {
            head = head -> next;
            pre -> next = head;
        } else {
            pre = head;
            head = head -> next;
        }
    }
    head = newHead -> next;
    free(newHead);
    return head;
}
