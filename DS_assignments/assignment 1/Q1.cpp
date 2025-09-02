#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX];
int size = 0;

void createArray() {
    cout << "Enter number of elements: ";
    cin >> size;
    if (size > MAX) {
        cout << "Size exceeds maximum allowed!\n";
        size = 0;
        return;
    }
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

void displayArray() {
    if (size == 0) {
        cout << "Array is empty!\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement() {
    if (size == MAX) {
        cout << "Array is full! Cannot insert.\n";
        return;
    }
    int pos, element;
    cout << "Enter position (1 to " << size + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > size + 1) {
        cout << "Invalid position!\n";
        return;
    }
    cout << "Enter element: ";
    cin >> element;
    for (int i = size; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = element;
    size++;
    cout << "Element inserted.\n";
}

void deleteElement() {
    if (size == 0) {
        cout << "Array is empty! Cannot delete.\n";
        return;
    }
    int pos;
    cout << "Enter position (1 to " << size << "): ";
    cin >> pos;
    if (pos < 1 || pos > size) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    size--;
    cout << "Element deleted.\n";
}

void linearSearch() {
    if (size == 0) {
        cout << "Array is empty! Cannot search.\n";
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << i + 1 << ".\n";
            return;
        }
    }
    cout << "Element not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n--- ARRAY OPERATIONS MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(); break;
            case 2: displayArray(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Exiting program.\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
