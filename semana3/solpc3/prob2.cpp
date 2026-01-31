#include <iostream>
using namespace std;

int numero(char* texto);

int main(){
    char texto[]={"   Este es   un ejemplo en C++  END"};
    cout<<"Texto: "<<texto<<endl;
    cout<<"Numero de palabras que comienzan con vocal: "<<numero(texto)<<endl;
    return 0;
}

int numero(char* texto){
    char* p=texto;
    int contador=0;
    while(*p!='\0'){
        if(p==texto && (*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u' || *p=='A' || *p=='E' || *p=='I' || *p=='O' || *p=='U')){
            contador++;
        }
        if(p!=texto){
            if(*(p-1)==' ' && (*p=='a' || *p=='e' || *p=='i' || *p=='o' || *p=='u' || *p=='A' || *p=='E' || *p=='I' || *p=='O' || *p=='U')){
                contador++;
            }
        }
        p++;
    }
    return contador;
}