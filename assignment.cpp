#include "matrix.hpp"
#include <algorithm>

//creates a matrix object by copying the provide 2D vector of integers
Matrix::Matrix(const vector<vector<int>> &input) : data(input) {}

//returns the size of the square matrix
int Matrix::get_size() const {
    return data.size();
}

//retrieves the value at a specified row and column and throws an exception if the inputted row and column are out of bounds
int Matrix::get_value(int row, int col) const {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of range");
    return data[row][col];
}

//sets the value at a specified row and column and throws an exception if the indices are invalid
void Matrix::set_value(int row, int col, int value) {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of range");
    data[row][col] = value;
}

//adds two matrices element-wise
Matrix Matrix::operator+(const Matrix &other) const {
    int n = get_size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return Matrix(result);
}

//multiples 2 matrices
Matrix Matrix::operator*(const Matrix &other) const {
    int n = get_size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                result[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return Matrix(result);
}

//calculates the sum of the value of the matrix's main diagonal
int Matrix::sum_diagonal_major() const {
    int n = get_size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][i];
    }
    return sum;
}

//calculates the sum of the value of the matrix's secondary diagonal
int Matrix::sum_diagonal_minor() const {
    int n = get_size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][n - 1 - i];
    }
    return sum;
}

//swaps the 2 specified rows of the matrix, throwing an exception if the row indices are invalid
void Matrix::swap_rows(int row1, int row2) {
    int n = get_size();
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
        throw std::out_of_range("Row index out of range");
    std::swap(data[row1], data[row2]);
}

//swaps the 2 specified columns of the matrix, throwing an exception if the column indices are invalid
void Matrix::swap_cols(int col1, int col2) {
    int n = get_size();
    if (n == 0) return;
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
        throw std::out_of_range("Column index out of range");
    for (int i = 0; i < n; i++) {
        std::swap(data[i][col1], data[i][col2]);
    }
}