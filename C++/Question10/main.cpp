#include <iostream>
using namespace std;

class Teacher{
private:
    string name,sex,address;
    int age,phone_number;
    string title;
public:
    Teacher(){
    }
    Teacher(string n,string s,string a,string t,int ag,int ph){
        this->name=n;
        this->sex=s;
        this->address=a;
        this->title=t;
        this->age=ag;
        this->phone_number=ph;
    }
    void display(){
        cout<<name<<age<<sex<<address<<phone_number<<title;
    }
};

class Cadre{
private:
    string name,sex,address;
    int age,phone_number;
    string post;
public:
    Cadre(){
    }
    Cadre(string n,string s,string a,string t,int ag,int ph){
        this->name=n;
        this->sex=s;
        this->address=a;
        this->post=t;
        this->age=ag;
        this->phone_number=ph;
    }
    void display(){
        cout<<name<<age<<sex<<address<<phone_number<<post;
    }
};

class Teacher_Cadre:public Teacher,public Cadre{
private:
    int wages;
public:
    Teacher_Cadre():Teacher(),Cadre(){
    }
    Teacher_Cadre(string n,int ag,string s,string a,int ph,string t,string p,int w):Teacher(n,s,a,t,ag,ph),Cadre(n,s,a,p,ag,ph){
    this->wages=w;
    }
    void display(){
        Teacher::display();
        cout<<wages;
    }
};

int main() {
    Teacher_Cadre t("Johnson", 14, "male", "Beijing", 123456, "professor", "assistant", 7000);
    t.display();
    return 0;
}
