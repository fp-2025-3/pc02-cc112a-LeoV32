#include <iostream>
using namespace std;

int main(){
    int a=24;
    int b=32;
    int* ap=NULL;
    int* bp=NULL;
    ap=&a;
    bp=&b;
    int** pp=NULL;
    pp=&ap;

    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*ap<<endl;
    cout<<ap<<endl;
    cout<<&ap<<endl;
    cout<<**pp<<endl;
    cout<<*pp<<endl;
    cout<<pp<<endl;
    cout<<&pp<<endl;

    *pp=bp;
    
    cout<<a<<endl;
    cout<<&a<<endl;
    cout<<*ap<<endl;
    cout<<ap<<endl;
    cout<<&ap<<endl;
    cout<<**pp<<endl;
    cout<<*pp<<endl;
    cout<<pp<<endl;
    cout<<&pp<<endl;
}