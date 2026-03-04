#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Estudiante{
    char nombre[40];
    int nota;
};  

//Falta avanzar la parte del binario

void LecturaBinario(const string &nombreArchivo);
void EscrituraBinario(const string &nombreArchivo,const string &nombre,int nota);

int main(){

    string nombreArchivo="datos.bin";

    EscrituraBinario(nombreArchivo,"Juan",19);
    EscrituraBinario(nombreArchivo,"Maria",12);
    EscrituraBinario(nombreArchivo,"Pedro",31);

    LecturaBinario(nombreArchivo);
    
    EscrituraBinario(nombreArchivo,"Melisa",14);
    EscrituraBinario(nombreArchivo,"Arturo",15);
    EscrituraBinario(nombreArchivo,"Andres",17);
    cout<<"Datos agregados correctamente"<<endl;

    LecturaBinario(nombreArchivo);
    
    return 0;
}

void LecturaBinario(const string &nombreArchivo){
    ifstream archivoLectura;
    archivoLectura.open(nombreArchivo);

    if(!archivoLectura){
        cerr<<"ERROR: No existe este archivo"<<endl;
        return;
    }

    Estudiante e;

    while(archivoLectura.read((char*)&e,sizeof(Estudiante))){
        cout<<e.nombre<<" "<<e.nota<<endl;
    }
    archivoLectura.close();
}


void EscrituraBinario(const string &nombreArchivo,const string &nombre,int nota){
    ofstream archivoEscritura(nombreArchivo, ios::app | ios::binary);

    if(!archivoEscritura){
        cerr<<"ERROR, al abrir el archivo de escritura"<<endl;
        return ;
    }
    Estudiante e;
    e.nota=nota;
    strncpy(e.nombre,nombre.c_str(),sizeof(e.nombre));
    e.nombre[sizeof(e.nombre)-1]='\0';
    
    archivoEscritura.write((char*)&e,sizeof(Estudiante));

    archivoEscritura.close();
}