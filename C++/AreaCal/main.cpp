#include "AreaCal.h"
#include "shape.cpp"

void main(int argc, char* argv[])
{
	Shape* p;
	Circle cir(2);
	Rectangle rec(3, 2);
	Triangle tri(3, 2);

	p = &cir;
	cout << p->getArea() << endl;
	p = &rec;
	cout << p->getArea() << endl;
	p = &tri;
	cout << p->getArea() << endl;
	system("pause");
}