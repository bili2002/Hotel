#include <stdexcept>

#include "vector.h"

const int MonthsNumber = 12;
const int Months[MonthsNumber] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
    int day, month, year;

    bool isLeapYear(int year) {
        if (year % 400 == 0) 
            return true;
        if (year % 100 == 0) 
            return false;
        if (year % 4 == 0) 
            return true;
        return false;
    }

public:
    Date(int day, int month, int year) {
        if (month < 1 || month > MonthsNumber) {
            throw std::invalid_argument("Invalid date");
        } 

        if (day < 1 || day > Months[month-1]) {
            throw std::invalid_argument("Invalid date");
        }
        if (month == 2 && !isLeapYear(year) && day > Months[month-1] - 1) {
            throw std::invalid_argument("Invalid date");
        } 

        this->day = day;
        this->month = month;
        this->year = year;
    }

    bool operator<(const Date &oth) {
        if (year != oth.year) 
            return year < oth.year;
        if (month != oth.month) 
            return month < oth.month;
        return day < oth.day;
    }
    bool operator==(const Date &oth) {
        if (day == oth.day && month == oth.month && year == oth.year) {
            return true;
        }
        return false;
    }
    bool operator<=(const Date &oth) {
        return *this < oth || *this == oth;
    }
    bool operator>(const Date &oth) {
        return !(*this <= oth);
    }
    bool operator>=(const Date &oth) {
        return !(*this < oth);
    }
};

enum UnavailableTypes {
    guest, 
    construction
};

class UnavailableRoom {
    Date begin, end;
    int days;

    myVector<char> customerName;
    myVector<char> note;

};

class Room {
    int number;
    int bedCount;

    myVector<UnavailableRoom> registrations;
    
    void registerRoom(const UnavailableRoom &reg); 
    void isItBusy(const Date &date);
    void freeRoom();

};