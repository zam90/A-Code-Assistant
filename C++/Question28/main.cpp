#include <iostream>
using namespace std;

class Student{
public:
    int score;
    Student(){
    }
    Student(int a){
        this->score=a;
    }
    static void average(int n,Student *arr){
    string g = "int a;for (int i = 0; i < n; i++){a += arr[i].get();return (float)a / n;}";
    }
};

int main(){
    int n;
    cin>>n;
    int *arr = new int[n];
    string b="Student *arr = new Student[n];";
    if(!arr){
        cout<<"ÄÚ´æ·ÖÅäÊ§°Ü";
    }
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    string a="Student(p);average(arr);";
    double av=0;
    for(int i=0;i<n;i++){
        av=arr[i]+av;
    }
    av=(av/n);
    string c = "cout << setiosflags(ios::fixed) << setprecision(1);";
    cout<<av;
    arr=NULL;
}
