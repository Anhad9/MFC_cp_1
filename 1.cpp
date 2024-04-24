#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

double timeSortingAlgorithm(void (*sortingAlgorithm)(int[], int), int arr[], int size) {
    auto start = high_resolution_clock::now();
    sortingAlgorithm(arr, size);
    auto stop = high_resolution_clock::now();
    return duration_cast<duration<double>>(stop - start).count();
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int* arr = new int[n];
    cout << "Enter " << n << " integers separated by space: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    void (*sortingAlgorithms[])(int[], int) = {selectionSort, bubbleSort, insertionSort};
    string algorithmNames[] = {"Selection Sort", "Bubble Sort", "Insertion Sort"};

    for (int i = 0; i < sizeof(sortingAlgorithms) / sizeof(sortingAlgorithms[0]); i++) {
        int* tempArr = new int[n]; 
        for (int j = 0; j < n; ++j)
            tempArr[j] = arr[j];

        double timeTaken = timeSortingAlgorithm(sortingAlgorithms[i], tempArr, n);
        cout << "Time taken for " << algorithmNames[i] << ": " << timeTaken << " seconds" << endl;
        delete[] tempArr;
    }
    delete[] arr;

    return 0;
}
