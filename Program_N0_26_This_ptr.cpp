#include <iostream>
using namespace std;

class Student {
private:
    int id;

public:
    // constructor
    Student(int id) {
        this->id = id;  // using this pointer
    }

    void display() {
        cout << "Student ID: " << this->id << endl;  // accessing value
    }

    void compare(Student s) {
        if (this->id == s.id)  // comparing with another object
            cout << "Both students have the same ID." << endl;
        else
            cout << "Students have different IDs." << endl;
    }
};

int main() {
    Student s1(101);
    Student s2(102);

    s1.display();
    s2.display();

    s1.compare(s2);  // calling compare

    return 0;
} 