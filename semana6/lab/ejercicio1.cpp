#include <iostream>
#include <fstream>
using namespace std;


const int N=7;

void Escribir(const string& nombre,int monto);
void Imprimir(const string& nombre);

int main(){
    int monto;
    string nombre1="output/ventas.txt";

    cout<<"Ingrese los "<<N<<" montos: "<<endl;
    for(int i=0;i<N;i++){
        cin>>monto;
        Escribir(nombre1,monto);
    }
    Imprimir(nombre1);
    return 0;
}


void Escribir(const string& nombre,int monto){
    ofstream archivoEscritura(nombre,ios::out | ios::app);

    if(!archivoEscritura){
        cerr<<"ERROR, al abrir el archivo"<<endl;
        return;
    }
    archivoEscritura<<monto<<endl;

    archivoEscritura.close();
}

void Imprimir(const string& nombre){
    ifstream archivoLectura(nombre,ios::in);

    if(!archivoLectura){
        cerr<<"ERROR, al leer el archivo"<<endl;
        return;
    }
    int max=-1e9;
    int min=1e9;
    int nota;
    int suma=0;
    int contador=0;
    while(archivoLectura>>nota){
        suma+=nota;
        if(max<nota) max=nota;
        if(min>nota) min=nota;
        contador++;
    }
    archivoLectura.close();

    ofstream archivoEscritura(nombre, ios::out | ios::app);

    if(!archivoEscritura){
        cerr<<"ERROR, al abrir el archivo"<<endl;
    }

    archivoEscritura<<"---------------"<<endl;
    archivoEscritura<<"Resumen: "<<endl;
    archivoEscritura<<"Total: "<<suma<<endl;
    archivoEscritura<<"Promedio: "<<suma/contador<<endl;
    archivoEscritura<<"Mayor venta: "<<max<<endl;
    archivoEscritura<<"Menor venta: "<<min<<endl;

    archivoEscritura.close();

    cout<<"Resumen: "<<endl;
    cout<<"Total: "<<suma<<endl;
    cout<<"Promedio: "<<suma/contador<<endl;
    cout<<"Mayor venta: "<<max<<endl;
    cout<<"Menor venta: "<<min<<endl;


}