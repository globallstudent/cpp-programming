/*  
     Asliddin Abdumannonov - U2310010
     Lab Assignement 13
*/




// First task
#include <iostream>
using namespace std;

// Function to read an m x n matrix
void readMatrix(int matrix[10][10], int m, int n) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];
}

// Function to display an m x n matrix
void displayMatrix(int matrix[10][10], int m, int n) {
    cout << "The matrix is:" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Function to find the sum of two matrices
void addMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Function to find the transpose of a matrix
void transposeMatrix(int matrix[10][10], int result[10][10], int m, int n) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            result[j][i] = matrix[i][j];
}

// Function to find the product of two matrices
void multiplyMatrices(int matrix1[10][10], int matrix2[10][10], int result[10][10], int m1, int n1, int m2, int n2) {
    if (n1 != m2) {
        cout << "Matrix multiplication not possible." << endl;
        return;
    }

    for (int i = 0; i < m1; ++i)
        for (int j = 0; j < n2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < n1; ++k)
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
}

int main() {
    int m, n;

    cout << "Enter the number of rows (m) and columns (n) for matrices: ";
    cin >> m >> n;

    int matrix1[10][10], matrix2[10][10], result[10][10];

    cout << "For Matrix 1:" << endl;
    readMatrix(matrix1, m, n);

    cout << "For Matrix 2:" << endl;
    readMatrix(matrix2, m, n);

    // Display the matrices
    displayMatrix(matrix1, m, n);
    displayMatrix(matrix2, m, n);

    // Find and display the sum of two matrices
    addMatrices(matrix1, matrix2, result, m, n);
    cout << "Sum of the matrices:" << endl;
    displayMatrix(result, m, n);

    // Find and display the transpose of a matrix
    int transpose[10][10];
    transposeMatrix(matrix1, transpose, m, n);
    cout << "Transpose of Matrix 1:" << endl;
    displayMatrix(transpose, n, m);

    // Find and display the product of two matrices
    int m2, n2;
    cout << "Enter the number of rows (m) and columns (n) for the second matrix: ";
    cin >> m2 >> n2;

    int matrix3[10][10], product[10][10];

    cout << "For Matrix 3:" << endl;
    readMatrix(matrix3, m2, n2);

    multiplyMatrices(matrix1, matrix3, product, m, n, m2, n2);
    cout << "Product of matrices:" << endl;
    displayMatrix(product, m, n2);

    return 0;
}


// Second task

#include <iostream>
using namespace std;

int main() {
    const int salesmen = 5;
    const int products = 3;

    int salesData[salesmen][products];

    // Read sales data for each salesman and each product
    for (int i = 0; i < salesmen; ++i) {
        cout << "Enter sales data for salesman " << i + 1 << ":" << endl;
        for (int j = 0; j < products; ++j) {
            cout << "Product " << j + 1 << ": ";
            cin >> salesData[i][j];
        }
    }

    // Calculate and display total sales by each salesman
    cout << "\nTotal sales by each salesman:" << endl;
    for (int i = 0; i < salesmen; ++i) {
        int totalSales = 0;
        for (int j = 0; j < products; ++j) {
            totalSales += salesData[i][j];
        }
        cout << "Salesman " << i + 1 << ": " << totalSales << endl;
    }

    // Calculate and display total sales of each item
    cout << "\nTotal sales of each item:" << endl;
    for (int j = 0; j < products; ++j) {
        int totalItemSales = 0;
        for (int i = 0; i < salesmen; ++i) {
            totalItemSales += salesData[i][j];
        }
        cout << "Product " << j + 1 << ": " << totalItemSales << endl;
    }

    return 0;
}
