#include<iostream>
using namespace std;

class Time
{
    int hour, minute, second;

public:
    // function to take input from user
    void getTime()
    {
        cout << "\nEnter Hour: ";
        cin >> hour;

        cout << "Enter Minute: ";
        cin >> minute;

        cout << "Enter Second: ";
        cin >> second;
    }

    // function to display time
    void printTime()
    {
        cout << "\nHour: " << hour;
        cout << "\nMinute: " << minute;
        cout << "\nSecond: " << second;
    }

    // function to add two Time objects
    void addTime(Time x, Time y)
    {
        // simply adding respective values
        hour = x.hour + y.hour;
        minute = x.minute + y.minute;
        second = x.second + y.second;

        // trying to adjust if seconds or minutes exceed 60
        if (second >= 60)
        {
            minute += second / 60;
            second = second % 60;
        }

        if (minute >= 60)
        {
            hour += minute / 60;
            minute = minute % 60;
        }
    }
};

int main()
{
    Time t1, t2, t3;

    cout << "\nEnter first time";
    t1.getTime();

    cout << "\nEnter second time";
    t2.getTime();

    // adding t1 and t2, storing result in t3
    t3.addTime(t1, t2);

    cout << "\nResult time:";
    t3.printTime();  // earlier mistake was printing t1 instead of t3

    return 0;
}