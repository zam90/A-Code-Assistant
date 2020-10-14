#include <iostream>
using namespace std;

class Point {
public:
	Point() {

	}
	Point(double a, double b) {
		this->x = a;
		this->y = b;
	}
protected:
	double x, y;
};

class Circle:public Point {
public:
	Circle() {

	}
	Circle(double a, double b, double c) {
		this->x = a;
		this->y = b;
		this->radius = c;
	}
	friend ostream& operator<<(ostream& output, const Circle& c) {
		output << c.x << " " << c.y << " " << c.radius;
		return output;
	}
protected:
	double radius;
};

class Cylinder :public Circle {
public:
	Cylinder() {

	}
	Cylinder(double a, double b, double c, double d) {
		this->x = a;
		this->y = b;
		this->radius = c;
		this->height = d;
	}
	friend istream& operator>>(istream& input, Cylinder& c) {
		double a, b, e, d;
		cin >> a >> b >> e >> d;
		Cylinder f(a, b, e, d);
		c = f;
		return input;
	}
	friend ostream& operator<<(ostream& out, Cylinder& c) {
		out << c.x << " " << c.y << " " << c.radius<<endl;
		out << c.x << " " << c.y << " " << c.radius << " " << c.height<<endl;
		double a =c.radius * c.radius * c.radius;
		double b = (4.0 / 3.0) * 3.14*a;
		out << b;
		return out;
	}
	int aa() {
		if (height == 2)
			return 2;
		else return 0;
	}
protected:
	double height;
};

#define PI 3.14
int main() {
	Cylinder c;
	cin >> c;
	cout << c << endl;
	Circle& cRef = c;
	cout << cRef << endl;
	return 0;
}
