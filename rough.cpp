#include<iostream>
using namespace std;

int main()
 {
    int i = 0; 
    while(i < 5)
    {
        int j = 0;
        while(j < 9)
        {
            if(j < 5 && i == 4)        //For Printing Last Line only.
            {
                cout << (j+1) << " ";
            }

            else if(j == (5-(i+1)) && i != 4)       //For Printing the First Characters.
            {
                cout << "1";
            }

            else if(j == (4+i) && i > 0 && i != 4)       //For Printing the Last Characters.
            {
                cout << (i+1);
            }

            else{               //For Printing the Space infront and creating hollow inside of the pyramid.
                cout << " ";
            }
            j++;
        }
        i++;
        cout <<endl;
    }
    return 0;
}