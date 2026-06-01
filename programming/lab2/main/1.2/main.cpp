#include <iostream>
#include <cmath>
using namespace std;

struct Point3D {
  double x, y, z;
};

double distance(const Point3D& p1, const Point3D& p2) {
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
}

int main(void) {
  Point3D p1, p2;
  
  cout << "Введіть координати першої точки (x y z): ";
  cin >> p1.x >> p1.y >> p1.z;


  cout << "Введіть координати другої точки (x y z): ";
  cin >> p2.x >> p2.y >> p2.z;
  
  // if (!(cin >> p1.x >> p1.y >> p1.z >> p2.x >> p2.y >> p2.z)) {
  //   cout << "Помилка вводу!";
  //   return 1;
  // }

  cout << "Відстань між точками: " << distance(p1, p2) << "\n";
  
  return 0;
}
