#include <iostream>
using namespace std;

class Teacher
{
public:
    Teacher()
    {
        num = 0;
    }
    Teacher(int a, string b, string c)
    {
        num = a;
        name = b;
        sex = c;
    }
protected:
    int num;
    string name, sex;
};

class Birthday
{
public:
    Birthday()
    {
        year = 0;
        month = 0;
        day = 0;
    }
    Birthday(int a, int b, int c)
    {
        year = a;
        month = b;
        day = c;
    }
public:
    int year, month, day;
};

class Professor:public Teacher{
private:
    Birthday birthday;
public:
    Professor(int num,string a,string b,int y,int m,int d):Teacher(num,a,b){
    birthday.year=y;
    birthday.month=m;
    birthday.day=d;
    }
    void display(){
        cout<<num<<" "<<name<<" "<<sex<<" "<<birthday.year<<" "<<birthday.month<<" "<<birthday.day;
    }
};

int main() {
    Professor prof(201401432, "Johnson", "female", 1969, 10, 20);
    prof.display();
    return 0;
}
