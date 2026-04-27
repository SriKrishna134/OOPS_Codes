#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string str1 = "Hello";
    string str2 = "World!";

    string result = str1 + str2;  // concatenation
    cout << result << endl;

    string str3 = str1 + ",C++!";  // adding extra text
    cout << str3 << endl;

    return 0;
}