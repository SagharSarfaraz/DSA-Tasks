//Lab_Task 08
//You are a software developer working for a library management system. The librarian  
//wants an undo feature when stacking books on a table. 
//Your task is to implement a stack-based system where books are added and removed  
//in a LIFO (Last In, First Out) manner. The program should allow users to dynamically  
//add, remove, and view books 
//Requirements: 
// Use a stack (Array) to manage books. 
//• The program should support the following operations: 
//• Push a book onto the stack (Add a new book). 
//• Pop a book from the stack (Remove the top book). 
//• Peek the top book (View the last added book). 
//• Display all books in stack order (Top to Bottom). 
//• Check if the stack is empty (No books left). 
//Submission Requirements 
//• Submit the report and source file, with comments explaining each function. 
//• Ensure the code compiles and runs without errors. 
//• Write test cases demonstrating all operations in the program. 
#include <iostream>
#include <string>
using namespace std;

class BookStack {
private:
	//Size of Array
    string books[10];   
    int top;

public:
    BookStack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == 9);
    }

    // Push book
    void push(string bookName) {
        if (isFull()) {
            cout << "Stack overflow, cannot add more books" << endl;
            return;
        }
        top++;
        books[top] = bookName;
        cout << "Book added: " << books[top] << endl;
    }

    // Pop book
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow, no book to remove" << endl;
            return;
        }
        cout << "Book removed: " << books[top] << endl;
        top--;
    }

    // Peek top book
    void peek() {
        if (isEmpty()) {
            cout << "No book in stack" << endl;
            return;
        }
        cout << "Top book: " << books[top] << endl;
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Books in Stack (Top to Bottom)" << endl;
        for (int i = top; i >= 0; i--) {
            cout << "- " << books[i] << endl;
        }
    }
};

int main() {
    BookStack ls;

    cout << "***** Library Book Stack Test *****" << endl;
    cout << "Is stack empty? " << (ls.isEmpty() ? "Yes\n\n" : "No\n\n");

    ls.push("Programming Fundamentals");
    ls.push("Object Oriented Programming");
    ls.push("Data Structures and Algorithms");

    ls.peek();
    ls.display();

    ls.pop();
    ls.peek();
    ls.display();

    ls.pop();
    ls.pop();
    ls.pop();

    cout << "Is stack empty? " << (ls.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
