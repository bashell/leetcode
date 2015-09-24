/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    // 将下一个元素的值和next指针都赋给当前元素
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
}
