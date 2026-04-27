#include<iostream>
using namespace std;

class demo{
    static int count;  // common for all objects

public:
    void getcount()
    {
        cout << "count=" << ++count << endl;  // increase and print
    }
};

int demo::count;  // static variable

int main()
{
    demo d1, d2, d3;  // objects

    d1.getcount();
    d2.getcount();
    d3.getcount();

    return 0;
}