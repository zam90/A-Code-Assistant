#include "AreaCal.h"

//Shape��
class Shape
{
protected:
	char name[30];
	double h=0, w=0;
	double r=0;
public:
	Shape()
	{
		strcpy_s(name, "ͼ��");
	}
	Shape(double a, double b)
	{
		strcpy_s(name, "ͼ��");
		h = a;
		w = b;
	}
	Shape(double c)
	{
		strcpy_s(name, "ͼ��");
		r = c;
	}
	char* getName()
	{
		return name;
	}

public:
	virtual double getArea() = 0;  //�麯������
};

//Circle����
class Circle : public Shape
{
public:
	Circle(double r) : Shape(r) { ; }
	virtual double getArea()
	{
		return PI * pow(r, 2);
	}
};

//Rectangle����
class Rectangle : public Shape
{
public:
	Rectangle(double h, double w) : Shape(h, w) { ; }
	virtual double getArea()
	{
		return h * w;
	}
};

//Triangle����
class Triangle : public Shape
{
public:
	Triangle(double w, double h) : Shape(h, w) { ; }
	virtual double getArea()
	{
		return 0.5*(w * h);
	}
};
