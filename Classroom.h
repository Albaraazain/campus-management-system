#ifndef CLASSROOM_H
#define CLASSROOM_H

#include "Room.h"

class Classroom : public Room {
private:
    int capacity;

public:
    // Default constructor
    Classroom();

    // Constructor that sets the name, floor, and capacity
    Classroom(const char* name, int floor, int capacity);

    // Getter for capacity
    int getCapacity() const;
    // Setter for capacity
    void setCapacity(int capacity);

    // Checks if the classroom can fit the number of students
    bool checkSuitability(int numberOfStudents) const;

    // Prints out the room details, including classroom-specific stuff
    void printRoom() const override;
};

#endif // CLASSROOM_H
