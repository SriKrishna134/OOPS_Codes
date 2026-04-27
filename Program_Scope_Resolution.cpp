#include<iostream>
using namespace std;

int m = 10;  // global variable

int main()
{
    int a = 3;
    int m = 5;  // local variable (shadows global)

    if (a == 2)
    {
        int m = 4;  // inner scope variable

        cout << ::m;  // accessing global m using scope resolution
    }

    return 0;
} 