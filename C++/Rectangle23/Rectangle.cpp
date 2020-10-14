#include<iostream>
using namespace std;

//面积基类
class ShapeArea {
public:
	virtual double getArea() = 0;
};
//体积基类
class ShapeVolume {
public:
	virtual double getVolume() = 0;
};

//图形面积派生类Rectangle
class Rectangle :public ShapeArea {
private:
	double l,h;
public:
	Rectangle() {
		l = 1;
		h = 1;
	}
	Rectangle(double l, double h) {
		this->l = l;
		this->h = h;
	}
	double getArea() {
		return l*h;
	}
};
//Rectangle派生类Rectangle3，同时继承体积基类
class Rectangle3 :public Rectangle, public ShapeVolume {
private:
	double l,w,h;
public:
	Rectangle3() {
		l = 1;
		w = 1;
		h = 1;
	}
	Rectangle3(double l, double w, double h) {
		this->l = l;
		this->w = w;
		this->h = h;
	}
	double getArea() {
		return 2*(l*w+l*h+w*h);
	}
	double getVolume() {
		return l*w*h;
	}
};