#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node() {}

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public: 
    Queue();
    int isEmpty();
    int isFull();
    void enqueue(int data);
    int dequeue();
    int size();
    void display();
};

Queue :: Queue()
{
    this->rear = NULL;
    this->front = NULL;
}

int Queue ::isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue ::isFull()
{
    Node *newNode = new Node;
    if (newNode == NULL)
    { 
        return 1;
    }
    delete newNode;
    return 0; 
}

void Queue ::enqueue(int data)
{

    if (isFull())
    {
        cout << "Enqueue Failed !! Queue is Full" << endl;
        return;
    }
    else if (isEmpty())
    {
        Node *newNode = new Node(data);
        front = newNode;
        rear = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        rear->next = newNode;
        rear = newNode;
    }
}

int Queue ::dequeue()
{
    int data;
    Node *temp = front;
    if (isEmpty())
    {
        return -1;
    }

    //if there is only one node.
    else if (front == rear)
    {
        data = front->data;
        front = NULL;
        rear = NULL;
        return data;
    }
    else
    {
        data = front->data;
        front = front->next;
    }
    delete temp;
    return data; 
}

int Queue ::size()
{
    int size = 0;
    Node *temp = front;
    while (temp != NULL)
    {
        size++;
        temp = temp->next;
    }
    return size;   
}

void Queue ::display()
{
    Node *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;  
}

int main()
{
    Queue queue;
    return 0;
}