/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head == NULL || head -> next == NULL)
        return NULL;
    struct ListNode *fast = head, *slow = head;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast)
            break;
    }
    // 不存在环
    if(fast == NULL || fast -> next == NULL)
        return NULL;
    // 存在环, 下面寻找入口结点
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
