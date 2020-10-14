#include <iostream>
using namespace std;

class Shape {
public:
	virtual float area() const = 0;
}; 

class Circle :public Shape {
public:
	Circle(){

	}
	Circle(float a) {
		this->r = a;
	}
	float area() const {
		return 3.14 * r * r;
	}
	friend istream& operator>>(istream & input, Circle & c)
	{
		input >> c.r;
		return input;
	}
private:
	float r;
};

class Square :public Shape {
public:
	Square() {

	}
	Square(float a) {
		this->a = a;
	}
	float area() const {
		return a * a;
	}
	friend istream& operator>>(istream& input, Square& c)
	{
		input >> c.a;
		return input;
	}
private:
	float a;
};

class Rectangle :public Shape {
public:
	Rectangle() {

	}
	Rectangle(float a,float b) {
		this->l = a;
		this->h = b;
	}
	float area() const {
		return l * h;
	}
	friend istream& operator>>(istream& input, Rectangle& c)
	{
		input >> c.l >> c.h;
		return input;
	}
private:
	float l,h;
};

class Trapezoid :public Shape {
public:
	Trapezoid() {

	}
	Trapezoid(float l1, float l2, float h) {
		this->l1 = l1;
		this->l2 = l2;
		this->h = h;
	}
	float area() const {
		return 0.5*(l1+l2) * h;
	}
	friend istream& operator>>(istream& input, Trapezoid& c)
	{
		input >> c.l1 >> c.l2 >> c.h;
		return input;
	}
private:
	float l1, l2, h;
};

class Triangle :public Shape {
public:
	Triangle() {

	}
	Triangle(float a, float b) {
		this->l = a;
		this->h = b;
	}
	float area() const {
		return 0.5* l * h;
	}
	friend istream& operator>>(istream& input, Triangle& c)
	{
		input >> c.l >> c.h;
		return input;
	}
private:
	float l, h;
};


int main() {
	Shape* pt[5];
	Circle circle;
	Square square;
	Rectangle rectangle;
	Trapezoid trapezoid;
	Triangle triangle;
	cin >> circle;
	cin >> square;
	cin >> rectangle;
	cin >> trapezoid;
	cin >> triangle;
	pt[0] = &circle;
	pt[1] = &square;
	pt[2] = &rectangle;
	pt[3] = &trapezoid;
	pt[4] = &triangle;
	cout << pt[0]->area() << endl;
	cout << pt[1]->area() << endl;
	cout << pt[2]->area() << endl;
	cout << pt[3]->area() << endl;
	cout << pt[4]->area() << endl;
	return 0;
}	