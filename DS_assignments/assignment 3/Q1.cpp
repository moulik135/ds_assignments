#include <iostream>
using namespace std;

#define SIZE 5  

int stack[SIZE], top = -1;

void push(int value) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow " << value << endl;
    } else {
        top++;
        stack[top] = value;
        cout << value << " pushed into stack." << endl;
    }
}


void pop() {
    if (top == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << stack[top] << " popped from stack." << endl;
        top--;
    }
}


void peek() {
    if (top == -1) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}


void isEmpty() {
    if (top == -1)
        cout << "Stack is Empty." << endl;
    else
        cout << "Stack is not Empty." << endl;
}


void isFull() {
    if (top == SIZE - 1)
        cout << "Stack is Full." << endl;
    else
        cout << "Stack is not Full." << endl;
}


void display() {
    if (top == -1) {
        cout << "Stack is Empty!" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice, value;

    while (true) {
      
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter value: ";
            cin >> value;
            push(value);
        } 
        else if (choice == 2) {
            pop();
        } 
        else if (choice == 3) {
            peek();
        } 
        else if (choice == 4) {
            isEmpty();
        } 
        else if (choice == 5) {
            isFull();
        } 
        else if (choice == 6) {
            display();
        } 
        else if (choice == 7) {
            cout << "Exiting program..." << endl;
            break;
        } 
        else {
            cout << "stack is full aready " << endl;
        }
    }
    return 0;
}