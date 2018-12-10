/*
Given a linked list, remove the n-th node from the end of list and return its head.
Example:
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int length(struct ListNode* head){
    int len = 0;
    while(head != NULL){
        len++;
        head = head->next;
    }
    return len;
}
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    if(head == NULL)
        return NULL;
    struct ListNode* temp = head;
    int len = length(head);
    int node = (len-n);
    
    if(node == 0)
        return head->next;
    
    for(int i = 0; (i < node-1 && temp != NULL) ; i++)
        temp = temp->next;
    
    struct ListNode *ml = temp->next;
    temp->next = ml->next;
    free(ml);
    
    return head;
    
}
