#pragma once

#include <fstream>

#include "date.h"
#include "vector.h"

class UnavailablePeriod {
public: 
    enum UnavailableTypes {
        guest = 0, 
        construction = 1
    };

private:
    Date begin, end;

    MyVector<char> customerName;
    MyVector<char> note;

    UnavailableTypes type;

public:

    UnavailablePeriod();
    bool aroundDate(const Date& date) const; //проверява дали дадена дата е в интервала на текущата заявка
    bool intersectWith(const UnavailablePeriod& date) const; //проверява дали текущата заявка се засича с друга

    Date getBeginDate() const;
    Date getEndDate() const;

    void setBeginDate(const Date& date);
    void setEndDate(const Date& date);

    void freeEarlier(const Date& date); //освобождава стаята по рано

    bool isConstruction(); //проеверява дали типа на завката е ремонт

    static UnavailablePeriod input(const UnavailableTypes& type); 
    
    friend std::istream& operator>>(std::istream& in, UnavailablePeriod &unavailable);
    friend std::ostream& operator<<(std::ostream& out, const UnavailablePeriod &unavailable);
};