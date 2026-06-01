#include <iostream>
using namespace std;

enum Month { January, February, March, April, May, June, July, August, September, October, November, December };

Month& operator++(Month& m) {
  m = (m == December) ? January : Month(m + 1);
  return m;
}

Month& operator--(Month& m) {
  m = (m == January) ? December : Month(m - 1);
  return m;
}

std::string getMonthName(Month m) {
  const string names[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};
  return names[m];
}

int main(void) {
  Month m = December;
  ++m;
  cout << "Month after December: " << getMonthName(m) << "\n";
  --m; 
  cout << "Months before January: " << getMonthName(m) << "\n";
  return 0;
}
