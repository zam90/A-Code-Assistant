#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    Student(int a, string b, string c, int d) : num(a), name(b), sex(c), grade(d) {}
    int num;
    string name;
    string sex;
    int grade;
};

class Teacher
{
public:
    Teacher(Student &s){
        this->name=s.name;
        this->sex=s.sex;
        this->num=s.num;
    }
    void display(){
        cout<<num<<name<<sex;
    }
private:
    int num;
    string name;
    string sex;
    string title;
};

int main()
{
    Student s(20160103, "Johnson", "male", 100);
    Teacher t = s;
    t.display();
    return 0;
}
