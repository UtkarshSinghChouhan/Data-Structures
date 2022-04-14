#include<iostream>
using namespace std;


//A class to create a node of the Linked-list.
class Node
{
public:
    Node* previous;
    int data;       //represents the 'data' of a node.
    Node* next;     //reprents the 'link' that a node

    Node(int data)          //Constructor to initialize the data-members of the node.
    {
        this->previous = NULL;
        this->data = data;
        this->next = NULL;
    }
};


//A class to implement the operations on Linked-List
class DoublyLinkedList
{
    Node* head;         //represents the head of the linked-list.
public:    
    DoublyLinkedList()         //Constructor to initialize the head of the linked-list.
    {
        this->head = NULL;
    }

    ~DoublyLinkedList()
    {
        Node* temp;
        while(head != NULL)
        {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
    void insertAtEnd(int data);
    void insertAtBeg(int data);
    void insertAfterNode(int data, int location);
    int deleteFirstNode();    
    int deleteLastNode();    
    int deleteSpecificNode(int data);

    void display();    
    int size();                     //returns number of nodes in the linked-list.
};

void DoublyLinkedList :: insertAtEnd(int data)
{

    //Condition-01 : If the List is empty create first node.
    if(head==NULL)
    {
        Node* newNode = new Node(data);     //Creating a pointer 'newNode' pointing to nameless object containing data-member 'data'.
        head = newNode;
        return;
    }

    //Condition-02 : If is not empty.
    else
    {
        Node* temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        //add node at the end.
        Node* newNode = new Node(data);
        temp->next = newNode;
        newNode->previous = temp;
        return;
    }

}

void DoublyLinkedList :: insertAtBeg(int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    newNode->next->previous = newNode;
    head = newNode;
}

int DoublyLinkedList :: size()
{
    Node* temp = head;
    int size = 0;
    while(temp!=NULL)
    {
        temp = temp->next;
        size++;
    }

    return size;
    }

void DoublyLinkedList :: insertAfterNode(int data, int location)       //Insert a node in the linked-list at a given 'location'
{    

    //Condition-01 : Checks weather the 'location' provided actually exists in the linked-list or not.
    if(location <=0 ) 
    {
        cout<<"Insertion failed !! Location out of bound"<<endl;
        return;
    }

    //Condition-02 : Checks weather the 'location' provided actually exists in the linked-list or not.
    // if(location > size())
    // {
    //     cout<<"Insertion failed !! Location out of bound"<<endl;
    //     return;
    // }

    Node* newNode = new Node(data);
    Node* temp = head; 

    //If the 'location' provided exists in the linked-list then below mechanism insert the node after the given 'location'.
    //traverse to the node at the given location.
    for(int i = 1; i<location; i++)
    {
        temp = temp->next;

        //if end of the linked list is encountered.
        if(temp == NULL)
        {
            cout<<"Insertion failed !! Location out of bound"<<endl;
            return;
        }
    }

    newNode->next  = temp->next;
    temp->next = newNode;
    newNode->previous = temp;
    newNode->next->previous = newNode;
}

void DoublyLinkedList :: display()
{
    Node* temp = head;

    //prints the linked list in forward order.
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    //prints the linked list in the reverse order.
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->previous;
    }
    cout<<endl;
}

int DoublyLinkedList :: deleteFirstNode()
{
    //if the linked list is empty.
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp = head;

        //if the linked list consists of only one node.
        if(temp->next == NULL)
        {
            head = temp->next;
        }

        //delete the first node.
        else
        {
            head = temp->next;
            head->previous = NULL;
        }

        // free the memory occupied by the node.
        delete temp;
        return 1;
    }
}

int DoublyLinkedList :: deleteLastNode()
{
    //if the linked list is empty.
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp = head;

        //if the linked list consists of only one node.
        if(temp->next == NULL && temp->previous == NULL)
        {
            head = NULL;
        }

        else
        {
        //traverse to the last node.
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->previous->next = NULL;

        }
        delete temp;
        return 1;
    }
}

int DoublyLinkedList :: deleteSpecificNode(int data)
{
    Node* temp = head;

    //traverse the entire linked-list.
    while(temp->next != NULL)
    {
        //if node to be deleted is found.
        if(temp->data == data)
        {
            //if node to be deleted is the first node.
            if(temp->previous == NULL)
            {
                //if node to be deleted(first node) is the only node.
                if(temp->next == NULL)
                {
                    head = NULL;
                }

                //delete the first node.
                else
                {
                    head = temp->next;
                    temp->next->previous = NULL;
                }
            }

            else
            {
                //if the node to be deleted is the last node.
                if(temp->next == NULL)
                {
                    temp->previous->next = NULL;
                }

                //if the node to be deleted is the intermediate node.
                else
                {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;
                }
            }
            delete temp;
            return 1;
        }
        temp = temp->next;

    }
    return -1;
}



int main()
{
    DoublyLinkedList l1;

    l1.insertAtEnd(10);
    l1.insertAtEnd(20);
    l1.insertAtEnd(30);
    l1.insertAtEnd(40);
   
    cout<<"Elements in the linked-list are : ",
    l1.display();

    cout<<"Elements in the linked-list after insertions at the beginning are : ",
    l1.insertAtBeg(2);
    l1.display();

    cout<<"Elements in the linked-list after insertions at the end are : ",
    l1.insertAtEnd(6);
    l1.display();


    cout<<"Elements in the linked-list after insertions after a given location are : ",
    l1.insertAfterNode(35,2);
    l1.display();


    l1.insertAfterNode(35,0);
    l1.insertAfterNode(35,-1);
    l1.insertAfterNode(35,10);

    l1.display();

    cout<<l1.deleteFirstNode()<<endl;;
    cout<<l1.deleteLastNode()<<endl;;
    cout<<l1.deleteSpecificNode(100)<<endl;;

    l1.display();

    return 0;
}