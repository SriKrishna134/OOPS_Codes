#include<iostream>
using namespace std;

class rectangle
{
private:
    int length;
    int width;
    float area;

public:
    void display()
    {
        cout << "Enter length and width of rectangle" << endl;
        cin >> length >> width;  // taking input

        area = length * width;   // calculating area

        cout << "Area = " << area << endl;  // showing result
    }
};

int main()
{
    rectangle r;  // object

    r.display();  // calling function

    return 0;
} 