#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <string>
#include <vector>

bool loadMatrices(const std::string &filename, int &n, std::vector<std::vector<int>> &matrix1, std::vector<std::vector<int>> &matrix2);
void printMatrix(const std::vector<std::vector<int>> &matrix);
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>> &m1, const std::vector<std::vector<int>> &m2);
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>> &m1, const std::vector<std::vector<int>> &m2);
int sumDiagonals(const std::vector<std::vector<int>> &matrix);
void swapMatrixRows(std::vector<std::vector<int>> &matrix, int row1, int row2);
void swapMatrixColumns(std::vector<std::vector<int>> &matrix, int col1, int col2);
void updateMatrixElement(std::vector<std::vector<int>> &matrix, int row, int col, int newValue);

#endif
