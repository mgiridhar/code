/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<ListNode *, ListNode *> findMid(ListNode *head) {
        if(head == NULL) 
            return pair<ListNode *, ListNode *>(NULL, NULL);
        ListNode *slow = head, *fast = head->next, *prev = NULL;
        while(fast != NULL) {
            fast = fast->next;
            if(fast)
                fast = fast->next;
            else
                return make_pair(prev, slow);
            prev = slow;
            slow = slow->next;
        }
        return make_pair(prev, slow);
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        pair<ListNode *, ListNode *> mid = findMid(head);
        if(mid.second == NULL)
            return NULL;
        cout << mid.second->val << endl;
        TreeNode *root = new TreeNode(mid.second->val);
        if(mid.first) {
            mid.first->next = NULL;
            root->left = sortedListToBST(head);
        }
        if(mid.second->next) {
            root->right = sortedListToBST(mid.second->next);
        }
        return root;
    }
};