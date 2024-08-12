
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int& comparisons, int& swaps) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        ++comparisons;
        while (j >= 0 && arr[j] > key) {
            ++comparisons;
            arr[j + 1] = arr[j];
            --j;
            ++swaps;
        }
        arr[j + 1] = key;
        if (j >= 0) ++swaps;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int comparisons = 0, swaps = 0;
    insertionSort(arr, n, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of swaps: " << swaps << endl;

    return 0;
}