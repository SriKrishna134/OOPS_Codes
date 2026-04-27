#include <iostream>
using namespace std;

class Car
{
public:
    string brand;
    int speed;

    void show()
    {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << endl;
    }
};

int main()
{
    Car c1;  // creating object

    c1.brand = "Toyota";
    c1.speed = 180;

    c1.show();  // displaying details

    return 0;
}