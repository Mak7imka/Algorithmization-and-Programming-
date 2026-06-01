#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <stdexcept>

class MatrixException : public std::runtime_error {
public:
    MatrixException(const std::string& msg) : std::runtime_error(msg) {}
};

template <typename T>
class Matrix {
    int rows, cols;
    std::vector<std::vector<T>> data;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, std::vector<T>(c)) {}

    T& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw MatrixException("Invalid indices");
        return data[i][j];
    }

    const T& operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw MatrixException("Invalid indices (const)");
        return data[i][j];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw MatrixException("Addition: dimensions mismatch");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = data[i][j] + other(i, j);
        return res;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw MatrixException("Subtraction: dimensions mismatch");
        Matrix res(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                res(i, j) = data[i][j] - other(i, j);
        return res;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw MatrixException("Multiplication: invalid dimensions");
        Matrix res(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    res(i, j) += data[i][k] * other(k, j);
        return res;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }

    friend std::istream& operator>>(std::istream& in, Matrix& m) {
        for (int i = 0; i < m.rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                in >> m.data[i][j];
        return in;
    }

    friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j)
                out << m.data[i][j] << "\t";
            out << "\n";
        }
        return out;
    }
};

#endif