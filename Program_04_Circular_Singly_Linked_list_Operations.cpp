#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class CircularLinkedList
{
    Node* head;
public:

    CircularLinkedList()
    {
        this->head = NULL;
    }
    void insertAtBeg(int data);
    void insertAtEnd(int data);
    void insertAfterNode(int data, int location);
    int deleteFirstNode();
    int deleteLastNode();
    int deleteSpecificNode(int data);

    int size();
    void display();
};

void CircularLinkedList :: insertAtBeg(int data)
{
    Node* newNode = new Node(data);

    //if the linked lsit is empty.
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head; 
    }

    else
    {
        Node* temp = head;
        while(temp->next != head)
        {
            temp = temp->next;
        }
        
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void CircularLinkedList :: insertAtEnd(int data)
{
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        newNode->next = head;
    }

    else
    {
        Node* temp = head;
        //traverse to the last node
        while (temp->next != head)
        {
           temp = temp->next;
        }

        //add node at the end.
        Node* newNode = new Node(data);
        temp->next = newNode;
        newNode->next = head;
        return;        
    }
}

void CircularLinkedList :: insertAfterNode(int data, int location)
{
    Node* temp = head;

    //traverse to the given location
    for(int i = 1; i<location; i++)
    {
        temp = temp->next;

        if(temp == head)
        {
            cout<<"Insertion Failed!!!...Location out of bound"<<endl;
            return;
        }
    }

    //insert a new node after the node at the given location.
    Node* newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

int CircularLinkedList :: deleteFirstNode()
{
    //if the linked list is empty.
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp2 = head;
        //if the linked list  consists of only one node.
        if(temp2->next == head)
        {
            head = NULL;
        }

        else
        {
            Node* temp1 = head;
            //traverse to the last node.
            while (temp2->next != head)
            {
                temp2 = temp2->next;
            }
            temp2->next = head->next;
            head = head->next;            
        }
        delete temp2;
        return 1;
    }
}

int CircularLinkedList :: deleteLastNode()
{
    //if the linked list is empty.
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp2 = head;
        //if the linked list contains only one node.
        if(head->next == head)
        {
            head = NULL;
        }

        else
        {
            Node* temp1;          
            //traverse to the last node.
            while (temp2->next != head)
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }
            temp1->next = temp2->next;                       
        }
        delete temp2;
        return 1;
    }
}

int CircularLinkedList :: deleteSpecificNode(int data)
{
    //if the linked list is empty
    if(head == NULL)
    {
        return -1;
    }
    
    Node* temp1;
    Node* temp2 = head;
    //traverse the entire linked list.
    do
    {
       
    } while (temp2 != head);
    
}

int CircularLinkedList :: size()
{
    int size = 0;

    //if the linked list if empty.
    if(head == NULL)
    {
        return size;
    }

    Node* temp = head;
    //traverse the entire linked list.
   do
    {
        temp =temp->next;
        size++;
    } while(temp->next != head);
    return size;
}

void CircularLinkedList :: display()
{
    //if the linked list is empty.
    if(head == NULL)
    {
        return;
    }

    Node* temp = head;
    do
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    } while (temp != head);    
}


int main()
{
    
    return 0;
}