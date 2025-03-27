#include "matrix.hpp"
#include <algorithm>

Matrix::Matrix(const vector<vector<int>> &input) : data(input) {}

int Matrix::get_size() const {
    return data.size();
}

int Matrix::get_value(int row, int col) const {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of range");
    return data[row][col];
}

void Matrix::set_value(int row, int col, int value) {
    if (row < 0 || row >= get_size() || col < 0 || col >= get_size())
        throw std::out_of_range("Index out of range");
    data[row][col] = value;
}

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

int Matrix::sum_diagonal_major() const {
    int n = get_size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][i];
    }
    return sum;
}

int Matrix::sum_diagonal_minor() const {
    int n = get_size();
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i][n - 1 - i];
    }
    return sum;
}

void Matrix::swap_rows(int row1, int row2) {
    int n = get_size();
    if (row1 < 0 || row1 >= n || row2 < 0 || row2 >= n)
        throw std::out_of_range("Row index out of range");
    std::swap(data[row1], data[row2]);
}

void Matrix::swap_cols(int col1, int col2) {
    int n = get_size();
    if (n == 0) return;
    if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
        throw std::out_of_range("Column index out of range");
    for (int i = 0; i < n; i++) {
        std::swap(data[i][col1], data[i][col2]);
    }
}