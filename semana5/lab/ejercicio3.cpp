#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

 const int n=5;

struct Seleccion{
    string pais;
    int PG;
    int PE;
    int PP;
    int puntaje;
    float rendimiento;
};

void datosAleatorios(Seleccion e[],int n);
void imprimir(Seleccion e[],int n);

int main(){
    srand(time(NULL));
   
    Seleccion e[n];
    datosAleatorios(e,n);
    imprimir(e,n);

    return 0;
}

void datosAleatorios(Seleccion e[],int n){
    for(int i=0;i<n;i++){
        e[i].pais="Pais_Seleccion "+to_string(i);
        e[i].PG=rand()%101;
        e[i].PP=rand()%(101-e[i].PG);
        e[i].PE=100-e[i].PG-e[i].PP;
        e[i].puntaje=3*e[i].PG+e[i].PE;
         e[i].rendimiento=e[i].puntaje;
        e[i].rendimiento/=3;
    }

}

void imprimir(Seleccion e[],int n){
    int mejor=0;
    cout<<"Seleccion            PG    PP    PE      Puntaje         Redimiento"<<endl;
    for(int i=0;i<n;i++){
    cout<<e[i].pais<<"     ";
    cout<<e[i].PG<<"    "<<e[i].PP<<"    "<<e[i].PE<<"        ";
    cout<<e[i].puntaje<<"                 "<<e[i].rendimiento<<endl;
    if(e[i].rendimiento>e[mejor].rendimiento) mejor=i;
    }

    cout<<"La seleccion con mejor rendimiento es: Seleccion "<<mejor;
    cout<<" Rendimiento: "<<e[mejor].rendimiento<<endl;
}