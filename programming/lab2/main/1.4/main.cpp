#include "header.h"

int main() {
    Node* list = nullptr;

    ifstream fin("res/input.txt");
    if (!fin) {
        cerr << "Не вдалося відкрити файл input.txt" << endl;
        return 1;
    }

    int num;
    while (fin >> num) {
        append(list, num);
    }
    fin.close();

    int total = count(list);
    int rows = (total + n - 1) / n;

    int** matrix = create_matrix(rows, n);
    fill_matrix_from_list(list, matrix, rows, n);

    replace_positive_with_sqrt(matrix, rows, n);
    int* max_arr = max_in_rows(matrix, rows, n);

    ofstream fout("res/output.txt");
    fout << "Оброблена матриця:\n";
    print_matrix(matrix, rows, n, fout);

    fout << "\nМаксимальні елементи по кожному рядку:\n";
    print_array(max_arr, rows, fout);
    fout.close();

    delete_matrix(matrix, rows);
    delete[] max_arr;
    clear(list);

    cout << "Результат записано у файл output.txt\n";
    return 0;
}
