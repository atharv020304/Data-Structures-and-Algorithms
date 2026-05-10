#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    int height;
    struct node *left, *right;
};

int maxFun(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}

int getBalance(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return (height(root->left) - height(root->right));
    }
}

struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
    x->right = y;
    y->left = T2;

    x->height = 1 + maxFun(height(x->left), height(x->right));
    y->height = 1 + maxFun(height(y->left), height(y->right));

    return x;
}
struct node *leftRotate(struct node *y)
{
    struct node *x = y->right;
    struct node *T2 = x->left;
    x->left = y;
    y->right = T2;

    x->height = 1 + maxFun(height(x->left), height(x->right));
    y->height = 1 + maxFun(height(y->left), height(y->right));

    return x;
}

struct node *insert(struct node *root, int key)
{
    if (root == NULL)
    {
        root = (struct node *)malloc(sizeof(struct node));
        root->data = key;
        root->height = 1;
        root->left = root->right = NULL;
        return root;
    }
    else if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + maxFun(height(root->left), height(root->right));
    int balance = getBalance(root);

    if (balance > 1 && key < root->left->data)
    {
        return (rightRotate(root));
    }

    if (balance < -1 && key > root->right->data)
    {
        return (leftRotate(root));
    }

    if (balance > 1 && key > root->left->data)
    {
        root->left = leftRotate(root->left);
        return (rightRotate(root));
    }

    if (balance < -1 && key < root->right->data)
    {
        root->right = rightRotate(root->right);
        return (leftRotate(root));
    }

    return root;
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void main()
{
    int n;
    struct node *root = NULL;
    printf("Enter number of node in tree : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int key;
        printf("Enter key : ");
        scanf("%d", &key);
        root = insert(root, key);
    }
    printf("\nAVL Tree : \n");
    inOrder(root);
}
