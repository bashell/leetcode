/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
// 链表反转函数(iterative): O(n)
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *pre = NULL, *cur = NULL;
    if(head == NULL || head -> next == NULL)  // o or 1 node
        return head;
    while(head -> next) {  // reverse iteratively
        cur = head;
        head = head -> next;
        cur -> next = pre;
        pre = cur;
    }
    head -> next = cur;
    return head;
}

bool isPalindrome(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return true;
    struct ListNode *left = head, *mid = head, *right = head, *pre = NULL;
    int i, len = 0;
    while(right != NULL) {  // 计算链表长度: O(n)
        ++len;
        right = right -> next;
    }
    for(i = 0; i != len / 2; ++i) {  // 找到中间结点: O(n)  维持pre -> next == mid
        pre = mid;
        mid = mid -> next;
    }
    // 链表反转 + 逐个元素比较: O(n) + O(n) = O(n)
    if(len % 2) {  // 当链表中有奇数个结点时
        struct ListNode *tmp = mid;
        mid -> next = reverseList(mid -> next);  // 反转后半部分
        mid = mid -> next;  // 现在mid指向反转后的第一个结点
        while(mid != NULL) {
            if(left -> val != mid -> val) {
                tmp -> next = reverseList(tmp -> next);  // 恢复链表原有顺序
                return false;
            }
            mid = mid -> next;
            left = left -> next;
        }
        tmp -> next = reverseList(tmp -> next);  // 恢复链表原有顺序
        return true;
    } else {  // 当链表中有偶数个结点时
        pre -> next = reverseList(pre -> next);  // 反转后半部分
        mid = pre -> next;  // 现在mid指向反转后的第一个结点
        while(mid != NULL) {
            if(left -> val != mid -> val) {
                pre -> next = reverseList(pre -> next);  // 恢复链表原有顺序
                return false;
            }
            mid = mid -> next;
            left = left -> next;
        }
        pre -> next = reverseList(pre -> next);  // 恢复链表原有顺序
        return true;
    }
}
