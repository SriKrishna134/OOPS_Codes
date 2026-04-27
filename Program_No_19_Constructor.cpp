#include <iostream>
using namespace std;

class Student {
private:
    int id;
    string name;

public:
    // default constructor
    Student() {
        id = 0;
        name = "Unknown";
        cout << "Default Constructor Called\n";
    }

    // parameterized constructor
    Student(int i, string n) {
        id = i;
        name = n;
        cout << "Parameterized Constructor Called\n";
    }

    // copy constructor
    Student(const Student &s) {
        id = s.id;
        name = s.name;
        cout << "Copy Constructor Called\n";
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

int main() {
    Student s1;  // default
    s1.display();

    cout << endl;

    Student s2(101, "Pranjwal");  // parameterized
    s2.display();

    cout << endl;

    Student s3 = s2;  // copy
    s3.display();

    return 0;
}