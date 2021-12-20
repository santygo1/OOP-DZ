#pragma once

#include <iostream>
#include "Hotel.h"
#include "Room.h"

int main()
{
    
    setlocale(LC_ALL, "rus");

    Hotel* hotel = new Hotel("Мой отель");
    hotel->addRoom(new Room(1));
    hotel->addRoom(new Room(1));
    hotel->addRoom(new Room(2));
    hotel->getRoom(2)->reserveBy(new Visitor("Jack",101,21));
    std::cout << hotel->getRoom(1)->getRoomNumber() << std::endl;

    Hotel* hotel1 = new Hotel(*hotel);

    hotel->removeRoom(1);
    std::cout << hotel1->getRoomsCount() << std::endl;

    std::cout << hotel->getRoom(2)->getReservation()->getRoomNumber() << std::endl;
    std::cout << hotel->getRoom(2)->getReservation()->getVisitor()->getName()<< std::endl;
    hotel->removeRoom(2);

    delete hotel;
    delete hotel1;
}