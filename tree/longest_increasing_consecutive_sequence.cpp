/*
struct Node
{
	int data;
	Node *left, *right;
};
*/
// your task is tp complete this function
// function should return the length of the longestConsecutive
// sequence

int lcUtil(Node* root, int &maxlc) {
    if(root == NULL)
        return 0;
    /*if(!root->left && !root->right) {
        return 1;
    }*/
    
    int rlen = 1, llen = 1;
    
    if(root->left) {
        int l = lcUtil(root->left, maxlc);
        if((root->data + 1) == root->left->data) {
            llen = l + 1;
        }
        maxlc = max(maxlc, llen);
    }
    if(root->right) {
        int r = lcUtil(root->right, maxlc);
        if((root->data + 1) == root->right->data) {
            rlen = r + 1;
        }
        maxlc = max(maxlc, rlen);
    }
    
    /*if(llen < 0 && rlen < 0) {
        return -1;
    }*/
    return max(llen, rlen);
}

int longestConsecutive(Node* root)
{
     //Code here
     int maxlc = -1;
     lcUtil(root, maxlc);
     return (maxlc == 1)? -1 : maxlc;
}