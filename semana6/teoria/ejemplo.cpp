#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ofstream archivoEscritura;
    archivoEscritura.open("texto.txt");

    if(!archivoEscritura){
        cerr<<"ERROR: no se logro abrir el archivo"<<endl;
        return 1;
    }

    archivoEscritura<<"Juan 19"<<endl;
    archivoEscritura<<"Maria 12"<<endl;
    archivoEscritura<<"Pedro 31"<<endl;

    archivoEscritura.close();

    ifstream archivoLectura;
    archivoLectura.open("texto.txt");

    if(!archivoLectura){
        cerr<<"ERROR: No existe este archivo"<<endl;
        return 1;
    }

    string nombre;
    int nota;

    while(archivoLectura>>nombre>>nota){
        cout<<nombre<<" "<<nota<<endl;
    }
    archivoLectura.close();

    ofstream fout("texto.txt", ios::app | ios::out);

    if(!fout){
        cerr<<"ERROR, al abir el archivo de escritura"<<endl;
        return 1;
    }
    fout<<"Melisa 14"<<endl;
    fout<<"Arturo 15"<<endl;
    fout<<"Andres 17"<<endl;

    cout<<"Datos agregados correctamente"<<endl;
}