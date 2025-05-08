/*A financial analytics company is working on a system that processes large volumes of sorted numerical
data from different sources. The challenge is to efficiently combine two independently sorted datasets
into a single, fully sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted
arrays of different sizes and merges them into a new dynamically allocated array while maintaining
the sorted order. The system should read input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory.*/
#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a new dynamically allocated array
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int& mergedSize) {
    mergedSize = size1 + size2;
    int* mergedArr = new int[mergedSize]; // Dynamically allocate memory

    int i = 0, j = 0, k = 0;
    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArr[k++] = arr1[i++];
        } else {
            mergedArr[k++] = arr2[j++];
        }
    }

    // Copy remaining elements if any
    while (i < size1) {
        mergedArr[k++] = arr1[i++];
    }

    while (j < size2) {
        mergedArr[k++] = arr2[j++];
    }

    return mergedArr; // Return the merged array
}

void displayArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {2, 4, 6, 8};
    int mergedSize;

    int* mergedArr = mergeSortedArrays(arr1, 4, arr2, 4, mergedSize);
    displayArray(mergedArr, mergedSize); // Output: 1 2 3 4 5 6 7 8

    delete[] mergedArr; // Free dynamically allocated memory
    return 0;
}

