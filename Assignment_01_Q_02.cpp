#include <iostream>
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

bool isPrime(int num)
{
    // 0 and 1 are not prime numbers
    if (num == 0 || num == 1)
    {
        return false;
    }

    // loop to check if num is prime
    for (int i = 2; i <= num / 2; ++i)
    {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

class Stack
{
    Node *top;

public:
    Stack();
    int isEmpty();
    int isFull();
    void push(int data);
    int pop();
    void display();
    void displayPrimeOccurrences();
};

Stack ::Stack()
{
    this->top = NULL;
}

int Stack ::isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

int Stack ::isFull()
{
    Node *newNode = new Node;
    if (newNode == NULL)
    {
        return 1;
    }
    delete newNode;
    return 0;
}

void Stack ::push(int data)
{
    if (isFull())
    {
        cout << "Stack Overflow" << endl;
        return;
    }

    Node *newNode = new Node(data);
    newNode->next = top;
    top = newNode;
}

int Stack ::pop()
{
    if (isEmpty())
    {
        return -1;
    }
    else
    {
        int data = top->data;
        Node *temp = top;

        top = top->next;

        delete temp;
        return data;
    }
}

void Stack ::display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Stack ::displayPrimeOccurrences()
{
    if (isEmpty())
    {
        return;
    }

    int temp = pop();
    if (isPrime(temp))
    {
        cout << temp << " ";
    }

    displayPrimeOccurrences();
    push(temp);
}



int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.display();
    s.displayPrimeOccurrences();
    return 0;
}