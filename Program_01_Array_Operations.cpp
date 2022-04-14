#include<iostream>
using namespace std;

const int MAX = 5;

class Array
{
    int arr[MAX];
public:
    void insert(int pos, int num);
    void del(int pos);
    void reverse();
    void display();
    void search(int num);    
};

//Insert an element 'num' at a given position 'pos'
void Array :: insert(int pos, int num)
{
  //Shifting element to the Right of the array.
  if(pos > 1)
  {
    for(int i = (MAX-1); i>=pos; i--)
    {
        arr[i] = arr[i-1];
        arr[i] = num;
    }
  }

  else
  {
    
  }
}

//Deleting an element from a given position.
void Array :: del(int pos)
{    
    for(int i = pos; i<=MAX; i++) 
    {
        arr[i-1] = arr[i];
        arr[i] = 0;
    }
}

//Reversing the array elements.
void Array :: reverse()
{
    for(int i = 0; i<=(MAX/2); i++)
    {
        int temp = arr[i];
        arr[i] = arr[MAX-(i+1)];
        arr[MAX-(i+1)] = temp;
    }
}

//Displaying the array elements.
void Array :: display()
{
    for(int i = 0; i<MAX; i++)
    {
        cout<<" "<<arr[i];
    }
}

//Searching an element in an array.
void Array :: search(int num)
{
    int i;
    for(i = 0; i<MAX; i++)
    {
        if(arr[i] == num)
        {
            cout<<"The element "<<num<<" is pressent at "<<(i+1)<<" location."<<endl;
        }
    }

    if(i == MAX)
    {
        cout<<"The element "<<num<<" is not present in the array."<<endl;
    }
}

int main()
{
    Array a;

    //Inserting the elements in array.
    a.insert(1,11);
    a.insert(2,12);
    a.insert(3,13);
    a.insert(4,14);
    a.insert(5,15);

    cout<<"After inserting the elements : "<<endl;
    a.display();
    return 0;
}