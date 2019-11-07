#include <iostream>

using namespace std;
class Date;

class Time{
private:
    int hour,minute,second;
public:
    Time(int h, int m,int s){
        this->hour=h;
        this->minute=m;
        this->second=s;
    }
    friend void display(Time &t,Date &d);
};

class Date{
private:
    int day,month,year;
public:
    Date(int d, int m,int y){
        this->day=d;
        this->month=m;
        this->year=y;
    }
    friend void display(Time &t,Date &d);
};

void display(Time &t,Date &d){
    cout<<d.day<<"/"<<d.month<<"/"<<d.year;
    cout<<" ";
    cout<<t.hour<<":"<<t.minute<<":"<<t.second;
}

int main(){
    int d,mm,y,h,m,s;
    cin>>d>>mm>>y>>h>>m>>s;
    Date date(d,mm,y);
    Time time(h,m,s);
    display(time,date);
    return 0;
}
