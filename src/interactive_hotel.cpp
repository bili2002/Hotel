#include <iostream>

#include "interactive_hotel.h"
#include "unavailable_room.h"

void InteractiveHotel::printHelp() {
    std::cout<<"Въведете 0 - за помощ;\n";
    std::cout<<"Въведете 1 - за регистриране на гост;\n";
    //to do
    std::cout<<"Въведете 10 - даизключите програмата.\n";
}

void InteractiveHotel::registerGuestInputAndRun() {
    hotel.registerGuestInRoom(getNumber(), UnavailableRoom::input());
}

void InteractiveHotel::printFreeRoomsInputAndRun() {
    hotel.printFreeRoomsForDate(Date::getDate());
}

void InteractiveHotel::freeRoomInputAndRun() {
    hotel.freeRoom(getNumber());
}

void InteractiveHotel::busyEnquiryInputAndRun() {
    hotel.busyEnquiry(Date::getDate(), Date::getDate());
}

void InteractiveHotel::findRoomInputAndRun() {
    hotel.findRoom(Date::getDate());
}

void InteractiveHotel::closeRoomInputAndRun() {
    hotel.closeRoom(getNumber(), UnavailableRoom::input());
}

void InteractiveHotel::doCommand(int command) {
    switch (command)
    {
    case Comamands::help :
        printHelp();
        break;
    case Comamands::registerGuest :
        registerGuestInputAndRun();
        break;
    case Comamands::printFreeRooms :
        printFreeRoomsInputAndRun();
        break;
    case Comamands::freeRoom :
        freeRoomInputAndRun();
        break;
    case Comamands::busyEnquiry :
        busyEnquiryInputAndRun();
        break;
    case Comamands::findRoom :
        findRoomInputAndRun();
        break;
    case Comamands::closeRoom :
        closeRoomInputAndRun();
        break;
    case Comamands::exit : 
        exitProgram();
        break;
    
    default:
        std::cerr<<"Грешна команда!"<<'\n';
        break;
    }
}

int InteractiveHotel::getNumber() {
    int n;
    std::cin>>n;
    return n;
}

int InteractiveHotel::getCommand() {
    int n;
    std::cin>>n;
    return n;
}

void InteractiveHotel::exitProgram() {
    std::exit(0);
}

void InteractiveHotel::run() {
    while (true) {
        doCommand(getCommand());
    }
}