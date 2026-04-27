#include<iostream>
using namespace std;

class Base
{
protected:
    int x;

public:
    void setData(int a)
    {
        x = 3;  // setting value (a not used)
    }

    int getData()
    {
        return x;  // returning value
    }
};

class Derived : public Base
{
public:
    void display()
    {
        cout << "value =" << getData() << endl;  // accessing base data
    }
};

int main()
{
    Derived d;

    d.setData(10);  // calling function
    d.display();    // showing result

    return 0;
} 