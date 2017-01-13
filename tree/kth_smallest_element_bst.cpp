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
    long int kthSmallest(TreeNode* root, int k) {
        long int curr = -1, kele = LONG_MAX;
        kthSmallestUtil(root, k, &curr, &kele);
        return kele;
    }
    
    void kthSmallestUtil(TreeNode* root, int k, long int* curr, long int* kele) {
        if(root == NULL)
            return;
        if(root->left == NULL && *curr == -1) 
            *curr = 0;
        if(*kele == LONG_MAX)
            kthSmallestUtil(root->left, k, curr, kele);
        (*curr)++;
        if(*curr == k)
            *kele = root->val;
        if(*kele == LONG_MAX)
            kthSmallestUtil(root->right, k, curr, kele);
    }
};