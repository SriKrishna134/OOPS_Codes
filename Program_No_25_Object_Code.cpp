#include<iostream>
using namespace std;

class ABC{
public:
    int a;

    void setData(int a)
    {
        this->a = a;  // using this pointer
    }

    void show()
    {
        cout << "Value=" << this->a << endl;  // accessing with this
    }
};

int main(){
    ABC ob1;

    ob1.setData(50);  // setting value
    ob1.show();       // displaying

    return 0;
} 