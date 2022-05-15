#include <iostream>

#include "unavailable_period.h"
#include "date.h"
#include "string.h"

UnavailablePeriod::UnavailablePeriod() {};

bool UnavailablePeriod::aroundDate(const Date& date) const {
    if (date >= this->begin && date <= this->end) 
        return true;
    return false;
}

bool UnavailablePeriod::intersectWith(const UnavailablePeriod& date) const {
    if (this->aroundDate(date.getBeginDate()) || this->aroundDate(date.getEndDate()) || date.aroundDate(this->begin)) 
        return true;
    return false;
}

Date UnavailablePeriod::getBeginDate() const {
    return begin;
}
Date UnavailablePeriod::getEndDate() const {
    return end;
}

void UnavailablePeriod::setBeginDate(const Date& date) {
    begin = date;
}
void UnavailablePeriod::setEndDate(const Date& date) {
    end = date;
}

void UnavailablePeriod::freeEarlier(const Date& date) {
    end = date;
}

bool UnavailablePeriod::isConstruction() {
    return type == construction;
}

UnavailablePeriod UnavailablePeriod::input() {
    UnavailablePeriod temp;

    temp.setBeginDate(Date::getDate());
    temp.setEndDate(Date::getDate());

    if (temp.getBeginDate() > temp.getEndDate()) {
        throw std::invalid_argument("ERROR: the end date is before the beginning one.\n");
        return temp;
    }
    
    std::cout<<"Enter name of the guest or input - if you want to leave it blank:\n";
    std::cin>>temp.customerName;

    std::cout<<"Enter note or input - if you want to leave it blank:\n";
    std::cin>>temp.customerName;

    temp.type = guest;

    return temp;
}

std::istream& operator>>(std::istream& in, UnavailablePeriod &unavailable) {
    in>>unavailable.begin;
    in>>unavailable.end;

    in>>unavailable.customerName;
    in>>unavailable.note;

    int tempInt;
    in>>tempInt;

    if (tempInt == 0) {
        unavailable.type = UnavailablePeriod::guest;
    } else {
        unavailable.type = UnavailablePeriod::construction;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const UnavailablePeriod &unavailable) {
    out<<unavailable.begin<<'\n';
    out<<unavailable.end<<'\n';

    out<<unavailable.customerName<<'\n';
    out<<unavailable.note<<'\n';

    if (unavailable.type == UnavailablePeriod::guest) {
        out<<0;
    } else {
        out<<1;
    }

    return out;
}
