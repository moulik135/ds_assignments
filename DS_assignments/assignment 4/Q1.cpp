#include<iostream>
using namespace std;

#define MAX 5

class Queue {
    int arr[MAX], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == MAX - 1;
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is Full\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        cout << "Deleted: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }
    void peek() {
        if (isEmpty()) cout << "Queue is Empty\n";
        else cout << "Front: " << arr[front] << endl;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, val;
    do {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Check Empty\n6.Check Full\n7.Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: cout << (q.isEmpty() ? "Queue is Empty\n" : "Queue is not Empty\n"); break;
            case 6: cout << (q.isFull() ? "Queue is Full\n" : "Queue is not Full\n"); break;
        }
    } while (choice != 7);
    return 0;
}
