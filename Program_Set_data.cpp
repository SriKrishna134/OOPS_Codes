#include<iostream>
using namespace std;

class Base
{
private:
    int z;

public:
    void setData(int a)
    {
        z = 2;  // setting value (a not used)
    }

    int getData()
    {
        return z;  // returning value
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "Value=" << getData() << endl;  // using base function
    }
};

int main()
{
    Derived d;  // object

    d.setData(10);  // calling function
    d.display();    // showing result
} 