#include <stdexcept>
#include <ctime>

#include "vector.h"
#include "info.h"

class Date {
    int day, month, year;

    bool isLeapYear() const;
    static bool isLeapYear(int year);
    static int daysIn(int month, int year);
    int daysThisYear() const;

public:
    Date(int day, int month, int year);

    bool operator==(const Date &oth) const;
    bool operator<(const Date &oth) const;
    bool operator<=(const Date &oth) const;
    bool operator>(const Date &oth) const;
    bool operator>=(const Date &oth) const;
    
    bool between(const Date &left, const Date &right) const;
    int daysTo(const Date &oth) const;

    static Date getCurrentDate();
};

enum UnavailableTypes {
    guest, 
    construction
};

class UnavailableRoom {
private:
    Date begin, end;
    int days;

    myVector<char> customerName;
    myVector<char> note;

    UnavailableTypes type;

public:
    bool around(const Date &const) const;
    Date getBeginDate() const;
    Date getEndDate() const;
};

class Room {
    int number;
    int bedCount;

    myVector<UnavailableRoom> registrations;

    
public:
    void registerRoom(const UnavailableRoom &reg); 
    bool isBusy(const Date &date);
    bool isBusy(const Date &begin, const Date &end);
    void freeRoom();
    int busyInPeriod(const Date &begin, const Date &end);
    void closeRoom(const UnavailableRoom &closing);
};