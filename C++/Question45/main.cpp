#include <iostream>
#include <stdio.h>
using namespace std;

class A{
public:
    int a;
    A (int _a = 0) : a(_a) { }
};

template <class T>
void Swap(T &a,T &b){
    T c;
    c=a;
    a=b;
    b=c;
}

int main() {
    A a(1), b(2);
    std::cout << "a.a = " << a.a << " b.a = " << b.a << "\n";
    Swap(a, b);
    std::cout << "a.a = " << a.a << " b.a = " << b.a << "\n";
    int t1 = 0, t2 = 100;
    printf("t1=%d, t2=%d\n", t1,t2);
    Swap(t1, t2);
    printf("t1=%d, t2=%d\n", t1,t2);
    return 0;
}
