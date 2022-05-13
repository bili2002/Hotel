#include <stdexcept>
#include <ctime>

#include "vector.h"
#include "info.h"

class Date {
private:
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


class UnavailableRoom {
private:
    enum UnavailableTypes {
        guest, 
        construction
    };

    Date begin, end;
    int days;

    myVector<char> customerName;
    myVector<char> note;

    UnavailableTypes type;

public:
    bool aroundDate(const Date &date) const;
    bool intersectWith(const UnavailableRoom &date) const;
    Date getBeginDate() const;
    Date getEndDate() const;

    void freeEarlier(const Date &date);
};

class Room {
private:
    int number;
    int bedCount;

    myVector<UnavailableRoom> unavailable;

public:
    void registerRoom(const UnavailableRoom &reg); 
    bool isBusy(const Date &date);
    bool isBusy(const Date &begin, const Date &end);
    int busyInPeriod(const Date &begin, const Date &end);
    void closeRoom(const UnavailableRoom &closing);
    void freeRoom();
};