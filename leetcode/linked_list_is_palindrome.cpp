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
    bool isPalindrome(ListNode* &front, ListNode* back) {
        if(back->next == NULL) {
            int curr = front->val;
            front = front->next;
            return curr == back->val;
        }
        bool res = isPalindrome(front, back->next);
        //if(front == back || front->next == back)
        //    return res;
        
        if(res) {
            if(front->val == back->val) {
                front = front->next;
                return true;
            }
            else
                return false;
        }
        else
            return false;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return true;
        return isPalindrome(head, head->next);
    }
};
