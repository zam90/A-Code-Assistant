#include <iostream>

using namespace std;

class box
{
private:
    int length, width, height;

public:
    box(int a, int b, int c) : length(a), width(b), height(c)
    {
    }
    box() : length(0), width(0), height(0)
    {
    }
    int volume()
    {
        return height * length * width;
    }
};
int main()
{
    double a,b,c,d,e,f,g,h,i;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i;
    box arr[3];
    box a1(a,b,c),a2(d,e,f),a3(g,h,i);
    arr[0]=a1;
    arr[1]=a2;
    arr[2]=a3;
    box *bp=arr;
    cout<<arr[0].volume()<<" ";
    cout<<arr[1].volume()<<" ";
    cout<<arr[2].volume()<<" ";
}
