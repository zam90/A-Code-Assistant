#include <iostream>

using namespace std;

class Time{
private:
    int minute,sec;
public:
    Time(){
    }
    Time(int m,int s){
        this->minute=m;
        this->sec=s;
    }
    friend Time operator++(Time &t){
    t.sec++;
    if(t.sec==60){
        t.sec=0;
        t.minute++;
    }
    return t;
    }
    void display(){
        cout<<this->minute<<":"<<this->sec<<"\n";
    }
};

int main(){
    Time time1(34,50);
    for(int i = 0; i < 20; i++)
    {
        ++time1;
        time1.display();
    }
    return 0;
}
