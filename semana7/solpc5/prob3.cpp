#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

const int Filas=21;
const int Columnas=80;

int main(){

    char matriz[Filas][Columnas];

    for(int i=0;i<Filas;i++){
        for(int j=0;j<Columnas;j++){
            matriz[i][j]=' ';
        }
    }

    for(int i=0;i<Columnas;i++){
        matriz[10][i]='-';
    }

    for(int i=0;i<Filas;i++){
        matriz[i][0]='|';
    }

    double paso=(2*M_PI)/(Columnas-1);

    for(int j=0;j<Columnas;j++){
        double x=j*paso;
        double y=sin(5*x);

        //Le puse +0.05 para que se elimine el error
        // al imprimir la grafica provocado 
        // porque M_PI no es pi es un valor aproximado
        int fila=((1-y)*10+0.05);
        if(fila>=0 && fila<Filas){
            matriz[fila][j]='*';
        }
    }

    ofstream archivo("grafico.txt", ios::out | ios::app);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    for(int i=0;i<Filas;i++){
        for(int j=0;j<Columnas;j++){
            archivo<<matriz[i][j];
        }
        archivo<<endl;
    }
    cout<<"Se genero el archivo grafico.txt"<<endl;

    return 0;
}