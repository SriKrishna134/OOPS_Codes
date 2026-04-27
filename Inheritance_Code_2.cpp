#include<iostream>
using namespace std;

class vehicle
{
public:
    int speed;

    void showspeed();  // function declaration
};

// function defined outside class
void vehicle::showspeed()
{
    cout << "speed=" << speed << "km/hr" << endl;
}

class car : public vehicle
{
public:
    string brand;  // extra data
};

int main()
{
    car c1, c2;  // objects

    c1.brand = "Toyota";
    c1.speed = 120;
    c1.showspeed();
    cout << "Brand:" << c1.brand << endl;

    c2.brand = "Porsche";
    c2.speed = 220;
    c2.showspeed();
    cout << "Brand:" << c2.brand << endl;

    return 0;
} 