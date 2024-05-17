#include "University.h"
using namespace std;

// Default constructor, sets name to "Undefined" and number of buildings to 0
University::University() : numberOfBuildings(0) {
    universityName = new char[10];
    strcpy(universityName, "Undefined");
}

// Constructor that sets the university name
University::University(const char* name) : numberOfBuildings(0) {
    universityName = new char[strlen(name) + 1];
    strcpy(universityName, name);
}

// Copy constructor, makes a copy of another University object
University::University(const University& other) : numberOfBuildings(other.numberOfBuildings) {
    universityName = new char[strlen(other.universityName) + 1];
    strcpy(universityName, other.universityName);

    for (int i = 0; i < numberOfBuildings; ++i) {
        buildings[i] = new Building(*other.buildings[i]);
    }
}

// Assignment operator to assign one University to another
University& University::operator=(const University& other) {
    // Check for self-assignment
    if (this == &other) {
        return *this;
    }

    // Clean up old memory
    delete[] universityName;

    // Copy new data
    universityName = new char[strlen(other.universityName) + 1];
    strcpy(universityName, other.universityName);
    numberOfBuildings = other.numberOfBuildings;

    for (int i = 0; i < numberOfBuildings; ++i) {
        delete buildings[i];
        buildings[i] = new Building(*other.buildings[i]);
    }

    return *this;
}

// Destructor to clean up memory
University::~University() {
    delete[] universityName;
    for (int i = 0; i < numberOfBuildings; ++i) {
        delete buildings[i];
    }
}

// Getter for university name
const char* University::getUniversityName() const {
    return universityName;
}

// Setter for university name
void University::setUniversityName(const char* name) {
    delete[] universityName;
    universityName = new char[strlen(name) + 1];
    strcpy(universityName, name);
}

// Getter for number of buildings
int University::getNumberOfBuildings() const {
    return numberOfBuildings;
}

// Add a new building to the university
void University::addBuilding(Building* newBuilding) {
    if (numberOfBuildings < 20) { // check if there's room for another building
        buildings[numberOfBuildings++] = newBuilding; // add building and increment count
    }
}

// Print details of all buildings
void University::printBuildings() const {
    cout << "Buildings in " << universityName << " University:" << endl;
    for (int i = 0; i < numberOfBuildings; ++i) {
        cout << "[" << i + 1 << "] ";
        buildings[i]->printBuilding(); // use the building's print function
    }
}

// Print details of all rooms in all buildings
void University::printRooms() const {
    cout << "Rooms in " << universityName << " university:" << endl;
    for (int i = 0; i < numberOfBuildings; ++i) {
        Building* building = buildings[i];
        cout << "All rooms in " << building->getBuildingName() << " building:" << endl;
        building->printRooms(); // call building's print rooms function
        cout << endl;
    }
    cout << endl;
}

// Print rooms by type (1: Classroom, 2: Office)
void University::printRoomsByType(int type) const {
    if (type == 1) {
        cout << "Classrooms in " << universityName << " university:" << endl;
    } else if (type == 2) {
        cout << "Offices in " << universityName << " university:" << endl;
    }

    for (int i = 0; i < numberOfBuildings; ++i) {
        buildings[i]->printRoomsByType(type); // delegate to building's function
        cout << endl;
    }
    cout << endl;
}

// Print the total count of each type of room
void University::printRoomTypeStatistics() const {
    int classroomCount = 0;
    int officeCount = 0;

    for (int i = 0; i < numberOfBuildings; ++i) {
        classroomCount += buildings[i]->getNumberOfClassrooms();
        officeCount += buildings[i]->getNumberOfOffices();
    }

    cout << "Room Type statistics for " << universityName << " university:" << endl;
    cout << "Number of offices = " << officeCount << endl;
    cout << "Number of classrooms = " << classroomCount << endl;
    cout << endl;
}

// Print details of available offices in all buildings
void University::printAvailableOffices() const {
    cout << "Available offices in " << universityName << " university:" << endl;
    for (int i = 0; i < numberOfBuildings; ++i) {
        buildings[i]->printAvailableOffices();
    }
    cout << endl;
}

// Print the total capacity of all offices
void University::printTotalCapacityOfOffices() const {
    cout << "Office capacity in " << universityName << " university:" << endl;
    for (int i = 0; i < numberOfBuildings; ++i) {
        buildings[i]->printTotalCapacity(); // call the building's capacity function
    }
    cout << endl;
}

// Print suitable classrooms based on the number of students
void University::printSuitableClassrooms(int numberOfStudents) const {
    cout << "Suitable classes in " << universityName << " university for " << numberOfStudents << " students:" << endl << endl;
    for (int i = 0; i < numberOfBuildings; ++i) {
        buildings[i]->printSuitableClassrooms(numberOfStudents);
    }
    cout << endl;
}

// Getter for buildings array
Building* const* University::getBuildings() const {
    return buildings;
}
