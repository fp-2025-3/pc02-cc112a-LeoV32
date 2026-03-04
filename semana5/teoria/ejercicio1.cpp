#include <iostream>
using namespace std;

struct Estudiante{
    int codigo;
    double promedio;
};

void leerDatos(Estudiante* e,int N){
    int cont=0;
    for(Estudiante* i=e;i<e+N;i++,cont++){
        cout<<"Estudiante "<<cont+1<<":"<<endl;
        cout<<"Ingresa el codigo: ";
        cin>>i->codigo;
        cout<<"Ingresa el promedio: ";
        cin>>i->promedio;
    }
}

void mostrarAprobados(Estudiante* e,int N){
    for(Estudiante* i=e;i<e+N;i++){
        if((*i).promedio>=10){
            cout<<"Codigo: "<<(*i).codigo<<endl;
            cout<<"Promedio: "<<(*i).promedio<<endl;
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