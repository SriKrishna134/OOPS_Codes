#include<iostream>
using namespace std;

class ABC{
public:
    int a = 50;  // data member
};

int main(){
    ABC ob1;
    ABC *ptr;   // pointer to object

    ptr = &ob1; // storing address

    cout << ob1.a << endl;
    cout << ptr->a;  // accessing using pointer (->)

    return 0;
}