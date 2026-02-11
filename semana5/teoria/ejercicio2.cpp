#include <iostream>
using namespace std;

struct Fecha{
    int dia;
    int mes;
    int anio;
};
struct contacto{
    string nombre;
    Fecha nacimiento;
};

void leer(contacto* e,int N){
    int cont=0;
    for(contacto* i=e;i<e+N;i++,cont++){
        cout<<"Contacto "<<cont+1<<": "<<endl;
        cout<<"Ingresar nombre: ";
        cin.ignore();
        getline(cin,i->nombre);
        cout<<"Ingresar fecha de nacimiento: "<<endl;
        cout<<"    Dia: ";
        cin.ignore();
        cin>>i->nacimiento.dia;
        cout<<"    Mes: ";
        cin.ignore();
        cin>>i->nacimiento.mes;
        cout<<"    Anio: ";
        cin.ignore();
        cin>>i->nacimiento.anio;
        cout<<endl;
    }
}

void mostrarPorAnio(contacto* e,int N,int anio){
    for(contacto* i=e;i<e+N;i++){
        if(i->nacimiento.anio==anio){
            cout<<"Nombre: "<<i->nombre<<endl;
            cout<<"Fecha: "<<i->nacimiento.dia<<"/"<<i->nacimiento.mes<<"/"<<i->nacimiento.anio<<endl;
            cout<<endl;
        }
        
    }
}


int main(){
    int N;
    cout<<"===Agenda==="<<endl;
    cout<<"Ingrese la cantidad de contactos: ";
    cin>>N;
    contacto* personas=new contacto[N];
    leer(personas,N);
    mostrarPorAnio(personas,N,2008);
    delete[] personas;
}