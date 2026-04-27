#include<iostream>
using namespace std;

class A{
public:
    int i;  // base data
};

class B : virtual public A
{
public:
    int j;
};

class C : virtual public A
{
public:
    int k;
};

class D : public B, public C
{
public:
    int sum;
};

int main()
{
    D ob1;  // object

    ob1.i = 2;
    ob1.j = 5;
    ob1.k = 3;

    ob1.sum = ob1.i + ob1.j + ob1.k;  // adding values

    cout << "sum=" << ob1.sum;

    return 0;
}