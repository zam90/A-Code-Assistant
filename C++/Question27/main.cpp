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
    friend void display(Student *p){
    for(int i=0;i<5;i++,p++){
        if(i==0||i==2||i==4){
            cout<< p->score<<" ";
        }
    }
    }
};

int main(){
    int a,b,c,d,e;
    cin>>a>>b>>c>>d>>e;
    Student a1(a),b1(b),c1(c),d1(d),e1(e);
    Student *arr = new Student[5];
    if(!arr){
        cout<<"ÄÚ´æ·ÖÅäÊ§°Ü";
    }
    else{
        arr[0]=a1;arr[1]=b1;arr[2]=c1;arr[3]=d1;arr[4]=e1;
        Student *sp;
        sp=&arr[0];
        display(sp);
        delete[] sp;
        sp = NULL;
    }

    return 0;
}
