#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>
using namespace std;

class Matrix {
public:
    Matrix(const vector<vector<int>> &input);
    int get_size() const;
    int get_value(int row, int col) const;
    void set_value(int row, int col, int value);
    Matrix operator+(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;
    int sum_diagonal_major() const;
    int sum_diagonal_minor() const;
    void swap_rows(int row1, int row2);
    void swap_cols(int col1, int col2);
private:
    vector<vector<int>> data;
};

#endif
