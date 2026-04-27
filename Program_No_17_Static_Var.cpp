#include<iostream>
using namespace std;

class demo{
    static int count;  // shared variable

public:
    void getcount()
    {
        cout << "count=" << ++count << endl;  // increment and show
    }
};

int demo::count;  // static initialization

int main()
{
    demo d1, d2, d3;  // creating objects

    d1.getcount();
    d2.getcount();
    d3.getcount();

    return 0;
} 