#include <iostream>
using namespace std;

class Student{
private:
    int score;
public:
    Student (){
    }
    Student(int a){
    this->score=a;
    }
    friend void max(Student *p){
    int m;
    m=p->score;
    for(int i=0;i<5;i++,p++){
    if(m<p->score){
        m=p->score;
    }
    }
    cout<<m;
    }
};

int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    Student s1(a),s2(b),s3(c),s4(d),s5(e);
    Student arr[5];
    arr[0]=s1;
    arr[1]=s2;
    arr[2]=s3;
    arr[3]=s4;
    arr[4]=s5;
    Student *sp;
    sp=&arr[0];
    max(sp);
    return 0;
}
