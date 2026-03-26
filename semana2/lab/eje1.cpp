#include <iostream>
#include <cstring>
using namespace std;

void rev(char* p);

int main(){
    char a[]={"Abejita"};
    cout<<"Arreglo:"<<endl;
    cout<<a<<endl;
    rev(a);
    cout<<a<<endl;

}

void rev(char *p){
    char* inicio=p;
    char* fin=p;

    while(*fin!='\0'){
        fin++;
    }
    fin--;

    while(inicio<fin){
        char temp=*inicio;
        *inicio=*fin;
        *fin=temp;
        inicio++;
        fin--;        
    }
}