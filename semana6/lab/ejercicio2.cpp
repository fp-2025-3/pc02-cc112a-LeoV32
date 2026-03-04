#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream lectura("notas.txt",ios::in);
    if(!lectura){
        cerr<<"Error al leer el archivo"<<endl;
        return 1;
    }
    int nota;
    int cantEstudiantes=0;
    double suma=0.0;
    int max=-1e9;
    int min=1e9;
    int aprobados=0;

    while(lectura>>nota){
        cantEstudiantes++;
        suma+=nota;
        if(nota>max) max=nota;
        if(nota<min) min=nota;
        if(10<=nota) aprobados++;
    }
    lectura.close();

    ofstream escritura("output/reporte.txt",ios::app);
    if(!escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    escritura<<"REPORTE GENERAL"<<endl;
    escritura<<"------------------------"<<endl;
    escritura<<"Total estudiantes: "<<cantEstudiantes<<endl;
    escritura<<"Promedio: "<<suma/cantEstudiantes<<endl;
    escritura<<"Mayor nota: "<<max<<endl;
    escritura<<"Menor nota: "<<min<<endl;
    escritura<<"Aprobados: "<<aprobados<<endl;
    escritura<<"Desaprobados: "<<cantEstudiantes-aprobados<<endl;

    cout<<"Se realizo el reporte correctamente"<<endl;
    escritura.close();

    return 0;
}