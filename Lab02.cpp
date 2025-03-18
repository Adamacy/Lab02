#include <iostream>

class Time {
private:
    int seconds_;
    int minutes_;
    int hours_;
public:
    Time() {};
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
    int convertToSeconds() {
        return (hours_ * 3600) + (minutes_ * 60) + seconds_;
    }

    Time operator-(const Time& t) const {
        return Time(hours_ - t.hours_, minutes_ - t.minutes_, seconds_ - t.seconds_);
    }
    Time operator+(const Time& t) const {
        return Time(hours_ + t.hours_, minutes_ + t.minutes_, seconds_ + t.seconds_);
    }
    Time operator*(const int scalar) const {
        return Time(scalar * hours_, scalar * minutes_, scalar * seconds_);
    }
    operator int() {
        return convertToSeconds();
    }
    friend std::ostream& operator<<(std::ostream& str, Time& t);
    friend std::istream& operator >>(std::istream& in, Time& t);
};
std::ostream& operator<<(std::ostream& str, Time& t) {
    if (t.hours_ != 0) {
        str << t.hours_ << "h:" << t.minutes_ << "m:" << t.seconds_ << "s";
    }
    else {
        str << t.minutes_ << "m:" << t.seconds_ << "s";
    }
    return str;
}
std::istream& operator >>(std::istream& in, Time& t) {
    std::cout << "Enter hours: ";
    in >> t.hours_;
    std::cout << "Enter minutes: ";
    in >> t.minutes_;
    std::cout << "Enter seconds: ";
    in >> t.seconds_;
    return in;
}
int main()
{
    int choice = 0;
    std::cout << "Chose task (1 - Time, 2 - Superinvoice): ";
    std::cin >> choice;
    if (choice == 1) {
        Time t1(13, 74, 122); //Example data
        std::cout << t1 << "\n";
        Time t2;
        std::cin >> t2;
        std::cout << t2 << "\n";

        Time add_result = t1 - t2;
        Time sub_result = t1 - t2;
        Time mult_result = t1 * 3;
        std::cout << t1 << "+" << t2 << "=" << add_result << "\n";
        std::cout << t1 << "-" << t2 << "=" << sub_result << "\n";
        std::cout << t1 << "* 3 = " << mult_result << "\n";
        
        std::cout << "Conversion " << t2 << " to seconds : " << static_cast<int>(t2);
    }
    
}
