#include<iostream>
using namespace std;
typedef struct node node;
struct node {
	int val;
	node *left, *right;
	node(int v):val(v), left(NULL), right(NULL) {}
};

void turn_binary_tree(node *root, node* &new_root) {
	if(root == NULL)
		return ;
	turn_binary_tree(root->left, new_root);
	//turn_binary_tree(root->right, new_root);
	if(root->left==NULL && new_root==NULL)
		new_root = root;
	if(root->left) {
		root->left->left = root->right;
		root->left->right = root;
	}
	root->left = NULL;
	root->right = NULL;
}

void print(node *root) {
	if(root == NULL)
		return;
	cout << root->val << " ";
	print(root->left);
	print(root->right);
}

int main() {
	node *root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	node *nroot = NULL;
	print(root);
	cout << endl;
	turn_binary_tree(root, nroot);
	print(nroot);
	cout << endl;
	
	nroot = NULL;
	root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->right->left = new node(4);
	root->right->right = new node(5);
	print(root);
	cout << endl;
	turn_binary_tree(root, nroot);
	print(nroot);
}
