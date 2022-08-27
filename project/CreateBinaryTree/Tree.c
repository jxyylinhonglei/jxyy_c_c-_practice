#include<stdio.h>
#include<stdlib.h>
struct BinaryTree
{
    char data;
    struct BinaryTree* leftchild;
    struct BinaryTree* rightchild;
};
struct BinaryTree* test(char* arr, int* i)
{
    if (arr[*i] == '#')
    {
        (*i)++;
        return NULL;
    }
    else
    {
        struct BinaryTree* tmp = (struct BinaryTree*)malloc(sizeof(struct BinaryTree));
        tmp->data = arr[*i];
        (*i)++;
        tmp->leftchild = test(arr, i);
        tmp->rightchild = test(arr, i);
        return tmp;
    }
}
void InOrder(struct BinaryTree* root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        InOrder(root->leftchild);
        printf("%c ", root->data);
        InOrder(root->rightchild);
    }
}
int main()
{
    char arr[100];
    scanf("%s", arr);
    int i = 0;
    struct BinaryTree* root = test(arr, &i);
    InOrder(root);
    return 0;
}