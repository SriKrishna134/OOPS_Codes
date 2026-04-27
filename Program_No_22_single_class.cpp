#include <iostream>
using namespace std;

// base class
class A {
public:
    int x;
};

// public inheritance
class B : public A {
public:
    void show() {
        x = 10;
        cout << "Public Inheritance x = " << x << endl;
    }
};

// protected inheritance
class C : protected A {
public:
    void show() {
        x = 20;
        cout << "Protected Inheritance x = " << x << endl;
    }
};

// private inheritance
class D : private A {
public:
    void show() {
        x = 30;
        cout << "Private Inheritance x = " << x << endl;
    }
};

int main() {
    B b;
    b.show();

    C c;
    c.show();

    D d;
    d.show();

    return 0;
}