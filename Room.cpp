#include "Room.h"
using namespace std;

// Default constructor, sets name to "Undefined" and floor to -1
Room::Room() : floorNumber(-1) {
    roomName = new char[10];
    strcpy(roomName, "Undefined");
}

// Constructor that sets the room name and floor number
Room::Room(const char* name, int floor) : floorNumber(floor) {
    roomName = new char[strlen(name) + 1];
    strcpy(roomName, name);
}

// Copy constructor to make a copy of another Room object
Room::Room(const Room& other) : floorNumber(other.floorNumber) {
    roomName = new char[strlen(other.roomName) + 1];
    strcpy(roomName, other.roomName);
}

// Assignment operator to assign one Room to another
Room& Room::operator=(const Room& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Clean up old memory
    delete[] roomName;

    // Copy new data
    roomName = new char[strlen(other.roomName) + 1];
    strcpy(roomName, other.roomName);
    floorNumber = other.floorNumber;

    return *this;
}

// Destructor to clean up dynamically allocated memory
Room::~Room() {
    delete[] roomName;
}

// Getter for roomName, marked as const because it doesn't change any member variables
const char* Room::getRoomName() const {
    return roomName;
}

// Setter for roomName
void Room::setRoomName(const char* name) {
    delete[] roomName;
    roomName = new char[strlen(name) + 1];
    strcpy(roomName, name);
}

// Getter for floorNumber, marked as const because it doesn't change any member variables
int Room::getFloorNumber() const {
    return floorNumber;
}

// Setter for floorNumber
void Room::setFloorNumber(int floor) {
    floorNumber = floor;
}

// Print room details
void Room::printRoom() const {
    cout << "Room name: " << roomName << ", Floor number: " << floorNumber << endl;
}
