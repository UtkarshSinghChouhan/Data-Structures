#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int  j = 0; j < 5; j++ )
        {
            if(i == 0 || i == 4)
            {
                cout << "* ";       //one space is provided after each character print.
            }

            else{
                if(j == 0 || j == 4)
                {
                    cout << "* ";     //one space is provided after each character print.
                }

                else{
                    cout << "  ";   //two spaces are provided here (Similar to above situation where one space is provided after each character print)
                }
            }
        }

        cout << endl;
    }
    return 0;
}