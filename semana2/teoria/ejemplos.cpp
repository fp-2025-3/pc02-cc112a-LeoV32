#include <iostream>
using namespace std;

int main(){
    int a=42;
    int *p=NULL;
    p=&a;
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;



    char ch='e';
    char* ptr=NULL;
    ptr=&ch;

    *ptr='i';

    cout<<ch<<endl;
    cout<<(void*)&ch<<endl;
    cout<<*ptr<<endl;
    cout<<(void*)ptr<<endl;
}