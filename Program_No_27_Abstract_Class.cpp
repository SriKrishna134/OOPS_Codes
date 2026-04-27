#include<iostream>
using namespace std;

class shape{
protected:
    float x;  // dimension

public:
    void getData(){
        cin >> x;  // input
    }

    virtual float calculateArea() = 0;  // pure virtual
};

class square : public shape
{
public:
    float calculateArea()
    {
        return x * x;  // area of square
    }
};

class circle : public shape
{
public:
    float calculateArea()
    {
        return 3.14 * x * x;  // area of circle
    }
};