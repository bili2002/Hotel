#pragma once

#include "date.h"
#include "vector.h"

class UnavailableRoom {
private:
    enum UnavailableTypes {
        guest, 
        construction
    };

    Date begin, end;

    MyVector<char> customerName;
    MyVector<char> note;

    UnavailableTypes type;

public:
    UnavailableRoom();
    bool aroundDate(const Date &date) const;
    bool intersectWith(const UnavailableRoom &date) const;

    Date getBeginDate() const;
    Date getEndDate() const;

    void setBeginDate(const Date &date);
    void setEndDate(const Date &date);

    void freeEarlier(const Date &date);

    bool isConstruction();

    static UnavailableRoom input();
};