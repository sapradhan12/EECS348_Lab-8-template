#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;

//returns the size of a square matrix represented as a 2D vector
int get_size(const vector<vector<int>> &matrix) {
    return matrix.size();
}

//retrieves the value at a specified row and column from the 2D vector
int get_value(const vector<vector<int>> &matrix, int row, int col) {
    int n = get_size(matrix);
    if (row < 0 || row >= n || col < 0 || col >= n)
        throw std::out_of_range("Index out of range");
    return matrix[row][col];
}

//sets the value at a specified row and column in the 2D vector
void set_value(vector<vector<int>> &matrix, int row, int col, int value) {
    int n = get_size(matrix);
    if (row < 0 || row >= n || col < 0 || col >= n)
        throw std::out_of_range("Index out of range");
    matrix[row][col] = value;
}

//adds two 2D vectors element-wise and returns the resulting 2D vector
vector<vector<int>> add_matrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2) {
    int n = get_size(mat1);
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

// Multiplies two 2D vector and returns the resulting 2D vector.
vector<vector<int>> multiply_matrices(const vector<vector<int>> &mat1, const vector<vector<int>> &mat2) {
    int n = get_size(mat1);
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

//calculates the sum of the main diagonal of the 2D vector
int sum_diagonal_major(const vector<vector<int>> &matrix) {
    int n = get_size(matrix);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

//calculates the sum of the secondary diagonal of the 2D vector
int sum_diagonal_minor(const vector<vector<int>> &matrix) {
    int n = get_size(matrix);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += matrix[i][n - 1 - i];
    }
    return sum;
}

//swaps two rows in a 2D vector
void swap_rows(vector<vector<int>> &matrix, int row1, int row2) {
    int n = get_size(matrix);
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
        throw std::out_of_range("Row index out of range");
    swap(matrix[row1], matrix[row2]);
}

//swaps 2 columns in a 2D vector
void swap_cols(vector<vector<int>> &matrix, int col1, int col2) {
    int n = get_size(matrix);
    if (n == 0) return;
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
        throw std::out_of_range("Column index out of range");
    for (int i = 0; i < n; i++) {
        swap(matrix[i][col1], matrix[i][col2]);
    }
}