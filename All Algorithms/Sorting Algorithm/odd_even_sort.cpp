#include <iostream>

void oddEvenSort(int arr[], int n) {
    bool sorted = false; 
// Initialize as unsorted

    while (!sorted) {
        sorted = true;

        // Perform the odd-indexed element comparisons and swaps
        for (int i = 1; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false; // Set the flag to indicate unsorted
            }
        }

        // Perform the even-indexed element comparisons and swaps
        for (int i = 0; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                sorted = false; // Set the flag to indicate unsorted
            }
        }
    }
}

int main() {
    int arr[] = {5, 2, 9, 3, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    oddEvenSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
