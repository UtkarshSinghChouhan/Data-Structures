#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorderTraversal(Node *root)
{
    // Base Condition
    if (root == NULL)
        return;

    // Induction step
    cout << root->data << " ";

    // Hypothesis Step(For smaller Input)
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    // Base Condition
    if (root == NULL)
        return;

    // Hypothesis Step(For smaller Input)
    postorderTraversal(root->left);
    postorderTraversal(root->right);

    // Induction step
    cout << root->data << " ";
}

void inorderTraversal(Node *root)
{
    // Base Condition
    if (root == NULL)
    {
        return;

    }

    // Hypothesis Step(For smaller Input)
    inorderTraversal(root->left);

    // Induction step
    cout << root->data << " ";

    // Hypothesis Step (For smaller input)
    inorderTraversal(root->right);
}

int isBST(Node *root)
{
    if (root == NULL)
    {
        return 1;
    }

    // Induction Step
    if (root->left != NULL && root->left->data >= root->data)
    {
        return 0;
    }

    if (root->right != NULL && root->right->data <= root->data)
    {
        return 0;
    }

    // Hypothesis Step
    int left_subtree = isBST(root->left);
    int right_subtree = isBST(root->right);

    return left_subtree && right_subtree;
}

Node *searchRecursive(Node *root, int data)
{

    // Base Condition
    if (root == NULL)
        return NULL;

    // Induction Step
    if (root->data == data)
    {
        return root;
    }

    // Hypothesis Step
    if (root->data > data)
    {
        return searchRecursive(root->left, data);
    }
    else
    {
        return searchRecursive(root->right, data);
    }
}

Node *searchIterative(Node *root, int data)
{
    while (root != NULL)
    {
        if (data == root->data)
        {
            return root;
        }

        else if (data > root->data)
        {
            root = root->left;
        }

        else
        {
            root = root->right;
        }
    }

    return NULL;
}

void insert(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return;
    }
    Node *pre = NULL;

    //searching iteratively
    while (root != NULL)
    {
        pre = root;
        if (data == root->data)
        {
            cout << "Cannont Insert the dataue " << data << ", as it already exixts in the tree.";
            return;
        }

        if (data < root->data)
        {            
            root = root->left;
        }

        else
        {            
            root = root->right;
        }
    }

    Node *newNode = new Node(data);
    if (data < pre->data)
    {
        pre->left = newNode;
    }

    else
    {
        pre->right = newNode;
    }
}


Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }

    else
    {
        //if the tree consists of only single node.
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        //if the tree is right skewed.
        else if (!root->left && root->right)
        {
            Node *node = root->right;
            root->right = NULL;
            delete root;
            return node;
        }

        //if the tree is left skewed.
        else if (!root->right && root->left)
        {
            Node *node = root->left;
            root->left = NULL;
            delete root;
            return node;
        }

        else
        {
            //To find the maximum node in the left sub_tree.
            Node*  maxNode = root->left;
            while(maxNode->right != NULL)
            {
                maxNode = maxNode->right;
            }


            
            root->data = maxNode->data;
            root->left = deleteNode(root->left, maxNode->data);
        }
    }

    return root;
}

int main()
{
    // Creating Some free nodes;
    Node *p = new Node(5);
    Node *p1 = new Node(3);
    Node *p2 = new Node(6);
    Node *p3 = new Node(2);
    Node *p4 = new Node(4);

    Node *p10 = new Node(8);

    // Linking above created free node to form a tree;
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    p2->right = p10;

    // Finally the tree looks like this;
    //                5(p)
    //                /    \
    //             3(p1)   6(p2)
    //            /   \
    //       2(p3)    4(p4)

    // Pre-Order Traversal (Root --> Left_subtree --> Right_subtree);
    preorderTraversal(p);
    cout << endl;

    // Post-Order Traversal  (Left_subtree --> Right_subtree --> Root);
    postorderTraversal(p);
    cout << endl;

    // In-Order Traversal (Left_subtree --> Root --> Right_subtree);
    inorderTraversal(p);
    cout << endl;

    cout << isBST(p);
    cout << endl;

    Node *datauePointer1 = searchRecursive(p, 7);
    if (datauePointer1 == NULL)
    {
        cout << "dataue doesnot exists in the tree!!" << endl;
    }

    else
    {
        cout << datauePointer1->data;
    }

    Node *datauePointer2 = searchIterative(p, 7);
    if (datauePointer2 == NULL)
    {
        cout << "dataue doesnot exists in the tree!!" << endl;
    }

    else
    {
        cout << datauePointer2->data;
    }

    inorderTraversal(p);
    cout << endl;

    deleteNode(p, 6);

    inorderTraversal(p);
    cout << endl;

    return 0;
}