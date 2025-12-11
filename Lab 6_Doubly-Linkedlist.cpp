//Task(Question of Lab 6 Daubly Linkedlist)
//You are requrid to implement a Menu driven C++ program using Doubly Linked List that Support the folloing Operation
// .....Inseration...
//1.Insert the student Record at the begining of the list
//2. Insert the student Record at the End of the list
//3.Insert at Student record at specific point or postion (indiux) in the list
//......Deletion Opreation.....
//1.Delete the student Record from the begining of the list
//2. Delete the student Record from the End of the list
//3.Delete the Student record at specific postion
//......Display Opreation
//1.Display all student record from start to end
//2.Display all student record from  end to start
//Each  student contain information
//Student ID
//Name
//Semester
//GPA
#include <iostream>
using namespace std;

// Structure for each student
struct Student {
    int id;
    string name;
    int semester;
    float gpa;
    Student* next;
    Student* prev;
};

// Doubly Linked List class
class StudentList {
private:
    Student* head;
    Student* tail;

public:
    StudentList() {
        head = NULL;
        tail = NULL;
    }

   
    // 1. Insert at beginning
    void insertAtBeginning(int id, string name, int semester, float gpa) {
        Student* newStudent = new Student();
        newStudent->id = id;
        newStudent->name = name;
        newStudent->semester = semester;
        newStudent->gpa = gpa;
        newStudent->next = head;
        newStudent->prev = NULL;

        if (head != NULL) {
            head->prev = newStudent;
        }
        head = newStudent;

        if (tail == NULL) {
            tail = newStudent;
        }
    }

    // 2. Insert at end
    void insertAtEnd(int id, string name, int semester, float gpa) {
        Student* newStudent = new Student();
        newStudent->id = id;
        newStudent->name = name;
        newStudent->semester = semester;
        newStudent->gpa = gpa;
        newStudent->next = NULL;
        newStudent->prev = tail;

        if (tail != NULL) {
            tail->next = newStudent;
        }
        tail = newStudent;

        if (head == NULL) {
            head = newStudent;
        }
    }

    // 3. Insert at specific position (1-based index)
    void insertAtPosition(int pos, int id, string name, int semester, float gpa) {
        if (pos <= 1) {
            insertAtBeginning(id, name, semester, gpa);
            return;
        }

        Student* temp = head;
        int count = 1;
        while (temp != NULL && count < pos - 1) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL || temp->next == NULL) {
            insertAtEnd(id, name, semester, gpa);
            return;
        }

        Student* newStudent = new Student();
        newStudent->id = id;
        newStudent->name = name;
        newStudent->semester = semester;
        newStudent->gpa = gpa;

        newStudent->next = temp->next;
        newStudent->prev = temp;
        temp->next->prev = newStudent;
        temp->next = newStudent;
    }

    // 1. Delete from beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Student* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        } else {
            tail = NULL;
        }
        delete temp;
        cout << "Deleted student from beginning." << endl;
    }

    // 2. Delete from end
    void deleteFromEnd() {
        if (tail == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Student* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
        cout << "Deleted student from end." << endl;
    }

    // 3. Delete from specific position (1-based index)
    void deleteFromPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Student* temp = head;
        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position does not exist." << endl;
            return;
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }

        delete temp;
        cout << "Deleted student from position " << pos << "." << endl;
    }

    // ===== DISPLAY =====
    // 1. Display from start to end
    void displayForward() {
        if (head == NULL) {
            cout << "No students in the list!" << endl;
            return;
        }
        Student* temp = head;
        cout << "Student List (Start to End):" << endl;
        while (temp != NULL) {
            cout << "ID: " << temp->id << ", Name: " << temp->name
                 << ", Semester: " << temp->semester << ", GPA: " << temp->gpa << endl;
            temp = temp->next;
        }
    }

    // 2. Display from end to start
    void displayBackward() {
        if (tail == NULL) {
            cout << "No students in the list!" << endl;
            return;
        }
        Student* temp = tail;
        cout << "Student List (End to Start):" << endl;
        while (temp != NULL) {
            cout << "ID: " << temp->id << ", Name: " << temp->name
                 << ", Semester: " << temp->semester << ", GPA: " << temp->gpa << endl;
            temp = temp->prev;
        }
    }
};


int main() {
    StudentList list;
    int choice, id, semester, pos;
    string name;
    float gpa;

    while (true) {
        cout << "\n======= Student Management System =======" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete from Beginning" << endl;
        cout << "5. Delete from End" << endl;
        cout << "6. Delete from Specific Position" << endl;
        cout << "7. Display Forward" << endl;
        cout << "8. Display Backward" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID, Name, Semester, GPA: ";
                cin >> id >> name >> semester >> gpa;
                list.insertAtBeginning(id, name, semester, gpa);
                break;

            case 2:
                cout << "Enter ID, Name, Semester, GPA: ";
                cin >> id >> name >> semester >> gpa;
                list.insertAtEnd(id, name, semester, gpa);
                break;

            case 3:
                cout << "Enter Position, ID, Name, Semester, GPA: ";
                cin >> pos >> id >> name >> semester >> gpa;
                list.insertAtPosition(pos, id, name, semester, gpa);
                break;

            case 4:
                list.deleteFromBeginning();
                break;

            case 5:
                list.deleteFromEnd();
                break;

            case 6:
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteFromPosition(pos);
                break;

            case 7:
                list.displayForward();
                break;

            case 8:
                list.displayBackward();
                break;

            case 9:
                cout << "Exiting Program." << endl;
                return 0;

            default:
                cout << "Invalid Choice. Try Again!" << endl;
        }
    }
}
