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

    int cont=0;
    double suma=0.0;
    string maxNombre;
    double maxNota=0.0;
    string minNombre;
    double minNota=20.0;

    while(archivoLectura>>codigo>>nombre>>notas[0]>>notas[1]>>notas[2]){
        cont++;
        promedio=(notas[0]+notas[1]+notas[2])/3.0;
        suma+=promedio;

        if(maxNota<promedio){
            maxNota=promedio;
            maxNombre=nombre;
        }else if(minNota>promedio){
            minNota=promedio;
            minNombre=nombre;
        }


        if(notas[0]<5 || notas[1]<5 || notas[2]<5) condicion="DESAPROBADO POR REGLA ACADEMICA";
        else if(promedio>=10) condicion="APROBADO";
        else condicion="DESAPROBADO";

        archivoEscritura<<codigo<<"\t"<<nombre<<"\t\t"<<promedio<<"\t\t"<<condicion<<endl;
    }
    archivoEscritura<<endl<<"Total de estudiantes: "<<cont<<endl;
    archivoEscritura<<"Promedio general: "<<suma/cont<<endl;
    archivoEscritura<<"Estudiante con mayor promedio: "<<maxNombre<<"\t"<<maxNota<<endl;
    archivoEscritura<<"Estudiante con menor promedio: "<<minNombre<<"\t"<<minNota<<endl;

    archivoEscritura.close();
    archivoLectura.close();
    cout<<"Se genero el archivo correctamente"<<endl;
    return 0;

}