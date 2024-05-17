#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <cstring>

class Room {

protected:
    char* roomName;
    int floorNumber;
public:
    // Default constructor
    Room();

    // Parameterized constructor
    Room(const char* name, int floor);

    // Copy constructor
    Room(const Room& other);

    // Assignment operator
    Room& operator=(const Room& other);

    // Destructor
    ~Room();

    // Getter and setter for roomName
    const char* getRoomName() const;
    void setRoomName(const char* name);

    // Getter and setter for floorNumber
    int getFloorNumber() const;
    void setFloorNumber(int floor);

    virtual // Print room details
    void printRoom() const;
};

#endif // ROOM_H
