#include <iostream>
#include <stdio.h>
using namespace std;
string a="template<class T>";
template<typename T>
void sort(int n,T *a){
    int i=0,j=0;
    T mid;
    for(i=0;i<n;i++){
        for(j=0;j<n-1;j++){
            if(a[i]<a[j]){
                mid=a[i];
                a[i]=a[j];
                a[j]=mid;
            }
        }
    }
}

int main(){
    int jud;
    cin>>jud;
    int n;
    cin>>n;
    if(jud==1){
        int *arr=new int[n];
        if(!arr){
            cout<<"内存分配失败";
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(n,arr);
        for(int i=0;i<n;i++){
            printf("%d ",arr[i]);
        }
        cout << "\n程序运行结束";
        delete arr;
        arr=NULL;
    }
    else if(jud==2){
        float *arr=new float[n];
        if(!arr){
            cout<<"内存分配失败";
        }
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(n,arr);
        for(int i=0;i<n;i++){
            printf("%.2f ",arr[i]);
        }
        cout << "\n程序运行结束";
        delete arr;
        arr=NULL;
    }
    return 0;
}
