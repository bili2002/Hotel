#include <ctime>  
#include <iostream>  
#include <algorithm> 

#include "date.h"
#include "info.h"
#include "vector.h"
#include "string.h"

bool Date::isLeapYear(int year) {
    if (year % 400 == 0) 
        return true;
    if (year % 100 == 0) 
        return false;
    if (year % 4 == 0) 
        return true;
    return false;
}

bool Date::isLeapYear() const {
    return isLeapYear(this->year);
}

int Date::daysIn(int month, int year) {
    if (month == February) {
        return daysInMonth[month] + isLeapYear(year);
    }
    return daysInMonth[month];
}

int Date::daysThisYear() const {
    int count = 0;
    int tempMonth = 0;

    while (tempMonth < this->month) {
        count += daysIn(tempMonth++, this->year);
    }
    count += this->day;

    return count;
}

Date::Date() {};

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::operator<(const Date& oth) const {
    if (year != oth.year) 
        return year < oth.year;
    if (month != oth.month) 
        return month < oth.month;
    return day < oth.day;
}
bool Date::operator==(const Date& oth) const {
    if (day == oth.day && month == oth.month && year == oth.year) {
        return true;
    }
    return false;
}
bool Date::operator<=(const Date& oth) const {
    return *this < oth || *this == oth;
}
bool Date::operator>(const Date& oth) const {
    return !(*this <= oth);
}
bool Date::operator>=(const Date& oth) const {
    return !(*this < oth);
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    return Date(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);
}

bool Date::between(const Date& left, const Date right) const {
    if (left > right) {
        if (*this <= left && *this >= right) {
            return true;
        }
    } else if (*this >= left && *this <= right)
        return true;
    return false;
}

int Date::daysTo(const Date& oth) const {
    Date temp = *this;
    int count = 0;

    while (temp.year < oth.year) {
        count += daysInYear;
        if (temp.isLeapYear()) 
            count++;

        temp.year++;
    }

    count += oth.daysThisYear() - temp.daysThisYear();

    return count + 1;
}

Date Date::getDate() {
    std::cout<<"Enter date(dd/mm/yyyy):\n";

    Date temp;
    std::cin>>temp.day>>temp.month>>temp.year;
    temp.month--;

    if (temp.month < January || temp.month > December) {
        std::cout<<"Wrong date, try again: \n";
        getDate();
    }

    if (temp.day < 1 || temp.day > daysIn(temp.month, temp.year)) {
        std::cout<<"Wrong date, try again: \n";
        getDate();
    }

    if (temp < getCurrentDate()) {
        std::cout<<"The date is in the past, try again: \n";
        getDate();
    }

    return temp;
}

char* Date::toString() const {
    char* str = nullptr;

    str += year / 1000 + '0';
    str += (year / 100) % 10 + '0';
    str += (year / 10) % 100 + '0';
    str += year % 1000 + '0';
    str += '-';
    str += month / 10 + '0';
    str += month % 10 + '0';
    str += '-';
    str += day / 10 + '0';
    str += day % 10 + '0';

    return str;
}

std::istream& operator>>(std::istream& in, Date &date) {
    in>>date.day>>date.month>>date.year;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Date &date) {
    out<<date.day<<' '<<date.month<<' '<<date.year;
    return out;
}