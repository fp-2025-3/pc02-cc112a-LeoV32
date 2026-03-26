#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int** reservaMemoria(int fila,int columna){
    int**Matriz=new int*[fila];
    for(int i=0;i<fila;i++){
        Matriz[i]=new int[columna];
    }

    return Matriz;
}

void liberarMatriz(int** M,int fila){
    for(int i=0;i<fila;i++){
        delete[] M[i];
    }
    delete[] M;

    //Investigar si tengo que dejar en NULL a los punteros dobles
}

void llenarMatriz(int** M,int fila,int columna){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            M[i][j]=rand()%19-9;
        }
    }
}



void imprimir(int**M,int fila,int columna){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<M[i][j]<<"   ";
        }    
        cout<<endl;
    }
}

int detectarFilasValidas(int** M,int fila,int columna,bool* filasValidas){
    bool* valida=filasValidas;
    int cont=0;
    for(int i=0;i<fila;i++){
        int suma=0;
        for(int j=0;j<columna;j++){
            suma+=M[i][j];
        }    
        if(suma%2==0){
            *valida=true;
            cont++;
        } else *valida=false;
        valida++;
    }
    return cont;
}

int detectarColumnasValidas(int** M,int fila,int columna,bool* columnasValidas){
    bool* valida=columnasValidas;
    int cont=0;
    for(int i=0;i<columna;i++){
        int max=M[0][i];
        for(int j=0;j<fila;j++){
            if(max<M[j][i]) max=M[j][i];
        }
        if(max>0){
            *valida=true;
            cont++;
        } else *valida=false;
        valida++;
    }
    return cont;
}

void modificar(int** &M,int &fila,int &columna){
    bool* FilasValidas=new bool[fila];
    bool* ColumnasValidas=new bool[columna];
    int NuevaFila=detectarFilasValidas(M,fila,columna,FilasValidas);
    int NuevaColumna=detectarColumnasValidas(M,fila,columna,ColumnasValidas);

    int** Nueva=reservaMemoria(NuevaFila,NuevaColumna);
    int i2=0;
    for(int i=0;i<fila;i++){
        
        if(FilasValidas[i]==true){
            int j2=0;
            for(int j=0;j<columna;j++){
                if(ColumnasValidas[j]==true){
                    Nueva[i2][j2]=M[i][j];
                    j2++;
                }
            }
            i2++;
        }
    }
    delete[] FilasValidas;
    delete[] ColumnasValidas;
    liberarMatriz(M,fila);
    M=Nueva;
    fila=NuevaFila;
    columna=NuevaColumna;

}

int main(){
    srand(time(NULL));
    int fila;
    int columna;
    cout<<"Ingresa el numero de filas y columnas respectivamente: "<<endl;
    cin>>fila;
    cin>>columna;
    int**M=reservaMemoria(fila,columna);
    llenarMatriz(M,fila,columna);
    cout<<"Matriz Original:"<<endl;
    imprimir(M,fila,columna);
    modificar(M,fila,columna);
    cout<<"Matriz Modificada:"<<endl;
    imprimir(M,fila,columna);
    liberarMatriz(M,fila);

    return 0;

}