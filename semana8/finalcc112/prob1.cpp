#include <iostream>
using namespace std;

int** crearMatriz(int n,int m);
void llenarMatriz(int**M,int n,int m);
void mostrarMatriz(int**M,int n,int m);
int* sumaFilas(int** M,int n,int m);
void liberarMatriz(int** M,int n);

int main(){
    int n,m;
    cout<<"Ingrese el numero de filas: ";
    cin>>n;
    cout<<"Ingrese el numero de columnas: ";
    cin>>m;
    int** M=crearMatriz(n,m);
    llenarMatriz(M,n,m);
    cout<<endl;
    mostrarMatriz(M,n,m);
    cout<<endl<<"Vector resultante: ";
    int* res=sumaFilas(M,n,m);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
    liberarMatriz(M,n);
    delete[] res;

    return 0;
}

int** crearMatriz(int n,int m){
    int** matriz = new int*[n];
    for(int i=0;i<n;i++){
        matriz[i] = new int[m];
    }
    return matriz;
}

void llenarMatriz(int**M,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            M[i][j]=(i+1)*(j+1);
        }
    }
}

void mostrarMatriz(int**M,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }
}

int* sumaFilas(int** M,int n,int m){
    int* suma = new int[n];
    int k=0;
    for(int i=0;i<n;i++){
        suma[k]=0;
        for(int j=0;j<m;j++){
            suma[k]+=M[i][j];
        }
        k++;
    }
    return suma;
}

void liberarMatriz(int** M,int n){
    for(int i=0;i<n;i++){
        delete[] M[i];
    }
    delete[] M;
}