#include <iostream>
using namespace std;
#define PI 3.14

class Point{
protected:
    double x,y;
public:
    void setPoint(double a,double b){
        this->x=a;
        this->y=b;
    }
    friend istream &operator>>(istream &input,Point &c){
        cin>>c.x>>c.y;
        return input;
    }
    friend ostream &operator<<(ostream &input,Point &c){
    cout<<c.x<<" "<<c.y;
    return input;
    }
};

class Circle:public Point{
protected:
    double radius;
public:
    void setRadius(double a){
        this->radius=a;
    }
    friend istream &operator>>(istream &input,Circle &c){
        cin>>c.x>>c.y>>c.radius;
        return input;
    }
    friend ostream &operator<<(ostream &input,Circle &c){
    cout<<c.x<<" "<<c.y<<" "<<c.radius;
    return input;
    }
};

class Cylinder:public Circle{
protected:
    double height;
public:
    Cylinder(){
    }
    void setHeight(double a){
        this->height=a;
    }
    friend istream &operator>>(istream &input,Cylinder &c){
        cin>>c.x>>c.y>>c.radius>>c.height;
        return input;
    }
    friend ostream &operator<<(ostream &input,Cylinder &c){
        cout<<c.x<<" "<<c.y<<" "<<c.radius<<" "<<c.height;
        return input;
    }
};

int main() {
    Cylinder c;
    cin >> c;
    cout << c << endl;
    c.setHeight(1);
    c.setRadius(2);
    c.setPoint(3, 4);
    Point &pRef = c;
    cout << pRef << endl;
    Circle &cRef = c;
    cout << cRef << endl;
    return 0;
}
