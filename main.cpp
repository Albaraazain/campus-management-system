#include <iostream>
#include "University.h"
#include "Building.h"
#include "Classroom.h"
#include "Office.h"
#include "limits"
using namespace std;

void displayMenu() {
    cout << endl;
    cout << "[1] Add a new building to the university" << endl;
    cout << "[2] Add a new room to a selected building" << endl;
    cout << "[3] Print the buildings in the university" << endl;
    cout << "[4] Print the rooms in each building in the university" << endl;
    cout << "[5] Print the rooms in each building in the university based on type" << endl;
    cout << "[6] Print the total number of classrooms and offices in the university" << endl;
    cout << "[7] Print the available offices in each building in the university" << endl;
    cout << "[8] Print the total capacity of all the offices" << endl;
    cout << "[9] Print the suitable classrooms in the university based on the given number of students" << endl;
    cout << "[0] Exit" << endl;
    cout << "Please enter your choice: ";
}

// Function to validate integer input
bool validateIntInput(int& input) {
    if (!(cin >> input)) {
        cin.clear(); // Clear the error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
        cout << "Invalid input! Returning to menu." << endl;
        return false;
    }
    return true;
}

// Function to add a new building
void addBuilding(University& university) {
    string name;
    int size;

    cout << "Please enter name of building: ";
    cin >> name;
    cout << "Please enter size of building: ";
    if (!validateIntInput(size)) {
        return;
    }

    Building* newBuilding = new Building(name.c_str(), size);
    university.addBuilding(newBuilding);
}

// Function to add a new room
void addRoom(University& university) {
    if (university.getNumberOfBuildings() == 0) {
        cout << "No buildings available. Add a building first." << endl;
        return;
    }

    university.printBuildings();
    int buildingIndex;
    cout << "Please enter the number of building to which the room should be added: ";
    if (!validateIntInput(buildingIndex) || buildingIndex < 1 || buildingIndex > university.getNumberOfBuildings()) {
        cout << "Invalid building number!" << endl;
        return;
    }

    int roomType;
    cout << "Please enter the type of room (1: Classroom/ 2: Office): ";
    if (!validateIntInput(roomType) || (roomType != 1 && roomType != 2)) {
        cout << "Invalid room type!" << endl;
        return;
    }

    string roomName;
    int floorNumber;
    cout << "Please enter the name of the new room: ";
    cin >> roomName;
    cout << "Please enter the floor number of the new room: ";
    if (!validateIntInput(floorNumber)) {
        return;
    }

    Building* selectedBuilding = university.getBuildings()[buildingIndex - 1];

    if (roomType == 1) { // If the room is a classroom
        int capacity;
        cout << "Please enter capacity of classroom: ";
        if (!validateIntInput(capacity)) {
            return;
        }
        Classroom* newClassroom = new Classroom(roomName.c_str(), floorNumber, capacity);
        selectedBuilding->addRoom(newClassroom);
    } else if (roomType == 2) { // If the room is an office
        int officeType, numberOfPeople;
        cout << "[1] Coordinator Office" << endl;
        cout << "[2] Standard Office" << endl;
        cout << "[3] Shared Office for 2 people" << endl;
        cout << "[4] Shared Office for 3 people" << endl;
        cout << "[5] Shared Office for 10 people" << endl;
        cout << "Please enter type of office: ";
        if (!validateIntInput(officeType) || officeType < 1 || officeType > 5) {
            cout << "Invalid office type!" << endl;
            return;
        }
        cout << "Please enter number of people in the office: ";
        if (!validateIntInput(numberOfPeople)) {
            return;
        }

        Office::OfficeType type = static_cast<Office::OfficeType>(officeType);
        Office* newOffice = new Office(roomName.c_str(), floorNumber, type, numberOfPeople);
        selectedBuilding->addRoom(newOffice);
    } else {
        cout << "Invalid room type!" << endl;
        return;
    }
}

int main() {
    University university("METU NCC"); // Creating university instance
    int choice;

    while (true) {
        displayMenu(); // Show the menu
        cin >> choice;

        switch (choice) {
            case 1:
                addBuilding(university);
                break;
            case 2:
                addRoom(university);
                break;
            case 3:
                university.printBuildings();
                break;
            case 4:
                university.printRooms();
                break;
            case 5:
                int type;
                cout << "Please enter type of room to display:\n[1] Classrooms\n[2] Offices" << endl;
                if (validateIntInput(type)) {
                    university.printRoomsByType(type);
                }
                break;
            case 6:
                university.printRoomTypeStatistics();
                break;
            case 7:
                university.printAvailableOffices();
                break;
            case 8:
                university.printTotalCapacityOfOffices();
                break;
            case 9:
                int numberOfStudents;
                cout << "Please enter number of students: ";
                if (validateIntInput(numberOfStudents)) {
                    university.printSuitableClassrooms(numberOfStudents);
                }
                break;
            case 0:
                cout << "Thank you for using the university campus management system!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
