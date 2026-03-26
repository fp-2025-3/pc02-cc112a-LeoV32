#include <iostream>
using namespace std;

void imprimir(const int* inicio, const int* fin);
int* buscarPrimerNegativo(int* inicio, int* fin);
int* subarregloMaximoInicio(int* inicio, int* fin);
void intercambiar(int* a, int* b);
void invertir(int* inicio, int* fin);
int* maxAbsoluto(int* inicio, int* fin);

int main() {
    int datos[] = {3, -2, 5, 7, -4, 10, -6, 1};
    int n=sizeof(datos)/sizeof(datos[0]);
    int* inicio=datos;
    int* fin=datos+n;
    cout<<"Arreglo: "<<endl;
    imprimir(inicio,fin);
    int* p=buscarPrimerNegativo(inicio,fin);
    cout<<"El primer negativo es: "<<*p<<" con direccion "<<p<<endl;
    int* q=subarregloMaximoInicio(inicio,fin);
    cout<<"El ultimo valor del subarreglo con suma maxima es "<<*q<<" con direccion "<<q<<endl;
    cout<<"Arreglo invertido: "<<endl;
    invertir(inicio,fin);
    imprimir(inicio,fin);
    int* r=maxAbsoluto(inicio,fin);
    cout<<"El maximo absoluto es "<<*r<<" con direccion "<<r<<endl;

    return 0;
}

void imprimir(const int* inicio, const int* fin){
    for(const int* pd=inicio;pd<fin;pd++){
        cout<<*pd<<"  ";
    }
    cout<<endl;
}

int* buscarPrimerNegativo(int* inicio, int* fin){
    for(int* pd=inicio;pd<fin;pd++){
        if(*pd<0) return pd;
    }
    return fin;
}

int* subarregloMaximoInicio(int* inicio, int* fin){
    int suma=0;
    int maxsuma=*inicio;
    int* p=inicio;
    for(int* pd=inicio;pd<fin;pd++){
        suma=suma+*pd;
        if(maxsuma<suma){
            p=pd;
        }
        
    }
    return p;
}

void intercambiar(int* a, int* b){
    int save=*a;
    *a=*b;
    *b=save;
}

void invertir(int* inicio, int* fin){
    while(inicio<fin-1){
        intercambiar(inicio,fin-1);
        inicio++;
        fin--;
    }
}

int* maxAbsoluto(int* inicio, int* fin){
    int* p=inicio;
    for(int* pd=inicio+1;pd<fin;pd++){
        if(abs(*p)<abs(*pd)){
            p=pd;
        }
    }
    return p;
}