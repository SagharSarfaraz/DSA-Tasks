//Task
//.......Patient Management System...........
//Write a C++ Program using singly Linked where each Patient has:
//Patient ID
//Implement the Following Opreaation
//1.Insert a new Patient at the End
//2.Insert a Emergency Patient at Front
//3.Display all Patient

#include <iostream>
using namespace std;

struct Patient {
    int id;
    Patient* next;
};

class PatientList {
private:
    Patient* head; 
public:
    PatientList() {
        head = NULL;
    }

    // Insert at End
    void insertAtEnd(int id) {
        Patient* newNode = new Patient();
        newNode->id = id;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            return;
        }

        Patient* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at Front (Emergency Patient)
    void InsertAtFront(int id) {
        Patient* newNode = new Patient();  
        newNode->id = id;
        newNode->next = head;
        head = newNode;
    }

    // Display all patients
    void display() {
        if (head == NULL) {
            cout << "No Patient in the List" << endl;
            return;
        }

        Patient* temp = head;
        cout << "Patients in the List:" << endl;
        while (temp != NULL) {
            cout << temp->id << endl;
            temp = temp->next;
        }
    }
};

int main() {
    PatientList list;  
    int choice, id;

    while (true) {
        cout << "\n.......Patient Management System......." << endl;
        cout << "1. New Patient Insert at End" << endl;
        cout << "2. Emergency Patient at Front" << endl;
        cout << "3. Display all Patients" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Patient ID: ";
                cin >> id;
                list.insertAtEnd(id);
                break;

            case 2:
                cout << "Enter Patient ID: ";
                cin >> id;
                list.InsertAtFront(id);
                break;

            case 3:
                list.display();
                break;

            case 4:
                cout << "Exiting Program." << endl;
                return 0;

            default:
                cout << "Invalid Choice. Try Again." << endl;
        }
    }
}
