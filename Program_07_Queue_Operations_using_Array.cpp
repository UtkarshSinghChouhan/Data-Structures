#include<iostream>
using namespace std;

class Queue
{
     int size;
    int* arr;
    int front;
    int rear;
public:
    Queue(int size)
    {
        this->size = size;
        //this is a special syntax which will initialize every element of the array with zero otherwise it will contain garbage value instead.
        this->arr = new int[size]();
        this->front = -1;
        this->rear = -1;
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
    if(rear == (size-1))
    {
        return 1;
    }
    return 0;
}

int Queue :: isEmpty()
{
    if(front == -1 && rear == -1)
    {
        return 1;
    }
    return 0;
}

void Queue :: enQueue(int data)
{
    if(isFull())
    {
        cout<<"Insertion Failed!!...Queue is full"<<endl;
        return;
    }

    else if(isEmpty())
    {
        rear = 0;
        front = 0;        
    }

    else
    {
        rear++;        
    }

    arr[rear] = data;
}

int Queue :: deQueue()
{
    int data;
    if(isEmpty())
    {
        return 0;
    }

    //if there is only one element in the Queue.
    else if(rear == front)
    {
        data = arr[front];
        arr[front] = 0;
        front = -1;
        rear = -1;
    }

    else
    {
        data = arr[front];
        arr[front] = 0;
        front++;
    }
    return data;
}

int Queue :: count()
{
    return (rear - front + 1);
}

void Queue :: display()
{
    for(int i = 0; i < size; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
   Queue q1(6);

    cout<<q1.isEmpty()<<endl;
    cout<<q1.isFull()<<endl;
    
   q1.enQueue(10);
   q1.enQueue(20);
   q1.enQueue(30);
   q1.enQueue(40);
   q1.enQueue(50);

   q1.display();

   cout<<q1.isEmpty()<<endl;
   cout<<q1.isFull()<<endl;
    

   cout<<q1.deQueue()<<endl;
   q1.display();

    cout<<q1.count()<<endl;

    return 0;
}