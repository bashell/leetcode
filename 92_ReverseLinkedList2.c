/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if(head == NULL || head -> next == NULL || m == n)
        return head;
    // head_tmp临时存储head, ptr_before_m指向位置m - 1, ptr_m指向位置m, ptr_n指向位置n
    struct ListNode *head_tmp = head, *ptr_before_m = NULL, *ptr_m = NULL, *ptr_n = NULL;
    struct ListNode *pre = NULL, *cur = NULL;    // 用于链表反转
    int cur_pos = 1;    // 当前指针的位置
    
    if(m == 1)
    {
        // 将位置m到位置n的部分反转
        while(cur_pos < n)
        {
            cur = head_tmp;
            head_tmp = head_tmp -> next;
            cur -> next = pre;
            pre = cur;
            ++cur_pos;
        }
        head -> next = head_tmp -> next;    // head指向反转后的部分链表的尾结点
        head_tmp -> next = cur;    // 完成反转
        return head_tmp;
        
    }else{
        // 遍历到位置m - 1处
        while(cur_pos < m - 1)
        {
            head_tmp = head_tmp -> next;
            ++cur_pos;
        }
        ptr_before_m = head_tmp;    // ptr_before_m指向位置 m - 1
        head_tmp = head_tmp -> next;    // head_tmp指向位置m
        ++cur_pos;
        ptr_m = head_tmp;    // ptr_m 指向 position m
        
        // 将位置m到位置n的部分反转
        while(cur_pos < n)
        {
            cur = head_tmp;
            head_tmp = head_tmp -> next;
            cur -> next = pre;
            pre = cur;
            ++cur_pos;
        }
        ptr_m -> next = head_tmp -> next;    // 将反转后的部分链表的尾结点指向未遍历的第一个结点(或NULL)
        head_tmp -> next = cur;    // 完成反转
        ptr_before_m -> next = head_tmp;    // 将位置m - 1的结点指向反转后链表的头结点
        return head;
    }
}
