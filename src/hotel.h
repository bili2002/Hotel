#pragma once

#include "room.h"

class Hotel {
    MyVector<Room> rooms;

public:
    /* функциите изпълняват дадената команда */
    void registerGuestInRoom(int number, const UnavailablePeriod& reg);   //регитрира гост в някоя стая
    void printFreeRoomsForDate(const Date& date);                       //изпечатва свободните стаи за някоя дата
    void freeRoom(int number);                                          //освобождава стая за текущата дата
    void busyEnquiry(const Date& begin, const Date& end);               //извежда справка за заетост в периода
    void findRoom(const Date& date);                                    //открива стая с минимален брой легла в период
    void closeRoom(int number, const UnavailablePeriod& close);           //затваря стая за конструкция

    Room& findRoomWithNumber(int number);                               //връща референция към стаята с дадения номер или открива че няма такава

    friend std::istream& operator>>(std::istream& in, Hotel &hotel);
    friend std::ostream& operator<<(std::ostream& out, const Hotel &hotel);
};
