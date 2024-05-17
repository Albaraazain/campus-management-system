#include "Classroom.h"
using namespace std;

// Default constructor. sets name and floor to defaults and capacity to -1
Classroom::Classroom() : Room(), capacity(-1) {}

// Constructor that initializes name, floor, and capacity
Classroom::Classroom(const char* name, int floor, int capacity)
        : Room(name, floor), capacity(capacity) {}

// Just returns the capacity
int Classroom::getCapacity() const {
    return capacity;
}

// Sets the capacity to the given value
void Classroom::setCapacity(int capacity) {
    this->capacity = capacity;
}

// Checks if the classroom can fit the number of students
bool Classroom::checkSuitability(int numberOfStudents) const {
    return capacity >= numberOfStudents;
}

// Prints out the room details includding classroom specific stuff
void Classroom::printRoom() const {
    cout << "Classroom name = " << roomName << endl;
    cout << "Classroom floor number = " << floorNumber << endl;
    cout << "Classroom capacity = " << capacity << endl;
}
