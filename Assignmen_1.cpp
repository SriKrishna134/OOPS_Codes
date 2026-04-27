#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str;

    str.assign("Hello, World!");  // assigning full string
    cout << str << endl;

    str.assign("Hello,Universe !", 7, 0);  // trying substring (but params are a bit confusing here)
    cout << str << endl;

    string other = "C++ Programming";
    str.assign(other, 4, 11);  // taking part of another string
    cout << str << endl;

    return 0;
}