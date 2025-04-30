#pragma once
#include <iostream>
#include <vector>
#include "DateTime.hpp"


class IBooking {
protected:
    std::vector <DateTimeRange> bookingSlots;
public:
    virtual bool book(const DateTimeRange &period) = 0;
    virtual ~IBooking() = default;
};

class IBilling {
protected:
    double price;
public:
    virtual ~IBilling() = default;
};

class Room : public IBooking, public IBilling {
private:
    unsigned int number;
public:
    Room(int number, float price) : number(number) {};

    bool isAvailable(const DateTimeRange &period) const {
        for (auto bookingSlot : bookingSlots)
        {
            if (period.overlaps(bookingSlot)) return false;
        }
        return true;
    }

    bool book(const DateTimeRange &period) override
    {
        if (!isAvailable(period)) { return false;}
    }
};

class Masseur : public IBooking{
private:
    std::string name;

public:
    Masseur(std::string name) : name(name) {};

    void book(DateTimeRange bookPeriod) {
        // правила бронрования для специалиста, наприммер, учитывать перерыв
        std::cout << "Специалист " << name << " забронирован " << std::endl;
        bookingSlots.push_back(bookPeriod);
    }
};

