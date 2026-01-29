#include <iostream>
using namespace std;

int separar_palabras(char* frase, char* palabras[]);
int comparar(const char* a, const char* b);
void ordenar(char* palabras[], int n);
void imprimir(char* palabras[], int n);

int main(){
    char frase[] = "aprender punteros exige mucha logica y practica";
    char* palabras[50];
    int n=separar_palabras(frase,palabras);
    ordenar(palabras,n);
    imprimir(palabras,n);
}

int separar_palabras(char* frase,char* palabras[]){
    int contador=0;
    char** q=palabras;
    char* p=frase;
    while(*p!='\0'){
        
            if(p==frase && *p!=' '){
                *q=p;
                contador++;
                q++;
            }
            if(p!=frase){
                if(*(p-1)==' ' && *p!=' '){
                    *q=p;
                    contador++;
                    q++;
                } 
            }
            p++;
    }
    return contador;
}

int comparar(const char* a, const char* b){
    while(*a!=' ' && *b!=' ' && *a!='\0' && *b!='\0' && *a==*b){
        a++;
        b++;
    }
    if(*a>*b) return 1;
    if(*a<*b) return -1;
    return 0;
}

void ordenar(char* palabras[], int n){
    char* temp=NULL;
    for(char** i=palabras;i<palabras+n;i++){
        for(char** j=i+1;j<palabras+n;j++){
            if(comparar(*i,*j)>0){
                temp=*i;
                *i=*j;
                *j=temp;
            }
        }
    }
}

void imprimir(char* palabras[], int n){

    for(char** pd=palabras;pd<palabras+n;pd++){
        char* p=*pd;

        while(*p!='\0' && *p!=' '){
            cout<<*p;
            p++;
        }
        cout<<endl;
    }
    cout<<endl;
}