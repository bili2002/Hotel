#include <algorithm>
#include <iostream>

#include "room.h"
#include "string.h"

void Room::registerRoom(const UnavailablePeriod& reg) {
    bool intersecting = false;
    for (int i=0; i<unavailable.size(); i++) {
        UnavailablePeriod &curr = unavailable[i];
        if (curr.intersectWith(reg)) {
            intersecting = true;
        }
    }
    
    if (!intersecting) 
        unavailable.push_back(reg);
    else 
        throw std::invalid_argument("The room is already taken for the period.");
}

bool Room::isBusy(const Date& date) const {
    bool busy = false;
    for (auto curr : unavailable) {
        if (curr.aroundDate(date)) {
            busy = true;
            break;
        }
    }
    return busy;
}

bool Room::isBusy(const Date& begin, const Date& end) const {
    bool busy = false;
    for (auto curr : unavailable) {
        if (curr.aroundDate(begin) || curr.aroundDate(end)) {
            busy = true;
            break;
        }
    }
    return busy;
}

int Room::busyInPeriod(const Date& begin, const Date& end) const {
    int count = 0;

    for (auto curr : unavailable) {
        Date tempBeg = curr.getBeginDate();
        Date tempEnd = curr.getEndDate();

        if (begin < tempBeg && end >= tempBeg) {
            count += tempBeg.daysTo(std::min(end, tempEnd));
        } else if (begin.between(tempBeg, tempEnd)) {
            count += begin.daysTo(std::min(end, tempEnd));
        }
    }
    return count;
}

void Room::closeRoom(UnavailablePeriod closing) {
    for (int i=0; i<unavailable.size(); i++) {
        UnavailablePeriod& curr = unavailable[i];
        if (curr.intersectWith(closing)) {
            if (curr.isConstruction()) {
                closing.setBeginDate(std::min(closing.getBeginDate(), curr.getBeginDate()));
                closing.setEndDate(std::min(closing.getEndDate(), curr.getEndDate()));
            }
            unavailable.erase(i);
            i--;
        }
    }
    unavailable.push_back(closing);
}

void Room::freeRoom() {
    for (auto& curr : unavailable) {
        if (curr.aroundDate(Date::getCurrentDate())) {
            curr.freeEarlier(Date::getCurrentDate());
            return;
        } 
    }
    std::cerr<<"The room was not used today!\n";
}

int Room::getNumber() const {
    return number;
}

int Room::getBedCount() const {
    return bedCount;
};

std::istream& operator>>(std::istream& in, Room &room) {
    in>>room.number>>room.bedCount;

    int n; 
    in>>n;

    room.unavailable.resize(n);
    for (auto& curr : room.unavailable) {
        in>>curr;
    }

    return in;
}

std::ostream& operator<<(std::ostream& out, const Room &room) {
    out<<room.number<<' '<<room.bedCount<<' ';

    int n = room.unavailable.size();
    out<<n<<'\n';

    for (auto& curr : room.unavailable) {
        out<<curr<<'\n';
    }

    return out;
}
