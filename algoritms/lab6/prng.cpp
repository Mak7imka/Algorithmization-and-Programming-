#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double dGet_A(int iNumber) {
    const double a_values[10] = {1.1, 5.2, 9.3, 4.4, 3.5, 7.6, 0.7, 2.8, 8.9, 6.0};
    return a_values[iNumber % 10];
}

int main() {
    double y_prev = 7.0;
    double y_current = 0.0;
    const double mu = 65.0;
    const double m = pow(2, 32);
    const int numbers_to_generate = 20;

    cout << fixed << setprecision(2); 
    
    cout << "Генератор псевдовипадкових чисел (лінійний конгруентний метод)\n";
    cout << "Початкові параметри:\n";
    cout << "y0 = " << y_prev << ", y1 = " << y_current << ", μ = " << mu << ", m = " << m << "\n\n";

    double x_current = y_current / m;
    cout << "Крок 1:\n";
    cout << "y1 = " << y_current << " (задане початкове значення)\n";
    cout << "x1 = " << y_current << " / " << m << " = " << x_current << "\n\n";


    for (int n = 1; n < numbers_to_generate; n++) {
        double sum = 0.0;
        for (int i = 0; i <= n; i++) {
            sum += dGet_A(i) * y_prev;
        }

        double y_next = fmod(sum + mu, m);

        double x_next = y_next / m;

        cout << "Крок " << n+1 << ":\n";
        cout << "y_" << n+1 << " = (Σ(a_i * y_" << n-1 << ") + μ) mod m = (" << sum << " + " << mu << ") mod " << m << " = " << y_next << "\n";
        cout << "x_" << n+1 << " = " << y_next << " / " << m << " = " << x_next << "\n\n";

        y_prev = y_current;
        y_current = y_next;
    }

    return 0;
}