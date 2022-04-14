#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;
    Node () {};

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node* front;
    Node* rear;
public:

    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    int isFull();
    int isEmpty();
    void enQueue(int data);
    int deQueue();
    int count();

    void display();
};

int Queue :: isFull()
{
    Node* newNode = new Node;
    if(newNode == NULL)
    {
        return 1;
    }
    delete newNode;
    return 0;
}

int Queue :: isEmpty()
{
    if(front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}

void Queue :: enQueue(int data)
{

    if(isFull())
    {
        cout<<"Enqueue Failed!!!...Queue is Full"<<endl;
        return;
    }

    else if(isEmpty())
    {
        Node* newNode = new Node(data);
        rear->next = newNode;
        rear = newNode;
        front = newNode;
    }

    else
    {
        Node* newNode = new Node(data);
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue :: deQueue()
{
    int data;
    Node* temp = front;

    if(isEmpty())
    {
        return 0;
    }

    //if there is only one node.
    else if(front == rear)
    {
        data = front->data;
        front = NULL;
        rear = NULL;
    }

    else
    {
        data = front->data;
        front = front->next;
    }

    delete temp;
}

int Queue :: count()
{
    int size;
    Node* temp = front;
    
    
}



int main()
{
    
    return 0;
}