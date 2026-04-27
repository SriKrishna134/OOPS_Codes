#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str1 = "apple";
    string str2 = "banana";

    int result = str1.compare(str2);  // comparing strings

    if(result == 0)
    {
        cout << "strings are equal" << endl;
    }
    else if(result < 0)
    {
        cout << str1 << " comes before " << str2 << endl;  // lexicographically smaller
    }
    else
    {
        cout << str1 << " comes after " << str2 << endl;
    }
}