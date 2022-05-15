#include <stdexcept>
#include <iostream>
#include <fstream>
#include <cstring>

#include "hotel.h"
#include "string.h"

Room& Hotel::findRoomWithNumber(int number) {
    for (auto& room : rooms) {
        if (room.getNumber() == number) {
            return room;
        }
    }

    throw std::invalid_argument("No room with this number.\n");   
}

void Hotel::registerGuestInRoom(int number, const UnavailablePeriod& reg) {
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

void Hotel::printFreeRoomsForDate(const Date& date) {
    for (auto& room : rooms) {
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

void Hotel::busyEnquiry(const Date& begin, const Date& end) {
    if (begin > end) {
        std::cerr<<("The end date is before the beginning one\n")<<std::endl;
        return;
    }

    char *filename = nullptr;
    strcpy(filename, "report-");
    strcpy(filename, begin.toString());

    std::ofstream out("filename.txt", std::ios::out);
    for (auto& room : rooms) {
        int days = room.busyInPeriod(begin, end);
        if (days != 0) {
            out<<room.getNumber()<<' '<<days<<'\n';
        }
    }
}

void Hotel::findRoom(const Date& date) {
    int minBeds = -1, numberOfRoom = -1;
    for (auto& room : rooms) {
        if (!room.isBusy(date)) {
            if (minBeds > room.getBedCount() || minBeds == -1) {
                minBeds = room.getBedCount();
                numberOfRoom = room.getNumber();
            }
        }
    }
    
    if (minBeds == -1) {
        std::cerr<<"No rooms left.\n";
    } else {
        std::cout<<"The room is number "<<numberOfRoom<<" with "<<minBeds<<" beds.\n";
    }
}


void Hotel::closeRoom(int number, const UnavailablePeriod& close) {
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

std::istream& operator>>(std::istream& in, Hotel &hotel) {
    int n;
    in>>n;

    hotel.rooms.resize(n);
    for (auto& room : hotel.rooms) {
        in>>room;
    }
    
    return in;
}

std::ostream& operator<<(std::ostream& out, const Hotel &hotel) {
    int n = hotel.rooms.size();
    out<<n<<'\n';

    for (auto room : hotel.rooms) {
        out<<room<<'\n';
    }

    return out;
}
