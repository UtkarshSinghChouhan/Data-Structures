#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            if(j < 5 && i == 4)     //For printing the Last Line only.
            {
                cout << (j+1) << " ";
            }

            else if(j == (5-(i+1)) && i > 0 && i != 4)          //For printing the First Characters.
            {
                cout << (j+1);
            }

            else if()       //For printing the Last Characters.
            {

            }

            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}