#include <iostream>
using namespace std;

void imprimir(const int* inicio, const int* fin);
int* buscarPrimerNegativo(int* inicio, int* fin);
int* subarregloMaximoInicio(int* inicio, int* fin);
void intercambiar(int* a, int* b);
void invertir(int* inicio, int* fin);
int* maxAbsoluto(int* inicio, int* fin);

int main(){
    int datos[] = {3, -2, 5, 7, -4, 10, -6, 1};
    int n=sizeof(datos)/sizeof(datos[0]);
    int* inicio=datos;
    int* fin=datos+n;

    cout<<"Arreglo Original: "<<endl;
   imprimir(inicio,fin);

   int *p = buscarPrimerNegativo(inicio,fin);
   cout<<"El primer negativo es "<<*p<<" con direccion "<<p<<endl;

   int *q=subarregloMaximoInicio(inicio,fin);
   cout<<"En donde acaba para tener la suma maxima es "<<*q<<" con direccion "<<q<<endl;

   cout<<"Arreglo invertido: "<<endl;
   invertir(inicio,fin);
   imprimir(inicio,fin);

   int* r=maxAbsoluto(inicio,fin);
   cout<<"El maximo absoluto es "<<*r<<" con direccion"<<endl;
}

 void imprimir(const int* inicio, const int* fin){
    for(const int* pd=inicio;pd<fin;pd++){
        cout<<*pd<<" ";
    }
    cout<<endl;
 }

 int* buscarPrimerNegativo(int* inicio, int* fin){

    for(int *pd=inicio;pd<fin;pd++){
        if(*pd<0) return pd;
    }void invertir(int* inicio, int* fin);
    return fin;
 }

 int* subarregloMaximoInicio(int* inicio, int* fin){
    int* p=NULL;
    p=inicio;
    int suma=*inicio;
    for(int* pd=inicio+1;pd<fin;pd++){
        if(suma<suma+*pd){
            suma=suma+*pd;
            p=pd;
        }
    }
    return p;
 }

 void intercambiar(int* a, int* b){
    int p=*a;
    *a=*b;
    *b=p;
 }

 void invertir(int* inicio, int* fin){
    while(inicio<fin){
        intercambiar(inicio,fin-1);
        inicio++;
        fin--;
    }
 }

 int* maxAbsoluto(int* inicio, int* fin){
    int* p=inicio;
    for(int* pd=inicio+1;pd<fin;pd++){
        if(abs(*pd)>*p) p=pd;
    }
    return p;
 }