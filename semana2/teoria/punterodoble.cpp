#include <iostream>
using namespace std;

int main(){
    int a=42;
    int b=23;
    int* p=&a;
    int *otro=&b;
    int** ptr=&p;

    

    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*p<<endl;
    cout<<p<<endl;
    cout<<&p<<endl;
    cout<<*ptr<<endl;
    cout<<**ptr<<endl;
    cout<<*ptr<<endl;
    cout<<ptr<<endl;
    cout<<endl<<endl;
    *ptr=otro;
    
    cout<<*p<<endl;
    cout<<p<<endl;


    return 0;
}