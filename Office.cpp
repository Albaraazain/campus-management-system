#include "Office.h"
using namespace std;

// Default constructor sets name and floor to defaults, type to None, and number of people to 0
Office::Office() : Room(), type(None), numberOfPeople(0) {}

// Constructor that initializes name, floor, type, and number of people
Office::Office(const char* name, int floor, OfficeType type, int numberOfPeople)
        : Room(name, floor), type(type), numberOfPeople(numberOfPeople) {}

// Getter for OfficeType
Office::OfficeType Office::getOfficeType() const {
    return type;
}

// Setter for OfficeType
void Office::setOfficeType(OfficeType type) {
    this->type = type;
}

// Getter for numberOfPeople
int Office::getNumberOfPeople() const {
    return numberOfPeople;
}

// Setter for numberOfPeople
void Office::setNumberOfPeople(int number) {
    numberOfPeople = number;
}

// Checks if the office is full
bool Office::isFull() const {
    return numberOfPeople >= getCapacity();
}

// Gets the capacity of the office based on its type
int Office::getCapacity() const {
    switch (type) {
        case None: return 0;
        case CoordinatorOffice: return 1;
        case StandardOffice: return 1;
        case SharedOfficeFor2People: return 2;
        case SharedOfficeFor3People: return 3;
        case SharedOfficeFor10People: return 10;
        default: return 0;
    }
}

// Converts OfficeType enum to string
const char* Office::officeTypeToString(OfficeType officeType) const {
    switch (officeType) {
        case CoordinatorOffice:
            return "Coordinator Office";
        case StandardOffice:
            return "Standard Office";
        case SharedOfficeFor2People:
            return "Shared office for 2 people";
        case SharedOfficeFor3People:
            return "Shared office for 3 people";
        case SharedOfficeFor10People:
            return "Shared office for 10 people";
        default:
            return "Unknown office type";
    }
}

// Prints out the room details including office info
void Office::printRoom() const {
    cout << "Office name = " << roomName << endl;
    cout << "Office floor number = " << floorNumber << endl;
    cout << "Office type = " << officeTypeToString(type) << endl;
    cout << "Number of people in office = " << numberOfPeople << endl;
    cout << "Office capacity = " << getCapacity() << endl;
    cout << "Office is " << (isFull() ? "full" : "not full") << endl;
}
