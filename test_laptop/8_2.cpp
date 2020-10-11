//
// Created by yang zhengtao on 2020/10/10.
//
// reload the operator ++ to member function of class
#include <iostream>
using namespace std;

class Clock{
public:
    Clock(int hour = 0, int minute = 0, int second = 0);
    void showTime() const;
    Clock& operator++ ();   // 前置运算符重载
    Clock operator++ (int); // 后置运算符重载
private:
    int hour, minute, second;
};

Clock::Clock(int hour/* =0 */, int minute/* =0 */, int second/* = 0*/) {
    if (0 <= hour <= 24 && 0 <= minute <= 60 && 0<= second <= 60){
        this->hour = hour;
        this->minute = minute;
        this->second = second;
    } else{
        cout<<"Time error!"<<endl;
    }
}

void Clock::showTime() const {
    cout<<hour<<":"<<minute<<":"<<second<<endl;
}

// 定义前置运算符
Clock & Clock::operator++() {
    second++;
    if (second >= 60){
        second -= 60;
        minute++;
        if (minute >= 60){
            minute -= 60;
            hour = (hour + 1)%24;
        }
    }
    return *this;
}

// 定义后置运算符
Clock Clock::operator++(int) {
    Clock old = *this;
    ++(*this);
    return old;
}

int main(){
    Clock myClock(12, 59, 59);
    Clock newClockFront, newClockBack;

    cout<<"Current time is ";
    myClock.showTime();

    newClockFront = ++myClock;  // 前置运算符
    cout<<"New time front++ is ";
    newClockFront.showTime();

    newClockBack = myClock++;   // 后置运算符
    cout<<"New time back++ is ";
    newClockBack.showTime();

    return 0;

}


