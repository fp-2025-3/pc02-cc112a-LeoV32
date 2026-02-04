#include <iostream>
using namespace std;

int** reservaMemoria(int fila,int columna){
    int**Matriz=new int*[fila];
    for(int i=0;i<n;i++){
        Matriz=new int[columna];
    }

    return Matriz;
}

void llenarMatriz(int** M,int fila,int columna){
    for(int i=0;i<fila;i++){
        for(j=0;j<columna;j++){
            M[i][j]=rand()%19-9;
        }
    }
}

void modificar(int**M,int fila,int columna){
    for(int i=0;i<fila;i++){
        int suma=0;
        for(int j=0;j<columna;j++){
            suma+=M[i][j];
        }
        if(suma%2==0){
            
        }
    }
}

int main(){
    int fila;
    int columna;
    cout<<"Ingresa el numero de filas y columnas respectivamente: "<<endl;
    cin>>fila;
    cin>>columna;
    int**M=reservaMemoria(fila,columna);
}

