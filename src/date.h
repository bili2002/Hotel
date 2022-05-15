#pragma once

#include <cstring>

class Date {
private:
    int day, month, year;

    bool isLeapYear() const; //проверява дали годината е високосна
    static bool isLeapYear(int year); //проверява дали годината е високосна
    static int daysIn(int month, int year); //брой дни в даден месец и година
    int daysThisYear() const; //изминали дни в текущата година

public:
    Date();
    Date(int day, int month, int year);

    bool operator==(const Date& oth) const;
    bool operator<(const Date& oth) const; 
    bool operator<=(const Date& oth) const;
    bool operator>(const Date& oth) const;
    bool operator>=(const Date& oth) const;

    friend std::istream& operator>>(std::istream& in, Date &date);
    friend std::ostream& operator<<(std::ostream& out, const Date &date);
    
    bool between(const Date& left, const Date right) const; //проверява дали датата е между 2 други
    int daysTo(const Date& oth) const; //смята дните до друга дата

    static Date getCurrentDate(); //връща текущатата дата

    static Date getDate(); //взема дата от потребителя

    void toString(char str[]) const; //превръща дата в стринг
};
