// Question - http://www.geeksforgeeks.org/find-distance-two-given-nodes/
/*
Please note that it's Function problem i.e.
you need to write your solution in the form Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

bool findDist(Node *root, int a, int b, int &depth, int &dist) {
    if(root == NULL) return false;
    int ld=0, rd=0;
    bool left = findDist(root->left, a, b, ld, dist);
    bool right = findDist(root->right, a, b, rd, dist);
    //cout << root->data << " " << left << " " << right << endl;
    //if reached common ancestor
    if((left && right) || ((left || right) && (root->data == a || root->data == b))) {
        dist = ld + rd;
        return false;
    }
    //two nodes are same
    if(root->data == a && root->data == b) {
        dist = 0;
        return false;
    }
    
    if(root->data == a || root->data == b) {
        depth = 1;
        return true;
    }
    else if(left)
        depth = ld + 1;
    else if(right)
        depth = rd + 1;
    
    return left || right;
}

/* Should return minimum distance between a and b 
   in a tree with given root*/
int findDist(Node* root, int a, int b)
{
    // Your code here 
    int d, dist = -1;
    findDist(root, a, b, d, dist);
    return dist;
}
