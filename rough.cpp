

// #include <iostream>
// #include <stdlib.h>
// using namespace std;
// int main()
// {
//     int i, j, k, l, n;
//     cout << "Enter the number of rows : ";
//     cin >> n;
//     for (i = 1; i <= n; i++)
//     {
//         for (k = 1; k <= i; k++)
//         {
//             cout << k << " ";
//         }

//         for (l = i - 1; l >= 1; l--)
//         {
//             cout << l << " ";
//         }

//         cout << endl;
//     }
//     return 0;
// }

#include<iostream>
using namespace std;

int main()
{
    for(int  i = 1; i <= 5; i++)
    {
        int k = i;
        for(int  j = 1; j <= i; j++)
        {
            cout << k++ << " ";
        }

        for(int l = (i-1); l >= 1; l--)
        {
            cout << l << " ";
        }
        cout << endl;
    }
    return 0;
}