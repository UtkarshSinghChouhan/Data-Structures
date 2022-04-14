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
    int peek(int location);
    int stackTop();
    int stackBottom();

    void display();

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

int Stack :: peek(int location)
{
    if(location <= 0)
    {
        return -1;
    }

    
        Node* temp = top;

        for(int i = 0; i<(location-1); i++)
        {
            //if the Stack is Empty or if the location doesn't exists.
            if(temp == NULL)
            {
                return -1;
            }
            temp = temp->next;
        }

        return temp->data;
    
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

int Stack :: stackBottom()
{
    if(isEmpty())
    {
        return -1;
    }

    else
    {
        Node* temp = top;
        while(temp->next != NULL)
        {
            temp = temp->next;            
        }

        return temp->data;
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

int main()
{
    Stack s;

    cout<<s.isEmpty()<<endl;

    s.push(10);    
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.display();

    s.pop();
    s.display();

    cout<<s.stackTop()<<endl;
    cout<<s.stackBottom()<<endl;

    return 0;
}