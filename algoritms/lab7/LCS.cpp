#include <iostream>
#include <string>
#include <iomanip> // для форматування виводу таблиці
using namespace std;

int main() {
    string X = "ABCABAAC";
    string Y = "BACCBCA";
    cout << "X: " << X << endl;
    cout << "Y: " << Y << endl;

    const int n = 8; 
    const int m = 7; 

    int dp[n+1][m+1] = {0};
    char dir[n+1][m+1] = {0};  

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                dir[i][j] = 'D'; 
            } else if (dp[i-1][j] >= dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                dir[i][j] = 'U'; 
            } else {
                dp[i][j] = dp[i][j-1];
                dir[i][j] = 'L'; 
            }
        }
    }


    cout << "\nДовжина LCS: " << dp[n][m] << endl;

    string lcs = "";
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (dir[i][j] == 'D') {
            lcs = X[i-1] + lcs;
            i--; j--;
        } else if (dir[i][j] == 'U') {
            i--;
        } else {
            j--;
        }
    }

    cout << "Найбільша загальна підпослідовність: " << lcs << endl;
    return 0;
}