#include <iostream>
#include "fraction.h"
#include "matrix.h"
#include "utils.h"
using namespace std;

int main() {
    try {
        int a[] = {5, -1, 3, 8};
        cout << "Min int: " << findMinElement(a, 4) << "\n";

        double d[] = {1.5, -3.2, 0.7};
        cout << "Min double: " << findMinElement(d, 3) << "\n";

        Fraction f[] = {Fraction(1, 3), Fraction(2, 5), Fraction(-1, 2)};
        cout << "Min fraction: " << findMinElement(f, 3) << "\n";

        Matrix<int> A(2, 2), B(2, 2);
        cout << "\nEnter matrix A:\n"; cin >> A;
        cout << "Enter matrix B:\n"; cin >> B;

        cout << "\nA + B:\n" << A + B;
        cout << "\nA - B:\n" << A - B;
        cout << "\nA * B:\n" << A * B;

    } catch (const MatrixException& ex) {
        cerr << "Matrix exception: " << ex.what() << endl;
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}