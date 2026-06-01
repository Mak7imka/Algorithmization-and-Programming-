#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MatrixException : public runtime_error {
public:
    MatrixException(const string& message) : runtime_error(message) {}
};

class Matrix {
private:
    int rows, cols;
    vector<vector<int>> data;

public:
    Matrix(int r = 0, int c = 0) : rows(r), cols(c), data(r, vector<int>(c)) {}

    int& operator()(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw MatrixException("Invalid indices");
        return data[i][j];
    }

    int operator()(int i, int j) const {
        if (i < 0 || i >= rows || j < 0 || j >= cols)
            throw MatrixException("Invalid indices (const)");
        return data[i][j];
    }

    Matrix operator+(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw MatrixException("Matrix dimensions do not match for addition");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] + other(i, j);

        return result;
    }

    Matrix operator-(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols)
            throw MatrixException("Matrix dimensions do not match for subtraction");

        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                result(i, j) = data[i][j] - other(i, j);

        return result;
    }

    Matrix operator*(const Matrix& other) const {
        if (cols != other.rows)
            throw MatrixException("Matrices cannot be multiplied");

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < other.cols; ++j)
                for (int k = 0; k < cols; ++k)
                    result(i, j) += data[i][k] * other(k, j);

        return result;
    }

    friend istream& operator>>(istream& in, Matrix& m) {
        cout << "Enter the elements of the " << m.rows << "x" << m.cols << " matrix:\n";
        for (int i = 0; i < m.rows; ++i)
            for (int j = 0; j < m.cols; ++j)
                in >> m.data[i][j];
        return in;
    }

    friend ostream& operator<<(ostream& out, const Matrix& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j)
                out << m.data[i][j] << "\t";
            out << "\n";
        }
        return out;
    }

    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

void transformMatrix(Matrix& m) {
    for (int i = 0; i < m.getRows(); ++i)
        for (int j = 0; j < m.getCols(); ++j) {
            int value = m(i, j);
            if (value < 0 && value % 2 != 0)
                m(i, j) = value * 2;
        }
}

int main() {
    try {
        Matrix A(2, 3), B(2, 3);
        cin >> A >> B;

        cout << "\nMatrix A:\n" << A;
        cout << "Matrix B:\n" << B;

        transformMatrix(A);
        transformMatrix(B);

        cout << "\nAfter transformation:\n";
        cout << "A:\n" << A;
        cout << "B:\n" << B;

        Matrix C = A + B;
        cout << "\nSum of A and B:\n" << C;
        Matrix D = A - B;
        cout << "\nDifference of A and B:\n" << D;
        Matrix E = A * B;
        cout << "\nMultiplication of A and B:\n" << E;
    }
    catch (const MatrixException& ex) {
        cerr << "MatrixException: " << ex.what() << endl;
    }
    catch (const exception& ex) {
        cerr << "Standard exception: " << ex.what() << endl;
    }

    return 0;
}