#include <iostream>
using namespace std;

int main(){
    char mensaje[]={"hola mundo"};
    char* p=NULL;
    p=mensaje;
    while(*p!='\0'){
        cout<<*p;
        cout<<endl<<(void*)p<<endl;
        p++;
    }
    p--;
    
    return 0;

}