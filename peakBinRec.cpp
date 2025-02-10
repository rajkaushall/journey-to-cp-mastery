#include <iostream>
using namespace std;

void findAllPeaks(int arr[], int low, int high, int n) {
    if (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid])) {
            cout << arr[mid] << " ";
        }

        // Recursively check the left half
        findAllPeaks(arr, low, mid - 1, n);

        // Recursively check the right half
        findAllPeaks(arr, mid + 1, high, n);
    }
}

void getPeakElements(int arr[], int n) {
    findAllPeaks(arr, 0, n - 1, n);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Peak elements: ";
    getPeakElements(arr, n);

    return 0;
}
