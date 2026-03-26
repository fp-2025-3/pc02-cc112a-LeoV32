#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream archivo1("entradas/archivo1.txt", ios::in);
    ifstream archivo2("entradas/archivo2.txt", ios::in);
    ofstream archivoM("output/archivoM.txt", ios::out | ios::app);

    if(!archivo1){
        cerr<<"Error al leer el archivo1"<<endl;
        return -1;
    }
    if(!archivo2){
        cerr<<"Error al leer el archivo2"<<endl;
        return -1;
    }
    if(!archivoM){
        cerr<<"Error al abrir el archivoM"<<endl;
        return -1;
    }
    int dato1,dato2;
        archivo1>>dato1;
        archivo2>>dato2;

    while(dato1!=-1 && dato2!=-1){
        

        if(dato1<dato2){
            archivoM<<dato1<<endl;
            archivo1>>dato1;
        }else{
            archivoM<<dato2<<endl;
            archivo2>>dato2;
        }
    }

    while(dato1!=-1){
        archivoM<<dato1<<endl;
        archivo1>>dato1;
    }
    while(dato2!=-1){
        archivoM<<dato2<<endl;
        archivo2>>dato2;
    }
    archivoM<<-1<<endl;
    archivo1.close();
    archivo2.close();
    archivoM.close();

    return 0;
}

