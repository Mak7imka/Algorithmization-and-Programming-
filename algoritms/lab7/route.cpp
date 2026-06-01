#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    const int m = 4, n = 5;
    int grid[m][n] = {
        {3, 2, 7, 4, 1},
        {1, 8, 10, 1, 5},
        {8, 6, 4, 3, 10},
        {2, 7, 4, 7, 3}
    };

    cout << "початкова матриця:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << grid[i][j] << "\t";
        cout << endl;
    }

    int dp[m][n];
    dp[0][0] = grid[0][0];

    for (int j = 1; j < n; j++)
        dp[0][j] = dp[0][j-1] + grid[0][j];

    for (int i = 1; i < m; i++)
        dp[i][0] = dp[i-1][0] + grid[i][0];

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
    }

    cout << "\nМаксимальна вага маршруту: " << dp[m-1][n-1] << endl;

    cout << "Матриця ваг маршруту:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << dp[i][j] << "\t";
        cout << endl;
    }

    return 0;
}
