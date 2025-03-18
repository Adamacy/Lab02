#include <iostream>

class Time {
private:
    int seconds_;
    int minutes_;
    int hours_;
public:
    Time(int h, int m, int s) {
        hours_ = ((m / 60) + h) % 24;
        minutes_ = ((s / 60) + m) % 60;
        seconds_ = s % 60;
    }
    Time(int s) {
        int minutes = (s / 60);
        hours_ = minutes / 60;
        seconds_ = s % 60;
        minutes_ = minutes % 60;
    }

    friend std::ostream& operator<<(std::ostream& str, Time& t);
};
std::ostream& operator<<(std::ostream& str, Time& t) {
    if (t.hours_ != 0) {
        str << t.hours_ << "h:" << t.minutes_ << "m:" << t.seconds_ << "s\n";
    }
    else {
        str << t.minutes_ << "m:" << t.seconds_ << "s\n";
    }
    return str;
}

int main()
{
    Time t1(13, 62, 73);
    std::cout << t1;
}
