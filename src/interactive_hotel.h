#pragma once

#include "hotel.h"

class InteractiveHotel {
private:
    Hotel hotel;

    /* всички функции въвеждат данните а дадена заявка и я извикват след това */
    
    void registerGuestInputAndRun();           //регитрира гост в някоя стая
    void printFreeRoomsInputAndRun();          //изпечатва свободните стаи за някоя дата
    void freeRoomInputAndRun();                //освобождава стая за текущата дата
    void busyEnquiryInputAndRun();             //извежда справка за заетост в периода
    void findRoomInputAndRun();                //открива стая с минимален брой легла в период
    void closeRoomInputAndRun();               //затваря стая за конструкция
 
    enum Comamands {
        help = 0,
        registerGuest = 1,
        printFreeRooms = 2,
        freeRoom = 3,
        busyEnquiry = 4,
        findRoom = 5,
        closeRoom = 6,
        exit = 10
    };

    void doCommand(int command); 
    int getCommand();
    void printHelp();
    void exitProgram();

    int getNumber();

public:
    void run(); 
};