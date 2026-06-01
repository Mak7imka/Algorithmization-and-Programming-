#include <iostream>
#include <cmath>
using namespace std;

class Point3D {
private:
    double x, y, z;

public:
    Point3D() : x(0), y(0), z(0) {}
    Point3D(double x, double y, double z) : x(x), y(y), z(z) {}

    void setX(const double xVal) { x = xVal; }
    void setY(const double yVal) { y = yVal; }
    void setZ(const double zVal) { z = zVal; }

    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    friend double operator-(const Point3D& a, const Point3D& b);
};

double operator-(const Point3D& a, const Point3D& b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2)); /* hypot(a.x - b.x, a.y - b.y, a.z - b.z); */
}

int main() {
    Point3D A;
      A.setX(1.0);
      A.setY(10.0);
      A.setZ(3.0);
    Point3D B{3.0, 4.0, 5.0};

    cout << "A: (" << A.getX() << ", " << A.getY() << ", " << A.getZ() << ")\n";
    cout << "B: (" << B.getX() << ", " << B.getY() << ", " << B.getZ() << ")\n";


    double distance1 = A - B;
    cout << "Distance (A - B): " << distance1 << endl;

      B.setX(0);
      B.setY(0);
      B.setZ(0);

    double distance2 = operator-(A, B);
    cout << "Distance (A - B) after update: " << distance2 << endl;

    return 0;
}
