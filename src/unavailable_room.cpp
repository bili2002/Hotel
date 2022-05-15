#include <iostream>

#include "unavailable_room.h"
#include "date.h"
#include "string.h"

UnavailableRoom::UnavailableRoom() {};

bool UnavailableRoom::aroundDate(const Date &date) const {
    if (date >= this->begin && date <= this->end) 
        return true;
    return false;
}

bool UnavailableRoom::intersectWith(const UnavailableRoom &date) const {
    if (this->aroundDate(date.getBeginDate()) || this->aroundDate(date.getEndDate())) 
        return true;
    return false;
}

Date UnavailableRoom::getBeginDate() const {
    return begin;
}
Date UnavailableRoom::getEndDate() const {
    return end;
}

void UnavailableRoom::setBeginDate(const Date &date) {
    if (date > end) {
        return;
    }
    begin = date;
}
void UnavailableRoom::setEndDate(const Date &date) {
    end = date;
}

void UnavailableRoom::freeEarlier(const Date &date) {
    end = date;
}

bool UnavailableRoom::isConstruction() {
    return type == construction;
}

UnavailableRoom UnavailableRoom::input() {
    UnavailableRoom temp;

    temp.setBeginDate(Date::getDate());
    temp.setEndDate(Date::getDate());

    if (temp.getBeginDate() > temp.getEndDate()) {
        throw std::invalid_argument("Крайната дата е преди началната дата.");
        return temp;
    }
    
    std::cout<<"Въведете име на гост или оставете празно";
    std::cin>>temp.customerName;

    std::cout<<"Въведете бележка или оставете празно";
    std::cin>>temp.customerName;

    temp.type = guest;

    return temp;
}