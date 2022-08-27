#include<stdio.h>
#include<stdlib.h>
#include <time.h>
struct BST {
	int data;
	struct BST* left;
	struct BST* right;
};
struct BST* SearchBST(struct BST* root,int key) {//二叉树的查找
	if (root==NULL||root->data==key) {
		return root;
	}
	return root->data < key ? SearchBST (root->left,key): SearchBST(root->right, key);
}
void InsertBST(struct BST** root, int key) {
	if ((*root)==NULL) {
		struct BST* tmp=malloc(sizeof(struct BST));
		tmp->left = NULL;
		tmp->right = NULL;
		tmp->data = key;
		*root = tmp;
		return;
	}
	struct BST* ps = *root;
	struct BST* pp = NULL;
	while (ps !=NULL) {
		pp = ps;
		if (ps->data==key) {
			return;
		}
		else if (ps->data<key) {
			ps = ps->right;
			if (ps==NULL) {
				struct BST* tmp = malloc(sizeof(struct BST));
				tmp->left = NULL;
				tmp->right = NULL;
				tmp->data = key;
				pp->right = tmp;
			}
		}
		else {
			ps = ps->left;
			if (ps == NULL) {
				struct BST* tmp = malloc(sizeof(struct BST));
				tmp->left = NULL;
				tmp->right = NULL;
				tmp->data = key;
				pp->left = tmp;
			}
		}
	}
}
void Traversal(struct BST* root) {
	if (root==NULL) {
		return;
	}
	Traversal(root->left);
	printf("%d->", root->data);
	Traversal(root->right);
}
void DeleteBST(struct BST** root,int key) {
	if (root==NULL||&(*root)==NULL) {
		return;
	}
	struct BST* prev=*root,*cur=*root,*pp=NULL,*ps=NULL;
	while (cur) {
		if (cur->data==key) {
			break;
		}
		else if (cur->data < key) {
			prev = cur;
			cur = cur->right;
		}
		else {
			prev = cur;
			cur = cur->left;
		}
	}//三种情况
	if (!cur) {
		return;
	}
	else {
		pp = cur;
		if (cur->left&&cur->right) {
			pp = pp->left;
			while (pp&&pp->right) {
				ps = pp;
				pp=pp->right;
			}
			if (ps!=NULL) {
				ps->right = pp->left;
			}
			pp->right=cur->right;
			if (cur->left!=pp) {
				pp->left = cur->left;
			}
			if (cur==*root) {
				*root = pp;
			}
			else if (prev->left==cur) {
				prev->left = pp;
			}
			else {
				prev->right = pp;
			}
		}
		else if (cur->left) {
			pp = pp->left;
			if (cur == *root) {
				*root = pp;
			}
			else if (prev->left == cur) {
				prev->left = pp;
			}
			else {
				prev->right = pp;
			}
		}
		else {
			pp = pp->right;
			if (cur == *root) {
				*root = pp;
			}
			else if (prev->left == cur) {
				prev->left = pp;
			}
			else {
				prev->right = pp;
			}
		}
	}
}
//int main() {
//	struct BST* root = NULL;
//	srand((unsigned)time(NULL));
//	int k = 0;
//	int i = 0;
//	for (i = 0; i < 100;i++) {
//		k = rand()%200;
//		InsertBST(&root, k);
//	}
//	Traversal(root);
//	return 0;
//}
int main() {
	srand((unsigned)time(NULL));
	struct BST* root = NULL;
	int i = 0,k=0;
	int arr[] = {2, 4,19,7,8,9,10,17,18,11,12,13,1,2,3,4,5,6,14,15,16,17,18 };
	for (i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		InsertBST(&root, arr[i]);
	}
	Traversal(root);
	printf("\n");
 	DeleteBST(&root,6);

	Traversal(root);
	return 0;
 }