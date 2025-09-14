#include <iostream>
using namespace std;

int partition(int arr[], int low, int high, int &swapCount) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
            swapCount++;
        }
    }
    swap(arr[i + 1], arr[high]);
    swapCount++;
    return i + 1;
}

void quickSort(int arr[], int low, int high, int &swapCount, int n) {
    if (low < high) {
        int pi = partition(arr, low, high, swapCount);

        cout << "Partition at index " << pi << ": ";
        for (int k = 0; k < n; k++) cout << arr[k] << " ";
        cout << endl;

        quickSort(arr, low, pi - 1, swapCount, n);
        quickSort(arr, pi + 1, high, swapCount, n);
    }
}

int insertionSort(int arr[], int n) {
    int swapCount = 0;
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            swapCount++;
            j--;
        }
        arr[j + 1] = key;
    }
    return swapCount;
}

int main() {
    cout << "Steven Saavedra" << endl;
    int arr[] = {35, 12, 43, 8, 51, 27, 4, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int quickArr[] = {35, 12, 43, 8, 51, 27, 4, 19};
    int swapCountQuick = 0;

    cout << "Quick Sort Steps:\n";
    quickSort(quickArr, 0, n - 1, swapCountQuick, n);

    cout << "\nSorted Array (Quick Sort): ";
    for (int i = 0; i < n; i++) cout << quickArr[i] << " ";
    cout << "\nTotal Quick Sort swaps: " << swapCountQuick << endl;

    int insertionArr[] = {35, 12, 43, 8, 51, 27, 4, 19};
    int swapCountInsertion = insertionSort(insertionArr, n);

    cout << "\nSorted Array (Insertion Sort): ";
    for (int i = 0; i < n; i++){

        cout << insertionArr[i] << " ";

    } 
    cout << "\nTotal Insertion Sort swaps: " << swapCountInsertion << endl;

    return 0;
}
