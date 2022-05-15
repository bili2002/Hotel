#pragma once

#include "unavailable_room.h"

class Room {
private:
    int number = 0;
    int bedCount = 0;

    MyVector<UnavailableRoom> unavailable = MyVector<UnavailableRoom>();

public:
    void registerRoom(const UnavailableRoom &reg); 
    bool isBusy(const Date &date) const;
    bool isBusy(const Date &begin, const Date &end) const;
    int busyInPeriod(const Date &begin, const Date &end) const;
    void closeRoom(UnavailableRoom closing);
    void freeRoom();

    int getNumber() const;
    int getBedCount() const;
};