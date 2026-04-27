#include<iostream>
using namespace std;

class Time
{
    int hour, minute, second;

public:
    void getTime()
    {
        cout << "\nEnter Hour:"; cin >> hour;
        cout << "\nEnter Minute:"; cin >> minute;
        cout << "\nEnter Second:"; cin >> second;
    }

    void printtime()
    {
        cout << "\nhour:" << hour;
        cout << "\nminute:" << minute;
        cout << "\nsecond:" << second;
    }

    void addtime(Time x, Time y)
    {
        hour = x.hour + y.hour;      // adding hours
        minute = x.minute + y.minute;
        second = x.second + y.second;
    }
};

int main(){
    Time t1, t2, t3;

    cout << "\nenter time";
    t1.getTime();

    cout << "\nenter time";
    t2.getTime();

    t3.addtime(t1, t2);  // storing in t3

    cout << "\nResult time";
    t3.printtime();  // print result

    return 0;
}