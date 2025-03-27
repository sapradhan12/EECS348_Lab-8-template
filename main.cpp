#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*
    loads 2 matrices from a file and stores them in 2 vectors
*/
bool loadMatrices(const string &filename, int &n, vector<vector<int>> &matrix1, vector<vector<int>> &matrix2) {
    ifstream infile(filename);

    infile >> n;

    matrix1.resize(n, vector<int>(n));
    matrix2.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            infile >> matrix2[i][j];
        }
    }

    infile.close();
    return true;
}

/*
    prints a matrix with aligned columns
*/
void printMatrix(const vector<vector<int>> &matrix) {
    for (const auto &row : matrix) {
        for (int num : row) {
            cout << setw(5) << num;
        }
        cout << endl;
    }
}

/*
    adds 2 matrices
 */
vector<vector<int>> addMatrices(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
    int n = m1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return result;
}

/*
    multiplies 2 matrices
 */
vector<vector<int>> multiplyMatrices(const vector<vector<int>> &m1, const vector<vector<int>> &m2) {
    int n = m1.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }
    return result;
}


//FIX
/**
 * @brief Calculates the sum of the main and secondary diagonal elements of a matrix.
 *
 * If the matrix has an odd size, the center element is not double-counted.
 *
 * @param matrix The matrix to calculate the diagonal sums.
 * @return The sum of the main and secondary diagonals.
 */
int sumDiagonals(const vector<vector<int>> &matrix) {
    int n = matrix.size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
        sum += matrix[i][n - 1 - i];
    }
    // If n is odd, subtract the center element once (it was added twice).
    if(n % 2 == 1) {
        sum -= matrix[n/2][n/2];
    }
    return sum;
}

/*
    swap 2 rows in a matrix
 */
void swapMatrixRows(vector<vector<int>> &matrix, int row1, int row2) {
    int n = matrix.size();
    if (row1 >= 0 && row1 < n && row2 >= 0 && row2 < n) {
        vector<int> temp = matrix[row1];
        matrix[row1] = matrix[row2];
        matrix[row2] = temp;
    } else {
        cout << "Invalid row indices provided." << endl;
    }
}

/*
    swap 2 columns in a matrix
 */
void swapMatrixColumns(vector<vector<int>> &matrix, int col1, int col2) {
    int n = matrix.size();
    if(n == 0) return;
    if (col1 >= 0 && col1 < matrix[0].size() && col2 >= 0 && col2 < matrix[0].size()) {
        for (int i = 0; i < n; i++) {
            int temp = matrix[i][col1];
            matrix[i][col1] = matrix[i][col2];
            matrix[i][col2] = temp;
        }
    } else {
        cout << "Invalid column indices provided." << endl;
    }
}

/*
    update an element at a specific row and column position in a matrix
 */
void updateMatrixElement(vector<vector<int>> &matrix, int row, int col, int newValue) {
    int n = matrix.size();
    if(n == 0) return;
    if (row >= 0 && row < n && col >= 0 && col < matrix[0].size()) {
        matrix[row][col] = newValue;
    } else {
        cout << "Invalid indices provided." << endl;
    }
}

/*
    the main function, through which the entire program runs
*/
int main() {
    string filename;
    cout << "Enter the name of the input file: ";
    getline(cin, filename);  // Use getline to support filenames with spaces

    int n;
    vector<vector<int>> matrix1, matrix2;
    
    // Load the matrices from the file.
    if (!loadMatrices(filename, n, matrix1, matrix2)) {
        return 1;
    }
    
    cout << "\nFirst Matrix:" << endl;
    printMatrix(matrix1);
    
    cout << "\nSecond Matrix:" << endl;
    printMatrix(matrix2);
    
    // Add the two matrices.
    vector<vector<int>> sumMatrix = addMatrices(matrix1, matrix2);
    cout << "\nSum of Matrices:" << endl;
    printMatrix(sumMatrix);
    
    // Multiply the two matrices.
    vector<vector<int>> productMatrix = multiplyMatrices(matrix1, matrix2);
    cout << "\nProduct of Matrices:" << endl;
    printMatrix(productMatrix);
    
    // Sum of diagonal elements of the first matrix.
    int diagSum = sumDiagonals(matrix1);
    cout << "\nSum of main and secondary diagonal elements of the first matrix: " << diagSum << endl;
    
    // Swap two rows of the first matrix (example: swap row 0 and row 1).
    swapMatrixRows(matrix1, 0, 1);
    cout << "\nFirst Matrix after swapping row 0 and row 1:" << endl;
    printMatrix(matrix1);
    
    // Swap two columns of the first matrix (example: swap column 0 and column 1).
    swapMatrixColumns(matrix1, 0, 1);
    cout << "\nFirst Matrix after swapping column 0 and column 1:" << endl;
    printMatrix(matrix1);
    
    // Update an element in the first matrix (example: update element at (0,0) to 99).
    updateMatrixElement(matrix1, 0, 0, 99);
    cout << "\nFirst Matrix after updating element at (0,0) to 99:" << endl;
    printMatrix(matrix1);
    
    return 0;
}