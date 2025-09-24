#include <iostream>
using namespace std;
#define DEBUG // Comment this out to disable debug messages
class Rectangle {
public:
 Rectangle(int a, int b) : width(a), height(b) {
#ifdef DEBUG
 cout << "Rectangle created with width=" << a
 << " and height=" << b << endl;
#endif
 }
 int area() {
#ifdef DEBUG
 cout << "Calculating area: " << width << " * " << height << endl;
#endif
 return width * height;
 }
private:
 int width, height;
};
int main() {
 Rectangle rect1(5, 4);
 cout << "Area = " << rect1.area() << endl;
 return 0;
}