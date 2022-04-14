#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(){}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Stack
{
    Node* top;
public:

    
    Stack()
    {
        top = NULL;
    }

    int isEmpty();
    int isFull();
    void push(int data);
    int pop(); 
    int stackTop();

    void display();
    void displayReverse();

};

int Stack :: isEmpty()
{
    if(top == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack :: isFull()
{
    Node* newNode = new Node;
    if(newNode == NULL)
    {
        return 1;
    }
    delete newNode;
    return 0;
}

void Stack :: push(int data)
{
    if(isFull())
    {
        cout<<"Stack overflow !!!"<<endl;
    }
    
    Node* newNode = new Node(data);        
    newNode->next = top;
    top = newNode;
    
}

int Stack :: pop()
{
    if(isEmpty())
    {
        return -1;
    }

    else
    {
        int data = top->data;
        Node* temp = top;

        top = top->next;

        delete temp;
        return data;
    }
}

int Stack :: stackTop()
{
    if(isEmpty())
    {
        return -1;
    }

    else
    {
        return top->data;
    }
}


void Stack :: display()
{
  
    Node* temp = top;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    
}

void Stack :: displayReverse()
{
    if(isEmpty())
    {
        return;
    }

    int x = stackTop();

    pop();

    displayReverse();

    cout<<x<<" ";

    push(x);
}

int main()
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();

    s.displayReverse();
   

    return 0;
}