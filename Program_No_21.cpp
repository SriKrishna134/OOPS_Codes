#include <iostream>
using namespace std;

// base class
class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    int publicVar;

    Base() {
        privateVar = 10;
        protectedVar = 20;
        publicVar = 30;
    }

    void displayBase() {
        cout << "Inside Base Class:" << endl;
        cout << "Private Variable: " << privateVar << endl;
        cout << "Protected Variable: " << protectedVar << endl;
        cout << "Public Variable: " << publicVar << endl;
    }
};

// public inheritance
class DerivedPublic : public Base {
public:
    void show() {
        cout << "\nPublic Inheritance:" << endl;
        // privateVar not accessible
        cout << "Protected Variable: " << protectedVar << endl;
        cout << "Public Variable: " << publicVar << endl;
    }
};

// protected inheritance
class DerivedProtected : protected Base {
public:
    void show() {
        cout << "\nProtected Inheritance:" << endl;
        cout << "Protected Variable: " << protectedVar << endl;
        cout << "Public Variable (now protected): " << publicVar << endl;
    }
};

// private inheritance
class DerivedPrivate : private Base {
public:
    void show() {
        cout << "\nPrivate Inheritance:" << endl;
        cout << "Protected Variable (now private): " << protectedVar << endl;
        cout << "Public Variable (now private): " << publicVar << endl;
    }
};

int main() {
    Base b;
    b.displayBase();

    DerivedPublic dp;
    dp.show();

    DerivedProtected dpro;
    dpro.show();

    DerivedPrivate dpri;
    dpri.show();

    return 0;
}