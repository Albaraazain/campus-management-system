#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include <cstring>
#include "Room.h"
#include "Office.h"
#include "Classroom.h"

class Building {
private:
    char* buildingName; // name of the building
    int size; // size in square meters
    Room* rooms[100]; // array of room pointers
    int numberOfRooms; // how many rooms

public:
    // Default constructor
    Building();

    // Constructor to set the building name and size
    Building(const char* name, int size);

    // Copy constructor
    Building(const Building& other);

    // Assignment operator
    Building& operator=(const Building& other);

    // Destructor
    ~Building();

    // Getter for building name, const because it doesn't change the object
    const char* getBuildingName() const;
    // Setter for building name
    void setBuildingName(const char* name);

    // Getter for size, const because it doesn't change the object
    int getSize() const;
    // Setter for size
    void setSize(int size);

    // Getter for number of rooms, const because it doesn't change the object
    int getNumberOfRooms() const;

    // Add a new room to the building
    void addRoom(Room* newRoom);

    // Print building details
    void printBuilding() const;

    // Print all room details
    void printRooms() const;

    // Print rooms by type (1: Classroom, 2: Office)
    void printRoomsByType(int type) const;

    // Get number of classrooms
    int getNumberOfClassrooms() const;

    // Get total capacity of offices
    int getTotalCapacity() const;

    // Get number of offices
    int getNumberOfOffices() const;

    // Print available offices
    void printAvailableOffices() const;

    // Print suitable classrooms based on number of students
    void printSuitableClassrooms(int numberOfStudents) const;

    // Getter for rooms array, const because it doesn't change the object
    Room* const* getRooms() const;

    // Print total capacity of offices
    void printTotalCapacity() const;
};

#endif // BUILDING_H
