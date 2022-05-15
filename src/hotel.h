#pragma once

#include "room.h"

class Hotel {
    MyVector<Room> rooms;

public:
    /* функциите изпълняват дадената команда */
    void registerGuestInRoom(int number, const UnavailableRoom &reg);   //регитрира гост в някоя стая
    void printFreeRoomsForDate(const Date &date);                       //изпечатва свободните стаи за някоя дата
    void freeRoom(int number);                                          //освобождава стая за текущата дата
    void busyEnquiry(const Date &begin, const Date &end);               //извежда справка за заетост в периода
    void findRoom(const Date &date);                                    //открива стая с минимален брой легла в период
    void closeRoom(int number, const UnavailableRoom &close);           //затваря стая за конструкция

    Room &findRoomWithNumber(int number);
};
