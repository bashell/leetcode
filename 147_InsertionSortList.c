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
    struct ListNode *pre = NULL, *cur = head -> next, *solved_tail = head, *ptr_tail = NULL, *ptr_tail_aft = NULL;
    while(cur) {
        if(cur -> val < solved_tail -> val) {   // 需要进行插入
            pre = cur;
            cur = cur -> next;
            if(pre -> val <= head -> val) {    // 需要插入在head之前
                solved_tail -> next = cur;
                pre -> next = head;
                head = pre;
            } else {    // 插在head之后的某个位置
                // 从头结点开始向后找到最后一个比待插入结点值小的那个结点q
                for(ptr_tail_aft = head; ptr_tail_aft -> val < pre -> val; ptr_tail_aft = ptr_tail_aft -> next) 
                    ptr_tail = ptr_tail_aft;
                // 遍历之后ptr_tail_aft会指向q后面那个结点，ptr_tail会指向q
                
                pre -> next = ptr_tail -> next;
                ptr_tail -> next = pre;
                solved_tail -> next = cur;
            }
        } else {
            solved_tail = cur;
            cur = cur -> next;
        }
    }
    return head;
}
