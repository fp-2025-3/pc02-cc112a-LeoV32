#include <iostream>
using namespace std;
int guardaDirecciones(char* texto,char** indice);
int comparar(const char* a,const char* b);
void ordenarIndice(char** indice,int n);
void imprimir(char* texto,char** indice,int n);

int main(){
    char texto[]={"los punteros no se copian se referencian y se ordenan"};
    char* indice[30];
    cout<<"Salida: "<<endl;
    int n=guardaDirecciones(texto,indice);
    ordenarIndice(indice,n);
    imprimir(texto,indice,n);

    return 0;
}

int guardaDirecciones(char* texto,char** indice){
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

int comparar(const char* a,const char* b){
    while(*a!=' ' && *b!=' ' && *a!='\0' && *b!='\0' && *a==*b){
        a++;
        b++;
    }
    if(*a-*b>0) return -1;
    if(*a-*b<0) return 1;
    return 0;
}

void ordenarIndice(char** indice,int n){
    for(char** i=indice;i<indice+n;i++){
        for(char** j=indice;j<indice+n;j++){
            if(comparar(*i,*j)>0){
                char* temp=*i;
                *i=*j;
                *j=temp;
            }
        }
    }
}

void imprimir(char* texto,char** indice,int n){
    int largomax=0;

    for(char** i=indice;i<indice+n;i++){
        char* j=*i;
        int l=0;
        while(*j!=' ' && *j!='\0'){
            l++;
            j++;
        }
        if(l>largomax) largomax=l;

    }

    for(char** i=indice;i<indice+n;i++){
        char* j=*i;
        int largo=0;
        while(*j!=' ' && *j!='\0'){
            cout<<*j;
            largo++;
            j++;
        }
        while(largo<largomax){
            cout<<" ";
            largo++;
        }

        cout<<"      (posicion "<<*i-texto<<")"<<endl;
    }
}