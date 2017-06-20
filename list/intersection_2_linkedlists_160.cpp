/*
Write a program to find the node at which the intersection of two singly linked lists begins.


For example, the following two linked lists:

A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗            
B:     b1 → b2 → b3
begin to intersect at node c1.


Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
            return NULL;
        unsigned long int lengthA = 0, lengthB = 0;
        ListNode *pA = headA, *pB = headB;
        while(pA != NULL) {
            lengthA++;
            pA = pA->next;
        }
        while(pB != NULL) {
            lengthB++;
            pB = pB->next;
        }
        if(lengthB > lengthA) {
            swap(headA, headB);
            swap(lengthA, lengthB);
        }
        pA = headA;
        pB = headB;
        unsigned long int diff = lengthA - lengthB;
        while(diff--) {
            pA = pA->next;
        }
        while(pA!=NULL && pB!=NULL && pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return ((pA == pB) ? pA : NULL);
    }
};