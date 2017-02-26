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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        ListNode *res = NULL, *n, *prev;
        int sum, carry = 0;
        while(l1 || l2) {
            sum = carry;
            if(l1)
                sum += l1->val;
            if(l2)
                sum += l2->val;
            carry = sum/10;
            n = new ListNode(sum%10);
            if(res == NULL)
                res = n;
            else
                prev->next = n;
            prev = n;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry)
            prev->next = new ListNode(carry);
            
        return res;
    }
};