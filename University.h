#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <cstring>
#include "Building.h"

class University {
private:
    char* universityName; // name of the university
    Building* buildings[20]; // array of building pointers, max 20
    int numberOfBuildings; // how many buildings

public:
    // Default constructor
    University();

    // Constructor that sets the university name
    University(const char* name);

    // Copy constructor
    University(const University& other);

    // Assignment operator
    University& operator=(const University& other);

    // Destructor
    ~University();

    // Getter for university name
    const char* getUniversityName() const;
    // Setter for university name
    void setUniversityName(const char* name);

    // Getter for number of buildings
    int getNumberOfBuildings() const;

    // Add a new building to the university
    void addBuilding(Building* newBuilding);

    // Print details of all buildings
    void printBuildings() const;

    // Print details of all rooms in all buildings
    void printRooms() const;

    // Print rooms by type (1: Classroom, 2: Office)
    void printRoomsByType(int type) const;

    // Print the total count of each type of room
    void printRoomTypeStatistics() const;

    // Print details of available offices in all buildings
    void printAvailableOffices() const;

    // Print the total capacity of all offices
    void printTotalCapacityOfOffices() const;

    // Print suitable classrooms based on the number of students
    void printSuitableClassrooms(int numberOfStudents) const;

    // Getter for buildings array
    Building* const* getBuildings() const;
};

#endif // UNIVERSITY_H
