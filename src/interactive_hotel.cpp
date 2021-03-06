#include <iostream>
#include <fstream>

#include "interactive_hotel.h"
#include "unavailable_period.h"

void InteractiveHotel::printHelp() {
    std::cout<<"Enter 0 - for help;\n";
    std::cout<<"Enter 1 - to register a guest;\n";
    std::cout<<"Enter 2 - to find free rooms for a given date;\n";
    std::cout<<"Enter 3 - to free a room today;\n";
    std::cout<<"Enter 4 - for a usage report for a given period;\n";
    std::cout<<"Enter 5 - to find the room with the fewest beds for a date;\n";
    std::cout<<"Enter 6 - to close a room;\n";
    std::cout<<"Enter 10 - to quit the program.\n";
}

void InteractiveHotel::registerGuestInputAndRun() {
    int n = getNumber();
    UnavailablePeriod UP = UnavailablePeriod::input(UnavailablePeriod::guest);
    hotel.registerGuestInRoom(n, UP);
}

void InteractiveHotel::printFreeRoomsInputAndRun() {
    Date date = Date::getDate();
    hotel.printFreeRoomsForDate(date);
}

void InteractiveHotel::freeRoomInputAndRun() {
    int n = getNumber();
    hotel.freeRoom(n);
}

void InteractiveHotel::busyEnquiryInputAndRun() {
    Date begin = Date::getDate();
    Date end = Date::getDate();
    hotel.busyEnquiry(begin, end);
}

void InteractiveHotel::findRoomInputAndRun() {
    Date date = Date::getDate();
    hotel.findRoom(date);
}

void InteractiveHotel::closeRoomInputAndRun() {
    int n = getNumber();
    UnavailablePeriod UP = UnavailablePeriod::input(UnavailablePeriod::construction);
    hotel.closeRoom(n, UP);
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
        std::cerr<<"Invalid command!"<<'\n';
        break;
    }
}

int InteractiveHotel::getNumber() {
    std::cout<<"Enter the number of the room:\n";

    int n;
    std::cin>>n;
    return n;
}

int InteractiveHotel::getCommand() {
    std::cout<<"Enter command:\n";

    int n;
    std::cin>>n;
    return n;
}

void InteractiveHotel::exitProgram() {
    std::exit(0);
}

void InteractiveHotel::run() {
    printHelp();
    std::ifstream in("Hotel.txt", std::ios::in);

    if (!in.is_open()) {
        std::cerr<<"Can't open file!\n";
        return;
    }

    in>>hotel;
    in.close();

    while (true) {
        doCommand(getCommand());

        std::ofstream out("Hotel.txt", std::ios::out | std::ios::trunc); 
        if (!out.is_open()) {
            std::cerr<<"The file isn't opened!\n"<<std::endl;
            return;
        }

        out<<hotel<<'\n';
        out.close();
    }
}