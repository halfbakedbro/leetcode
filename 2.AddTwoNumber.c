/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* res = NULL;
    struct ListNode* iter = NULL;
    int sum = 0 , carry = 0, val;
    while(l1 != NULL && l2 != NULL){
        sum = l1->val + l2->val + carry;
        carry = sum/10;
        val = sum%10;
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->val = val;
        temp->next = NULL;
        if(res == NULL){
            res = temp;
        }else{
            struct ListNode* t = res;
            while(t->next != NULL){
                t = t->next;
            }
            
            t->next = temp;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    if(l1 != NULL){
        iter = l1;
    }else if(l2 != NULL){
        iter = l2;
    }
    
    while(carry || iter != NULL){
        
        struct ListNode* temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        sum = ((iter)? iter->val : 0) + carry;
        carry = sum/10;
        val = sum%10;
        temp->val = val;
        temp->next = NULL;
        if(res == NULL){
            res = temp;
        }else{
            struct ListNode* t = res;
            while(t->next != NULL){
                t = t->next;
            }
            
            t->next = temp;
        }
        
        if(iter)
            iter = iter->next;
    }
    
    return res;
}
