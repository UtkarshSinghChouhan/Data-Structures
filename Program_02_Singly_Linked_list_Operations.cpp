#include<iostream>
using namespace std;


//A class to create a node of the Linked-list.
class Node
{
public:
    int data;       //represents the 'data' of a node.
    Node* next;     //reprents the 'link' that a node

    Node(int data)          //Constructor to initialize the data-members of the node.
    {
        this->data = data;
        this->next = NULL;
    }
};


//A class to implement the operations on Linked-List
class SinglyLinkedList
{
    Node* head;         //represents the head of the linked-list.
public:    
    SinglyLinkedList()         //Constructor to initialize the head of the linked-list.
    {
        this->head = NULL;
    }

    ~SinglyLinkedList()
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

void SinglyLinkedList :: insertAtEnd(int data)
{
    Node* newNode = new Node(data);     //Creating a pointer 'newNode' pointing to nameless object containing data-member 'data'.

    //Condition-01 : If the List is empty create first node.
    if(head==NULL)
    {
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
        temp->next = newNode;
        return;
    }

}

void SinglyLinkedList :: insertAtBeg(int data)
{
    Node* newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

int SinglyLinkedList :: size()
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

void SinglyLinkedList :: insertAfterNode(int data, int location)       //Insert a node in the linked-list at a given 'location'
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
    
    for(int i = 1; i<location; i++)
    {
        temp = temp->next;

        //Condition-02 : Checks weather the 'location' provided actually exists in the linked-list or not.
        if(temp == NULL)
        {
            cout<<"Insertion failed !! Location out of bound"<<endl;
            return;
        }
    }

    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void SinglyLinkedList :: display()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int SinglyLinkedList :: deleteFirstNode()
{
    //if the linked list is empty
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp = head;
        
        //if the linked list contains only node.
        if(head->next == NULL)
        {
            head = NULL;
        }

        //otherwise delete the first node
        else
        {
            head = temp->next;            
        }
        delete temp;
        return 1;
    }
}

int SinglyLinkedList :: deleteLastNode()
{
    //if the linked list is empty
    if(head == NULL)
    {
        return -1;
    }

    else
    {
        Node* temp1;
        Node* temp2 = head;

        //if linked list contains only one node.
        if(head->next == NULL)
        {
            head = NULL;
        }

        else
        {
            //traverse to the last node
            while (temp2->next != NULL)
            {
                temp1 = temp2;
                temp2 = temp2->next;
            }
            temp1->next = NULL;            
        }

        delete temp2;
        return 1;
    }
}

int SinglyLinkedList :: deleteSpecificNode(int data)
{
    Node* temp1;
    Node* temp2 = head;


    while(temp2 != NULL)
    {
        //if the node to be deleted is encountered.
        if(temp2->data == data)
        {
            //if node to be deleted is the first node.
            if(temp2 == head)
            {
                head = temp2->next;
            }

            //if the node to be deleted is not the first node.
            else
            {
                temp1->next = temp2->next;
            }
            delete temp2;
            return 1;
        }

        else
        {
            temp1 = temp2;
            temp2 = temp2->next;
        }
    }

    //if node to be deleted is never encountered.
    return -1;
}



int main()
{
    SinglyLinkedList l1;

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

    cout<<l1.deleteFirstNode()<<endl;;
    cout<<l1.deleteLastNode()<<endl;;
    cout<<l1.deleteSpecificNode(100)<<endl;;

    l1.display();

    return 0;
}