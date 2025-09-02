#include <iostream>
#include <algorithm>
using namespace std;

int countDistinct(int arr[], int n) {
    sort(arr, arr + n);
    int count = 1;  
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            count++;
    }
    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;
    return 0;
}
