/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head == NULL || head -> next == NULL)
        return false;
    // 快慢指针判断法
    struct ListNode *fast = head -> next, *slow = head;
    while(fast != slow){
        if(fast == NULL || fast -> next == NULL)    // 无环
            return false;
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return true;
}
