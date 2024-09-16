#include<iostream>
using namespace std;

// Function to display an array
void displayArray(int arr[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to find the average of array elements
double findAverage(int arr[], int size) {
    double sum = 0;

    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }

    return sum / size;
}

// Function to insert an element into an array
void insertElement(int arr[], int& size, int position, int element) {
    if (position < 0 || position > size) {
        cout << "Invalid position for insertion." << endl;
        return;
    }

    for (int i = size; i > position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position] = element;
    size++;
}

// Function to delete an element from an array
void deleteElement(int arr[], int& size, int position) {
    if (position < 0 || position >= size) {
        cout << "Invalid position for deletion." << endl;
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
}

int main() {
    const int maxSize = 100;
    int arr[maxSize];
    int size, position, element;

    // Task 1: Display an array
    cout << "Enter the size of the array: ";
    cin >> size;

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    displayArray(arr, size);

    // Task 2: Find the average of array elements
    double average = findAverage(arr, size);
    cout << "Average of array elements: " << average << endl;

    // Task 3: Insert an element into an array
    cout << "Enter the position to insert the element: ";
    cin >> position;

    cout << "Enter the element to be inserted: ";
    cin >> element;

    insertElement(arr, size, position, element);

    displayArray(arr, size);

    // Task 4: Delete an element from an array
    cout << "Enter the position to delete the element: ";
    cin >> position;

    deleteElement(arr, size, position);

    displayArray(arr, size);

    return 0;
}
