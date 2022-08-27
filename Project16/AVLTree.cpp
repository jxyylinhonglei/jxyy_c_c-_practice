typedef struct AVLNode {
	int data;
	int height;
	struct AVLNode* left;
	struct AVLNode* right;
}*AVLTree;
int Height(AVLTree T) {//计算高度
	if (!T) {
		return 0;
	}
	return T->height;
}
void updateHeight(AVLTree &T) {//更新高度
	if (!T) {
		return;
	}
	T->height = Height(T->left) > Height(T->right) ? Height(T->left)+1 : Height(T->right)+1;
}
AVLTree LL_Rotation(AVLTree& T) {
	AVLTree newRoot = T->left;
	T->left = newRoot->right;
	newRoot->right = T;
	updateHeight(T);
	updateHeight(newRoot);
	return newRoot;
}
AVLTree RR_Rotation(AVLTree& T) {
	AVLTree newRoot = T->right;
	T->right = newRoot->left;
	newRoot->left = T;
	updateHeight(T);
	updateHeight(newRoot);
	return newRoot;
}
AVLTree LR_Rotation(AVLTree& T) {
	T->left = RR_Rotation(T->left);
	return LL_Rotation(T);
}
AVLTree RL_Rotation(AVLTree& T) {
	T->right = LL_Rotation(T->right);
	return RR_Rotation(T);
	T->right = LL_Rotation(T->right);
	return RR_Rotation(T->right);
}
void adjust(AVLTree& T) {
	if (!T) {
		return;
	}
	if (Height(T->left)-Height(T->right)>1) {//左子树高
		if (Height(T->left->left)>= Height(T->left->right)) {
			T = LL_Rotation(T);
		}
		else
		{
			T = LR_Rotation(T);
		}
	}
	else if (Height(T->right) - Height(T->left) > 1) {//右子树高
		if (Height(T->right->right) >= Height(T->right->left)) {
			T = RR_Rotation(T);
		}
		else
		{
			T = RL_Rotation(T);
		}
	}
}