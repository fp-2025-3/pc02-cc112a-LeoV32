#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void imprimir(const char* t);

int main(){
    char archivo[]="entradas/baseUNI.txt";

    imprimir(archivo);
    return 0;
}

void imprimir(const char* t){
    ifstream archivo(t,ios::in);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return;
    }

    cout<<"Num\t Apellidos\tNombre\tNota1\tNota2\tPromedio"<<endl;
    string apellidosMax,nombreMax;
    double notaMax=0.0;
    string linea,apellidos,nombre;
    int numero;
    double nota1,nota2;
    while(getline(archivo,linea,'.')){
        numero=stoi(linea);
        getline(archivo,linea,',');
        apellidos=linea;
        getline(archivo,linea,'-');
        nombre=linea;
        getline(archivo,linea,'-');
        nota1=stof(linea);
        getline(archivo,linea);
        nota2=stof(linea);
        cout<<numero<<"\t"<<apellidos<<"\t"<<nombre<<"\t"<<nota1;
        cout<<"\t"<<nota2<<"\t"<<(nota1+nota2)/2<<endl;
        if((nota1+nota2)/2>notaMax){
            notaMax=(nota1+nota2)/2;
            apellidosMax=apellidos;
            nombreMax=nombre;
        } 
    }
    archivo.close();

    cout<<"El promedio maximo es: "<<notaMax<<endl;
    cout<<"Alumno: "<<nombreMax<<" "<<apellidosMax<<endl;
}