#include "hotel.h"


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

Date::Date(int day, int month, int year) {
    if (month < January || month > December) {
        throw std::invalid_argument("Invalid date");
    } 

    if (day < 1 || day > daysIn(month, year)) {
        throw std::invalid_argument("Invalid date");
    }

    this->day = day;
    this->month = month;
    this->year = year;
}

bool Date::operator<(const Date &oth) const {
    if (year != oth.year) 
        return year < oth.year;
    if (month != oth.month) 
        return month < oth.month;
    return day < oth.day;
}
bool Date::operator==(const Date &oth) const {
    if (day == oth.day && month == oth.month && year == oth.year) {
        return true;
    }
    return false;
}
bool Date::operator<=(const Date &oth) const {
    return *this < oth || *this == oth;
}
bool Date::operator>(const Date &oth) const {
    return !(*this <= oth);
}
bool Date::operator>=(const Date &oth) const {
    return !(*this < oth);
}

Date Date::getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    return Date(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);
}

bool Date::between(const Date &left, const Date &right) const {
    if (*this >= left && *this <= right) 
        return true;
    return false;
}

int Date::daysTo(const Date &oth) const {
    Date temp = *this;
    int count = 0;

    while (temp.year < oth.year) {
        count += daysInYear;
        if (temp.isLeapYear()) 
            count++;

        temp.year++;
    }

    count += oth.daysThisYear() - temp.daysThisYear();

    return count;
}

bool UnavailableRoom::around(const Date &oth) const{
    if (oth >= this->begin && oth <= this->end) 
        return true;
    return false;
}

Date UnavailableRoom::getBeginDate() const {
    return begin;
}
Date UnavailableRoom::getEndDate() const {
    return end;
}

void Room::registerRoom(const UnavailableRoom &reg) {
    registrations.push_back(reg);
}

bool Room::isBusy(const Date &date) {
    bool busy = false;
    for (auto curr : registrations) {
        if (curr.around(date)) {
            busy = true;
            break;
        }
    }
    return busy;
}

bool Room::isBusy(const Date &begin, const Date &end) {
    bool busy = false;
    for (auto curr : registrations) {
        if (curr.around(begin) || curr.around(end)) {
            busy = true;
            break;
        }
    }
    return busy;
}

int Room::busyInPeriod(const Date &begin, const Date &end) {
    int count = 0;

    for (auto curr : registrations) {
        Date tempBeg = curr.getBeginDate();
        Date tempEnd = curr.getEndDate();

        if (begin < tempBeg && end.between(tempBeg, tempEnd)) {
            count += tempBeg.daysTo(end);
        }
    }
    return count;
}

void Room::closeRoom(const UnavailableRoom &closing) {

}

void Room::freeRoom() {

}

int main() {

}