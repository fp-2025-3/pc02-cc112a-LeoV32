#include <iostream>
using namespace std;

int construir_indice(char* texto, char* indice[]);
int comparar(const char* a, const char* b);
void ordenar_indice(char* indice[], int n);
void imprimir_indice(char* texto, char* indice[], int n);

int main(){
    char texto[300] = "los punteros no se copian se referencian y se ordenan";      // arreglo base
    char* indice[60];    // arreglo de punteros a palabras
    int n=construir_indice(texto,indice);
    ordenar_indice(indice,n);
    imprimir_indice(texto,indice,n);
}

int construir_indice(char* texto, char* indice[]){
    char* p=texto;
    char** q=indice;
    while(*p!='\0'){
        if(p==texto && *p!=' '){
            *q=p;
            q++;
        }
        if(p!=texto){
            if(*(p-1)==' ' && *p!=' '){
                *q=p;
                q++;
            }
        }
        p++;
    }
    return q-indice;
}

int comparar(const char* a, const char* b){
    while(*a!=' ' && *b!=' ' && *a==*b && *a!='\0' && *b!='\0'){
        a++;
        b++;
    }
    if(*a-*b>0) return 1;
    if(*a-*b<0) return -1;
    return 0;
}

void ordenar_indice(char* indice[], int n){
    for(char** i=indice;i<indice+n-1;i++){
        for(char** j=i+1;j<indice+n;j++){
            if(comparar(*i,*j)>0){
                char* temp=*i;
                *i=*j;
                *j=temp;
            }
        }
    }
}

void imprimir_indice(char* texto, char* indice[], int n){
    for(char** pd=indice;pd<indice+n;pd++){
        char* q=*pd;
        while(*q!=' ' && *q!='\0'){
            cout<<*q;
            q++;
        }
        cout<<"         (posicion "<<*pd-texto<<")"<<endl;
    }
}

