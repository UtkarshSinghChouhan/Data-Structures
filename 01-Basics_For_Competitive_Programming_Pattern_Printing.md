<a href = "#01">Program-01</a> <br>
<a href = "#02">Program-02</a> <br>
<a href = "#03">Program-03</a> <br>
<a href = "#04">Program-04</a> <br>
<a href = "#05">Program-05</a> <br>
<a href = "#06">Program-06</a> <br>
<a href = "#07">Program-07</a> <br>
<a href = "#08">Program-08</a> <br>
<a href = "#09">Program-09</a> <br>
<a href = "#10">Program-10</a> <br>

<h2 id = "01">Program-01</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop.
#include<iostream>
using namespace std;

int main()
{
    for(int  i =0; i < 5; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
    return 0;
}

//Using While-Loop.
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while (j < i+1)
        {
           cout << "*" << " ";
           j++;
        }        
        cout << endl;
        i++;
    }
    return 0;
}
```

<h2 id = "02">Program-02</h2>

![alt text](http://url/to/img.png)

```cpp
//Using the For-Loop
#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j =  0; j < 5; j++)
        {
            if( j < 5- (i+1)){
                cout << " ";
            }

            else{
                cout << "*";
            }            
        }

        cout<<endl;
    }
    return 0;
}



//Using the While-Loop
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5){
        int j = 0;
        while(j < 5){
            if(j < 5-(i+1)){
                cout << " ";
            }
            
            else{
                cout << "*";
            }
            
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}
```

<h2 id = "03">Program-03</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop
#include<iostream>
using namespace std;

int main()
{
    for(int  i = 0; i < 5; i++ )
    {
        for(int j = 5-i; j > 0; j--)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}


//Using While-Loop
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5)
    {
        int j = 5-i;
        while(j > 0)
        {
            cout << "*";
            j--;
        }
        cout << endl;
        i++;
    }
    return 0;
}
```
<h2 id = "04">Program-04</h2>

![alt text](http://url/to/img.png)

```cpp
//Using the For-Loop
#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            if(j >= i){
                cout << "*";
            }

            else{
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}


//Using the While-Loop
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while (j < 5)
        {
            if(j >= i){
                cout << "*";
            }

            else{
                cout << " ";
            }
            j++;
        }
        
        cout << endl;
        i++;
    }
    return 0;
}
```

<h2 id = "05">Program-05</h2>

![alt text](http://url/to/img.png)

```cpp
//Using the For-Loop
#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout << (i+1);
        }

        cout << endl;
    }
    return 0;
}


//Using the While-Loop
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while(j < i+1)
        {
            cout << (i+1);
            j++;
        }
        cout << endl;
        i++;
    }
}
```

<h2 id = "06">Program-06</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop.
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    int k = i+1;
    
    for(i; i < 5; i++)
    {        
        for(int  j = 0; j < i+1 ; j++)
        {
            cout << k++ << " ";
        }
        cout << endl;
    }
    return 0;
}


//Using While-Loop.
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    int  k = (i+1);

    while(i < 5)
    {
        int j = 0;
        while(j < i+1)
        {
            cout << k++ << " "; 
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
```

<h2 id = "07">Program-07</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop.
#include<iostream>
using namespace std;

int main()
{
    char c = 'A';
    for(int  i = 0; i < 5; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout << c++ << " ";
        }
        cout << endl;
    }
    return 0;
}


//Using while-Loop.
#include<iostream>
using namespace std;

int main()
{
    char c = 'A';
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while(j < i+1)
        {
            cout << c++ << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
```

<h2 id = "08">Program-08</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop
#include<iostream>
using namespace std;

int main()
{
    char c = 'A';
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < i+1; j++)
        {
            cout << c << " ";
        }
        cout << endl;
        c++;
    }
  
    return 0;
}

//Using While-Loop
#include<iostream>
using namespace std;

int main()
{
    char c = 'A';
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while(j < i+1)
        {
            cout << c << " ";
            j++;
        }
        cout << endl;
        c++;
        i++;
    }
    return 0;
}
```

<h2 id = "09">Program-09</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop.
#include<iostream>
using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        for(int j =  0; j < 5; j++)
        {
            if( j < 5- (i+1)){
                cout << " ";
            }

            else{
                cout << "*" <<" ";
            }            
        }

        cout<<endl;
    }
    return 0;
}


```

<h2 id = "09">Program-09</h2>

![alt text](http://url/to/img.png)

```cpp
//Using For-Loop.


//Using While-Loop.
#include<iostream>
using namespace std;

int main()
{
    int i = 0;
    while(i < 5)
    {
        int j = 0;
        while (j < 5)
        {
            if(j >= i){
                cout << "* ";
            }

            else{
                cout << " ";
            }
            j++;
        }
        
        cout << endl;
        i++;
    }
    return 0;
}
```