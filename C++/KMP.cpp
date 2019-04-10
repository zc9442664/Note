#include<iostream>
using namespace std;

struct Tree {
	int value;
	Tree *left;
	Tree *right;
	Tree(int value) {
		this->value = value;
		this->left = left;
		this->right = right;
	}
};
void createTree(Tree **root,int value) {
	Tree *node = (Tree*)malloc(sizeof(Tree));
	node->value = value;
	if (root == NULL) {
		*root = node;
		printf("%d\n", (*root)->value);
	}
	else {
		Tree *temp = *root;
		while (temp != NULL) {
			if (value < temp->value) {
				if (temp->left == NULL) {
					temp->left = node;
					printf("%d\n", temp->left->value);
					return;
				}
				else {
					temp = temp->left;
				}
			}
			else {
				if (temp->right == NULL) {
					temp->right = node;
					printf("%d\n", temp->right->value);
					return;
				}
				else {
					temp = temp->right;
				}
			}
		}
	}
	return;
}
void inorder(Tree *root) {
	if (root != NULL) {
		inorder(root->left);
		printf("%d ", root->value);
		inorder(root->right);
	}
}
int main() {
	int a[10] = { 5,2,0,3,1,6,4,7,8,9 };
	int len = (sizeof(a) / sizeof(int));
	Tree *root;
	for (int i = 0; i < len; i++) {
		createTree(&root, a[i]);
	}
	inorder(root);

	return 0;
}