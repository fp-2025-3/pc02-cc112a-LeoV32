#include <iostream>
using namespace std;

struct Estudiante{
    int codigo;
    double promedio;
};

void leerDatos(Estudiante* e,int N){
    for(int i=0;i<N;i++){
        cout<<"Estudiante "<<i+1<<":"<<endl;
        cout<<"Ingresa el codigo: ";
        cin>>e[i].codigo;
        cout<<"Ingresa el promedio: ";
        cin>>e[i].promedio;
    }
}

void mostrarAprobados(Estudiante* e,int N){
    for(int i=0;i<N;i++){
        if(e[i].promedio>=10){
            cout<<"Codigo: "<<e[i].codigo<<endl;
            cout<<"Promedio: "<<e[i].promedio<<endl;
            cout<<endl;
        }
        
    }
}

void liberarMemoria(Estudiante* e){
    delete[] e;
}

int main(){
    int N;
    cout<<"Ingrese la cantidad de estudiantes: ";
    cin>>N;
    Estudiante* e = new Estudiante[N];
    leerDatos(e,N);
    cout<<endl;
    mostrarAprobados(e,N);
    liberarMemoria(e);
}