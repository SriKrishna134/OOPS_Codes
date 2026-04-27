//write a c++ program to pass a object as a function argument where object represents time add two object make it a non inline function
#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;  // store time

public:
    void getTime() {
        cout << "Enter hours, minutes and seconds: ";
        cin >> hours >> minutes >> seconds;
    }

    void displayTime() {
        cout << hours << "h " << minutes << "m " << seconds << "s";
    }

    // non-inline function (defined outside)
    Time addTime(Time t);
};

// defined outside class → so non-inline
Time Time::addTime(Time t) {
    Time temp;  // result object

    temp.seconds = seconds + t.seconds;

    // carry from sec → min
    temp.minutes = minutes + t.minutes + temp.seconds / 60;
    temp.seconds = temp.seconds % 60;

    // carry from min → hr
    temp.hours = hours + t.hours + temp.minutes / 60;
    temp.minutes = temp.minutes % 60;

    return temp;
}

int main() {
    Time t1, t2, result;

    cout << "Enter first time:\n";
    t1.getTime();

    cout << "Enter second time:\n";
    t2.getTime();

    result = t1.addTime(t2);  // passing object

    cout << "Sum of time = ";
    result.displayTime();

    return 0;
}