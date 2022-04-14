#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorderTraversal(Node *root)
{
    //Base Condition
    if(root == NULL)
        return;

    //Induction step
    cout<<root->data<<" ";

    //Hypothesis Step(For smaller Input)
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    //Base Condition
    if(root == NULL)
        return;


    //Hypothesis Step(For smaller Input)
    postorderTraversal(root->left);
    postorderTraversal(root->right);

    //Induction step
    cout<<root->data<<" ";
}

void inorderTraversal(Node *root)
{
    //Base Condition
    if(root == NULL)
        return;


    //Hypothesis Step(For smaller Input)
    inorderTraversal(root->left);

    //Induction step
    cout<<root->data<<" ";

    //Hypothesis Step (For smaller input)
    inorderTraversal(root->right);
}



int main()
{
    //Creating Some free nodes;
    Node *p = new Node(4);
    Node *p1 = new Node(1);
    Node *p2 = new Node(6);
    Node *p3 = new Node(5);
    Node *p4 = new Node(2);

    //Linking abive created free node to form a tree;
    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    //Finally the tree looks like this;
    //                4
    //               / \
    //              1   6
    //             / \
    //            5   2     


    //Pre-Order Traversal (Root --> Left_subtree --> Right_subtree);
    preorderTraversal(p);
    cout<<endl;

    //Post-Order Traversal  (Left_subtree --> Right_subtree --> Root);
    postorderTraversal(p);
    cout<<endl;
    
    //In-Order Traversal (Left_subtree --> Root --> Right_subtree);
    inorderTraversal(p);

    return 0;
}