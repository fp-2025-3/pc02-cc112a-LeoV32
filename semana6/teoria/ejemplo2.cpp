#include <iostream>
#include <fstream>
using namespace std;

struct Estudiante{
    char nombre[40];
    int nota;
};  

//Falta avanzar la parte del binario

void Lectura(const string &nombreArchivo);
void EscribirSobrescribiendo(const string &nombreArchivo,const string &nombre,int edad);
void EscribirAlUltimo(const string &nombreArchivo,const string &nombre,int edad);

int main(){

    string nombreArchivo="texto.txt";

    EscribirSobrescribiendo(nombreArchivo,"Juan",19);
    EscribirSobrescribiendo(nombreArchivo,"Maria",12);
    EscribirSobrescribiendo(nombreArchivo,"Pedro",31);

    Lectura(nombreArchivo);
    
    EscribirAlUltimo(nombreArchivo,"Melisa",14);
    EscribirAlUltimo(nombreArchivo,"Arturo",15);
    EscribirAlUltimo(nombreArchivo,"Andres",17);
    cout<<"Datos agregados correctamente"<<endl;

    Lectura(nombreArchivo);
    
    return 0;
}

void Lectura(const string &nombreArchivo){
    ifstream archivoLectura;
    archivoLectura.open(nombreArchivo);

    if(!archivoLectura){
        cerr<<"ERROR: No existe este archivo"<<endl;
        return;
    }

    string nombre;
    int nota;

    while(archivoLectura>>nombre>>nota){
        cout<<nombre<<" "<<nota<<endl;
    }
    archivoLectura.close();
}

void EscribirSobrescribiendo(const string &nombreArchivo,const string &nombre,int edad){
    ofstream archivoEscritura;
    archivoEscritura.open(nombreArchivo);

    if(!archivoEscritura){
        cerr<<"ERROR: no se logro abrir el archivo"<<endl;
        return ;
    }

    archivoEscritura<<nombre<<" "<<edad<<endl;

    archivoEscritura.close();

}

void EscribirAlUltimo(const string &nombreArchivo,const string &nombre,int edad){
    ofstream fout(nombreArchivo, ios::app | ios::out);

    if(!fout){
        cerr<<"ERROR, al abir el archivo de escritura"<<endl;
        return ;
    }
    fout<<nombre<<" "<<edad<<endl;
    

    fout.close();
}