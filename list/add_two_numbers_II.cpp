/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbersUtil(ListNode *l1, ListNode *l2, int *carry, int diff) {
        if(!l1 && !l2)
            return NULL;
        int sum = (l1) ? l1->val : 0;
        ListNode *n = new ListNode(0);
        if(diff) {
            n->next = addTwoNumbersUtil(l1->next, l2, carry, diff-1);
        }
        else {
            sum += (l2) ? l2->val : 0;
            n->next = addTwoNumbersUtil(l1->next, l2->next, carry, 0);
        }
        sum += *carry;
        n->val = sum % 10;
        *carry = sum / 10;
        return n;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) {
            return NULL;
        }
        int n1 = 0, n2 = 0;
        ListNode *p1 = l1, *p2 = l2;
        while(p1!=NULL) {
            n1++;
            p1 = p1->next;
        }
        while(p2!=NULL){
            n2++;
            p2 = p2->next;
        }
        int diff = n1 - n2;
        if(diff < 0) {
            ListNode *temp = l1;
            l1 = l2;
            l2 = temp;
            diff = -diff;
        }
        int carry = 0;
        ListNode *head = addTwoNumbersUtil(l1, l2, &carry, diff);
        if(carry) {
            ListNode *n = new ListNode(carry);
            n->next = head;
            head = n;
        }
        return head;
    }
};