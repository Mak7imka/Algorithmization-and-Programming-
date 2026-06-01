#include <iostream>
#include "fraction.h"
#include "matrix.h"
#include "utils.h"

int main() {
    using namespace std;

    try {

        cout << "\n--- Тестування операцій з Matrix ---" << endl;
        Matrix<int> A(2, 2), B(2, 2);
        cout << "Введіть матрицю A (2x2 цілих чисел):\n";
        cin >> A;
        cout << "Введіть матрицю B (2x2 цілих чисел):\n";
        cin >> B;

        cout << "\n--- Тестування findMinElement ---" << endl;
        cout << "Мінімальний елемент в матриці A: " << A.findMinElement() << endl;
        cout << "Мінімальний елемент в матриці B: " << B.findMinElement() << endl;


        cout << "\nМатриця A:\n" << A;
        cout << "Матриця B:\n" << B;

        cout << "\nA + B:\n" << A + B;
        cout << "\nA - B:\n" << A - B;
        cout << "\nA * B:\n" << A * B;
        
        cout << "\n--- Тестування обробки помилок ---" << endl;
        Matrix<int> C(2, 3);
        cout << "A + C:\n" << A + C;

    } catch (const MatrixException& ex) {
        cerr << "Matrix error: " << ex.what() << endl;
    } catch (const std::invalid_argument& ex) {
        cerr << "wrong arg: " << ex.what() << endl;
    } catch (const std::exception& ex) {
        cerr << "error: " << ex.what() << endl;
    }

    return 0;
}