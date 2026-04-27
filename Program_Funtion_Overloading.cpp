#include <iostream>
using namespace std;

// function overloading
void display(int);
void display(float);
void display(int, float);

int main() {

    int a = 5;
    float b = 5.5;

    display(a);      // calling int version
    display(b);      // calling float version
    display(a, b);   // calling both

    return 0;
}

void display(int var)
{
    cout << "Integer number: " << var << endl;
}

void display(float var)
{
    cout << "Float number: " << var << endl;
}

void display(int var1, float var2)
{
    cout << "Integer number: " << var1 << " and float number: " << var2 << endl;
}