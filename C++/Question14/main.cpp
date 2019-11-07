#include <iostream>
using namespace std;

class matrix{
private:
    int mtx[3][3];
public:
    friend istream &operator>>(istream &input,matrix &a){
    cin>> a.mtx[0][0] >> a.mtx[0][1] >> a.mtx[0][2] >> a.mtx[1][0] >> a.mtx[1][1] >> a.mtx[1][2] >> a.mtx[2][0] >> a.mtx[2][1] >> a.mtx[2][2];
    return input;
    }
    friend ostream &operator<<(ostream &output,matrix &a){
    cout<< a.mtx[0][0] << " " << a.mtx[0][1] << " " << a.mtx[0][2] << "\n"<< a.mtx[1][0] << " " << a.mtx[1][1] << " " << a.mtx[1][2] << "\n"<< a.mtx[2][0] << " " << a.mtx[2][1] << " " << a.mtx[2][2];
    return output;
    }
    friend matrix operator+(matrix &a,matrix &b){
    matrix c;
    c.mtx[0][0] = a.mtx[0][0] + b.mtx[0][0];
    c.mtx[0][1] = a.mtx[0][1] + b.mtx[0][1];
    c.mtx[0][2] = a.mtx[0][2] + b.mtx[0][2];
    c.mtx[1][0] = a.mtx[1][0] + b.mtx[1][0];
    c.mtx[1][1] = a.mtx[1][1] + b.mtx[1][1];
    c.mtx[1][2] = a.mtx[1][2] + b.mtx[1][2];
    c.mtx[2][0] = a.mtx[2][0] + b.mtx[2][0];
    c.mtx[2][1] = a.mtx[2][1] + b.mtx[2][1];
    c.mtx[2][2] = a.mtx[2][2] + b.mtx[2][2];
    return c;
    }
};

int main(){
    matrix a,b,c;
    cin>>a;
    cin>>b;
    c=a+b;
    cout<<c;
    return 0;
}
