#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>
#include <stdexcept>
using namespace std;

vector<vector<int>> create_matrix(const vector<vector<int>> &input);
int get_size(const vector<vector<int>> &data);
int get_value(const vector<vector<int>> &data, int row, int col);
void set_value(vector<vector<int>> &data, int row, int col, int value);
vector<vector<int>> add_matrices(const vector<vector<int>> &data1, const vector<vector<int>> &data2);
vector<vector<int>> multiply_matrices(const vector<vector<int>> &data1, const vector<vector<int>> &data2);
int sum_diagonal_major(const vector<vector<int>> &data);
int sum_diagonal_minor(const vector<vector<int>> &data);
void swap_rows(vector<vector<int>> &data, int row1, int row2);
void swap_cols(vector<vector<int>> &data, int col1, int col2);

#endif
