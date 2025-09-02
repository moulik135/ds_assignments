#include <iostream>
using namespace std;

int main() {
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    int arr[10][10];
    cout << "Enter elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> arr[i][j];

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++)
            rowSum += arr[i][j];
        cout << "Sum of row " << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++)
            colSum += arr[i][j];
        cout << "Sum of column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}
