#include<iostream>
using namespace std;

class Stack
{
    int size;
    int top;
    int* arr;

public:

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
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
    if(top == -1)
    {
        return 1;
    }
    return 0;    
}

int Stack :: isFull()
{
    if(top == (size-1))
    {
        return 1;
    }

    return 0;
}

void Stack :: push(int data)
{
    if(isFull())
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    top++;
    arr[top] = data;
    return;
}

int Stack :: pop()
{
    if (isEmpty())
    {
        return 0;
    }
    int data = arr[top];
    top--;
    return data;
}

int Stack :: peek(int location)
{
    if (location <= 0 || location > top)
    {
       return 0;
    }
    
    else
    {
        return arr[location-1];
    }
}

int Stack :: stackTop()
{
    if(isEmpty())
    {
        return 0;
    }
    else
    {
        return arr[top];
    }
}

int Stack :: stackBottom()
{
    if(isEmpty())
    {
        return 0;
    }

    else
    {
        return arr[0];
    }
}

void Stack :: display()
{
    for(int i = 0; i<=top; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    Stack s1(10);

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);
    s1.push(60);

    s1.display();

    cout<<s1.pop()<<endl;
    s1.display();

    cout<<s1.peek(3)<<endl;

    
    cout<<s1.stackTop()<<endl;
    cout<<s1.stackBottom()<<endl;


    return 0;
}