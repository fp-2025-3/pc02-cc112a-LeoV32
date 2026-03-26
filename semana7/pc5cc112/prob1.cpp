#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream archivoLectura("notas.txt", ios::in);
    if(!archivoLectura){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    ofstream archivoEscritura("reporteAlumnos.txt", ios::out | ios::app);
    if(!archivoEscritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    int codigo;
    string nombre;
    float notas[3];

    float promedio;
    string condicion;

    while(archivoLectura>>codigo>>nombre>>notas[0]>>notas[1]>>notas[2]){
        promedio=(notas[0]+notas[1]+notas[2])/3;

        if(notas[0]<5 || notas[1]<5 || notas[2]<5) condicion="DESAPROBADO POR REGLA ACADEMICA";
        else if(promedio>=10) condicion="APROBADO";
        else condicion="DESAPROBADO";

        archivoEscritura<<codigo<<"\t"<<nombre<<"\t\t"<<promedio<<"\t\t"<<condicion<<endl;
    }

    archivoEscritura.close();
    archivoLectura.close();
    cout<<"Se genero el archivo correctamente"<<endl;
    return 0;

}