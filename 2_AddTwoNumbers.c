/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    // ptr用于遍历链表求长度，head为返回的头结点，ptr_head用于代替head进行遍历
    struct ListNode *ptr = NULL, *head = NULL, *ptr_head = NULL;
    struct ListNode *ptr_pre = NULL, *ptr_pre1 = NULL, *ptr_pre2 = NULL;
    int len1, len2;
    int carry;    // 进位标志：1代表进位，0代表不进位
    
    // 分别计算两个链表长度
    for(len1 = 0, ptr = l1; ptr; ptr = ptr -> next)
        ++len1;
    for(len2 = 0, ptr = l2; ptr; ptr = ptr -> next)
        ++len2;
        
    head = len1 >= len2 ? l1 : l2;    // 设置结果头结点(head应指向较长的那个链表)
    ptr_head = head;    // 设置ptr_head，用于代替head进行操作
    carry = 0;
    
    while(l1 && l2) {
        int cal = l1 -> val + l2 -> val + carry;
        l1 = l1 -> next;
        l2 = l2 -> next;
        ptr_head -> val = cal % 10;
        ptr_pre = ptr_head;    // ptr_pre记录ptr_head指向的前一个结点
        ptr_head = ptr_head -> next;
        if(cal >= 10)    // 发生进位
            carry = 1;
        else
            carry = 0;
    }
    
    /* while循环退出时，l1、l2必有一个为NULL */
    if(carry == 1) {  // 较短的链表处理结束后(或者两个链表都处理完毕)，仍有进位需要继续处理
        if(l1 == NULL && l2 == NULL) {    // 两个链表都处理完毕
            struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
            ptr -> val = 1;
            ptr -> next = NULL;
            ptr_pre -> next = ptr;
        } else if(l1 == NULL && l2 != NULL) {    // l1处理完毕，l2未处理完毕
            while(l2) {
                int cal = l2 -> val + carry;
                l2 = l2 -> next;
                ptr_head -> val = cal % 10;
                ptr_pre2 = ptr_head;
                ptr_head = ptr_head -> next;
                if(cal >= 10)   // 连续进位
                    carry = 1;
                else {
                    carry = 0;
                    break;    // 不需要进位，退出循环
                }
            }
            if(carry == 1) {    // 说明l2的长度不够
                struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
                ptr -> val = 1;
                ptr -> next = NULL;
                ptr_pre2 -> next = ptr;
            }
        } else if(l1 != NULL && l2 == NULL) {    // l2处理完毕，l1
            while(l1) {
                int cal = l1 -> val + carry;
                l1 = l1 -> next;
                ptr_head -> val = cal % 10;
                ptr_pre1 = ptr_head;
                ptr_head = ptr_head -> next;
                if(cal >= 10)   // 连续进位
                    carry = 1;
                else {
                    carry = 0;
                    break;    // 不需要进位，退出循环
                }
            }
            if(carry == 1) {    // 说明l1的长度不够
                struct ListNode *ptr = (struct ListNode *)malloc(sizeof(struct ListNode));
                ptr -> val = 1;
                ptr -> next = NULL;
                ptr_pre1 -> next = ptr;
            }
        }
    }
    return head;
}
