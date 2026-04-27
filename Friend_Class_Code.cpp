#include<iostream>
using namespace std;

class Base{
    int x;

public:
    Base()
    {
        x = 5;  // initializing value
    }

    friend class Derived;  // giving access to Derived
};

class Derived{
public:
    void display(Base b){
        cout << "Value=" << b.x << endl;  // accessing private data
    }
};

int main()
{
    Base b;
    Derived d;

    d.display(b);  // calling function

    return 0;
}