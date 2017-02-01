/* A binary tree node has data, pointer to left child
   and a pointer to right child 
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

int treeHeight(Node *root)
{
    if(root == NULL)
        return 0;
    return max(1 + treeHeight(root->left), 1 + treeHeight(root->right));
}

void printFirstNodeAtLevel(Node *root, int curr, int level, int *found)
{
    if(root == NULL)
        return;
    if(curr == level)
    {
        cout << root->data << " ";
        *found = 1;
    }
    printFirstNodeAtLevel(root->right, curr+1, level, found);
    if(*found == 0)
        printFirstNodeAtLevel(root->left, curr+1, level, found);
}

// Should print right view of tree
void rightView(Node *root)
{
   // Your Code here
   int height = treeHeight(root);
   for(int i=0; i<height; i++)
   {
       int found = 0;
       printFirstNodeAtLevel(root, 0, i, &found);
   }
   //cout << endl;
}