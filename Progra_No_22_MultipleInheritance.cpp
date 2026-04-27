#include <iostream>
using namespace std;

// base class 1
class A {
public:
    int x;
};

// base class 2
class B {
public:
    int y;
};

// derived class (multiple inheritance)
class C : public A, public B {
public:
    void show() {
        x = 10;
        y = 20;

        cout << "x = " << x << endl;
        cout << "y = " << y << endl;
        cout << "Sum = " << x + y << endl;  // adding both
    }
};

int main() {
    C obj;  // object of derived class
    obj.show();

    return 0;
}