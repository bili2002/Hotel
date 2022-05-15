#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>

#include "hotel.h"

Room &Hotel::findRoomWithNumber(int number) {
    for (auto &room : rooms) {
        if (room.getNumber() == number) {
            return room;
        }
    }

    throw std::invalid_argument("Няма такава стая.");   
}

void Hotel::registerGuestInRoom(int number, const UnavailableRoom &reg) {
    Room room;
    try {
        room = findRoomWithNumber(number);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    try {
        room.registerRoom(reg);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

void Hotel::printFreeRoomsForDate(const Date &date) {
    for (auto &room : rooms) {
        if (!room.isBusy(date)) {
            std::cout<<room.getNumber()<<' ';
        }
    }
    std::cout<<'\n';
}

void Hotel::freeRoom(int number) {
    Room room;
    try {
        room = findRoomWithNumber(number);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    room.freeRoom();
}

void Hotel::busyEnquiry(const Date &begin, const Date &end) {
    if (begin > end) {
        std::cerr<<("Крайната дата е преди началната дата.")<<std::endl;
        return;
    }

    char *filename = nullptr;
    strcpy(filename, "report-");
    strcpy(filename, begin.toString());

    std::ofstream out("filename.txt", std::ios::out);
    for (auto &room : rooms) {
        int days = room.busyInPeriod(begin, end);
        if (days != 0) {
            out<<room.getNumber()<<' '<<days<<'\n';
        }
    }
}

void Hotel::findRoom(const Date &date) {
    int minBeds = -1, numberOfRoom = -1;
    for (auto &room : rooms) {
        if (!room.isBusy(date)) {
            if (minBeds > room.getBedCount() || minBeds == -1) {
                minBeds = room.getBedCount();
                numberOfRoom = room.getNumber();
            }
        }
    }
    
    if (minBeds == -1) {
        std::cout<<"Няма свободна стая."<<'\n';
    } else {
        std::cout<<"Стаята е: "<<numberOfRoom<<"с "<<minBeds<<" легла.";
    }
}


void Hotel::closeRoom(int number, const UnavailableRoom &close) {
    Room room;
    try {
        room = findRoomWithNumber(number);
    }
    catch (std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
        return;
    }

    room.closeRoom(close);
}