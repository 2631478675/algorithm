#include<iostream>

using namespace std;

class Date;


class Time {
public:
    Time(int, int, int);

    friend void display();

private:
    int hour;
    int minute;
    int sec;
};

class Date {
public:
    Date(int, int, int);

    friend void display();

private:
    int month;
    int day;
    int year;
};

Time::Time(int h, int m, int s) {
    hour = h;
    minute = m;
    sec = s;
}

Date::Date(int m, int d, int y) {
    month = m;
    day = d;
    year = y;
}

void display() {
    Time t(10, 13, 56);
    Date d(12, 25, 2004);
    cout << d.month << "/" << d.day << "/" << d.year << " " << t.hour << ":" << t.minute << ":" << t.sec << endl;
    cout << endl;
}

int main() {

    display();
    return 0;
}
