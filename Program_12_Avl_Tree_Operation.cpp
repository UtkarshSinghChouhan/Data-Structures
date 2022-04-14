#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
        this->height = 1;
    }
};

int max(int a, int b)
{
    return a > b ? a : b;
}

int getHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return root->height;
}

int getBalanceFactor(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeight(root->left) - getHeight(root->right);
}
//      y                         x
//     / \    Rignt Rotate       / \
//    x   T3      --->         T1   y 
//   / \                           / \
// T1   T2                       T2   T3

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

//    x                          y 
//   / \                        / \ 
// T1   y      Left Rotate    x   T3
//     / \        --->        / \   
//   T2   T3                T1   T2

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return new Node(data);
    }

    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int bf = getBalanceFactor(root);

    // Left Left Case
    if (bf > 1 && data < root->left->data)
    {
        return rightRotate(root);
    }

    // Right Right Case
    if (bf < -1 && data > root->right->data)
    {
        return leftRotate(root);
    }

    // Left Right Case
    if (bf > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (bf < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}


void inorderTraversal(Node *root)
{
    // Base Condition
    if (root == NULL)
        return;

    // Hypothesis Step(For smaller Input)
    inorderTraversal(root->left);

    // Induction step
    cout << root->data << " ";

    // Hypothesis Step (For smaller input)
    inorderTraversal(root->right);
    return;
}

int main()
{
    Node * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorderTraversal(root);
    cout<<endl;
    inorderTraversal(root);

    return 0;
}