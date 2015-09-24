/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 
 
/* recursive version */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    
    struct ListNode *head;
    if(l1 -> val <= l2 -> val)
    {
        head = l1;
        head -> next = mergeTwoLists(l1 -> next, l2);
    }else{
        head = l2;
        head -> next = mergeTwoLists(l1, l2 -> next);
    }
    return head;
}


/* iterative version */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    struct ListNode *head = NULL, *head_ptr = NULL;
    
    // 设置头结点
    if(l1 -> val <= l2 -> val)
    {
        head = l1;
        l1 = l1 -> next;
    }else
    {
        head = l2;
        l2 = l2 -> next;
    }
    
    head_ptr = head;    // head_ptr用于遍历
    while(l1 && l2)
    {
        if(l1 -> val <= l2 -> val)
        {
            head_ptr -> next = l1;
            l1 = l1 -> next;

        }else
        {
            head_ptr -> next = l2;
            l2 = l2 -> next;
        }
        head_ptr = head_ptr -> next;
    }
    head_ptr -> next = (l1 ? l1 : l2);    // l1和l2谁非空就将谁连到最后
    
    return head;
}
