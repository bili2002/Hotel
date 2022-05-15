#pragma once

#include <cstring>

class Date {
private:
    int day, month, year;

    bool isLeapYear() const;
    static bool isLeapYear(int year);
    static int daysIn(int month, int year);
    int daysThisYear() const;

public:
    Date();
    Date(int day, int month, int year);

    bool operator==(const Date &oth) const;
    bool operator<(const Date &oth) const;
    bool operator<=(const Date &oth) const;
    bool operator>(const Date &oth) const;
    bool operator>=(const Date &oth) const;
    
    bool between(const Date &left, const Date &right) const;
    int daysTo(const Date &oth) const;

    static Date getCurrentDate();

    static Date getDate();

    char *toString() const;
};