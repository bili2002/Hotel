#pragma once

#include "unavailable_period.h"

class Room {
private:
    int number = 0; //номер на стая
    int bedCount = 0; //брой легла

    MyVector<UnavailablePeriod> unavailable; //списък с датите и инфромация за тях в които дадената стая е заета

public:
    void registerRoom(const UnavailablePeriod& reg); //регистриране на гост в текущата стая
    bool isBusy(const Date& date) const; //проверява дали стаята е заета за дадена дата
    bool isBusy(const Date& begin, const Date& end) const; //проверява дали стаята е заета за даден период
    int busyInPeriod(const Date& begin, const Date& end) const; //връща за колко дни е заета стаята в даден период
    void closeRoom(UnavailablePeriod closing); //затваря стая
    void freeRoom(); //освобождава стая

    int getNumber() const; 
    int getBedCount() const; 

    void getRoom();

    friend std::istream& operator>>(std::istream& in, Room &room);
    friend std::ostream& operator<<(std::ostream& out, const Room &room);
};