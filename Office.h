#ifndef OFFICE_H
#define OFFICE_H

#include "Room.h"

class Office : public Room {
public:
    // Enum for office types
    enum OfficeType { None, CoordinatorOffice, StandardOffice, SharedOfficeFor2People, SharedOfficeFor3People, SharedOfficeFor10People };

private:
    OfficeType type; // Type of office
    int numberOfPeople; // Number of people in the office

public:
    // Default constructor
    Office();

    // Constructor that sets the name, floor, type, and number of people
    Office(const char* name, int floor, OfficeType type, int numberOfPeople);

    // Getter for OfficeType
    OfficeType getOfficeType() const;
    // Setter for OfficeType
    void setOfficeType(OfficeType type);

    // Getter for numberOfPeople
    int getNumberOfPeople() const;
    // Setter for numberOfPeople
    void setNumberOfPeople(int number);

    // Checks if the office is full
    bool isFull() const;

    // Gets the capacity of the office based on its type
    int getCapacity() const;

    // Prints out the room details
    void printRoom() const override;

    // Convert OfficeType enum to string
    const char* officeTypeToString(OfficeType) const;
};

#endif // OFFICE_H
