//using queue
#include<queue>
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{
    std::queue<node *> q;
    if(root != NULL)
        q.push(root);
    while(!q.empty()) {
        node * temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
}

//without using queue
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
    unsigned int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        unsigned int lheight = height(root->left);
        unsigned int rheight = height(root->right);
        return max(lheight, rheight) + 1;
    }
    
    void givenLevelElements(TreeNode* root, unsigned int level, vector<int>& elements) {
        if(root == NULL)
            return;
        if(level == 1)
            elements.push_back(root->val);
        else if (level > 1) {
            givenLevelElements(root->left, level-1, elements);
            givenLevelElements(root->right, level-1, elements);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        unsigned int h = height(root);
        vector<vector<int>> levOrdTra;
        for(unsigned int i=1; i<=h; i++) {
            vector<int> elements;
            givenLevelElements(root, i, elements);
            levOrdTra.push_back(elements);
        }
        return levOrdTra;
    }
};
