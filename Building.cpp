#include "Building.h"
using namespace std;

// Default constructor, sets name to "Undefined" and size to -1
Building::Building() : size(-1), numberOfRooms(0) {
    buildingName = new char[10];
    strcpy(buildingName, "Undefined");
}

// Constructor that sets the building name and size
Building::Building(const char* name, int size) : size(size), numberOfRooms(0) {
    buildingName = new char[strlen(name) + 1];
    strcpy(buildingName, name);
}

// Copy constructor, makes a copy of another Building object
Building::Building(const Building& other) : size(other.size), numberOfRooms(other.numberOfRooms) {
    buildingName = new char[strlen(other.buildingName) + 1];
    strcpy(buildingName, other.buildingName);

    for (int i = 0; i < numberOfRooms; ++i) {
        rooms[i] = other.rooms[i];
    }
}

// Assignment operator to assign one Building to another
Building& Building::operator=(const Building& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Clean up old memory
    delete[] buildingName;

    // Copy new data
    buildingName = new char[strlen(other.buildingName) + 1];
    strcpy(buildingName, other.buildingName);
    size = other.size;
    numberOfRooms = other.numberOfRooms;

    for (int i = 0; i < numberOfRooms; ++i) {
        rooms[i] = other.rooms[i];
    }

    return *this;
}

// Destructor to clean up memory
Building::~Building() {
    delete[] buildingName;
    for (int i = 0; i < numberOfRooms; ++i) {
        delete rooms[i];
    }
}

// Getter for building name
const char* Building::getBuildingName() const {
    return buildingName;
}

// Setter for building name
void Building::setBuildingName(const char* name) {
    delete[] buildingName;
    buildingName = new char[strlen(name) + 1];
    strcpy(buildingName, name);
}

// Getter for size
int Building::getSize() const {
    return size;
}

// Setter for size
void Building::setSize(int size) {
    this->size = size;
}

// Getter for number of rooms
int Building::getNumberOfRooms() const {
    return numberOfRooms;
}

// Add a new room to the building
void Building::addRoom(Room* newRoom) {
    if (numberOfRooms < 100) {
        rooms[numberOfRooms++] = newRoom;
    }
}

// Print building details
void Building::printBuilding() const {
    cout << "Building name = " << buildingName
              << endl << "Building size = " << size
              << endl << "Building number of rooms = " << numberOfRooms << endl << endl;
}

// Print all rooms in the building
void Building::printRooms() const {
    for (int i = 0; i < numberOfRooms; ++i) {
        rooms[i]->printRoom();
        cout << endl;
    }
}

// Print rooms by type (1: Classroom, 2: Office)
void Building::printRoomsByType(int type) const {
    if (type == 1) {
        cout << "All classrooms in " << buildingName << " building:" << endl;
    } else if (type == 2) {
        cout << "All offices in " << buildingName << " building:" << endl;
    }

    for (int i = 0; i < numberOfRooms; ++i) {
        Room* room = rooms[i];
        if (type == 1) { // Classrooms
            if (Classroom* classroom = dynamic_cast<Classroom*>(room)) {
                classroom->printRoom();
            }
        } else if (type == 2) { // Offices
            if (Office* office = dynamic_cast<Office*>(room)) {
                office->printRoom();
            }
        }
        cout << endl;
    }
}

// Print total capacity of offices in the building
void Building::printTotalCapacity() const {
    int totalCapacity = 0;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (Office* office = dynamic_cast<Office*>(rooms[i])) {
            totalCapacity += office->getCapacity();
        }
    }
    cout << "Office capacity in " << buildingName << " building = " << totalCapacity << endl;
}

// Get number of classrooms
int Building::getNumberOfClassrooms() const {
    int count = 0;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (dynamic_cast<Classroom*>(rooms[i])) {
            ++count;
        }
    }
    return count;
}

// Get total capacity of offices
int Building::getTotalCapacity() const {
    int totalCapacity = 0;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (Office* office = dynamic_cast<Office*>(rooms[i])) {
            totalCapacity += office->getCapacity();
        }
    }
    return totalCapacity;
}

// Get number of offices
int Building::getNumberOfOffices() const {
    int count = 0;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (dynamic_cast<Office*>(rooms[i])) {
            ++count;
        }
    }
    return count;
}

// Print available offices
void Building::printAvailableOffices() const {
    cout << "Available offices in " << buildingName << " building:" << endl;
    for (int i = 0; i < numberOfRooms; ++i) {
        if (Office* office = dynamic_cast<Office*>(rooms[i])) {
            if (!office->isFull()) {
                office->printRoom();
            }
        }
    }
    cout << endl;
}

// Print suitable classrooms given num of students
void Building::printSuitableClassrooms(int numberOfStudents) const {
    for (int i = 0; i < numberOfRooms; ++i) {
        if (Classroom* classroom = dynamic_cast<Classroom*>(rooms[i])) {
            if (classroom->checkSuitability(numberOfStudents)) {
                classroom->printRoom();
            }
        }
    }
}

// Getter for rooms array
Room* const* Building::getRooms() const {
    return rooms;
}
