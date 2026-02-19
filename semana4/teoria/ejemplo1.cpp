#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void valores(int* arr, int n);

int main(){
    srand(time(NULL));
    int a=20;
    int* ptr = new int(a);
    cout<<"Numero: "<<*ptr<<endl;
    delete ptr;

    ptr=new int[a]();
    valores(ptr,a);
    cout<<"Arreglo: "<<endl;
    for(int i=0;i<a;i++){
        cout<<ptr[i]<<" ";
    }
    cout<<endl;
    delete[] ptr;

    cout<<"Matriz: "<<endl;
    int fila=rand()%9+1;
    int columna=rand()%9+1;
    int**M = new int*[fila];
    for(int i=0;i<fila;i++){
        M[i]=new int[columna];
    }

    for(int i=0;i<fila;i++){
        valores(M[i],columna);
    }

    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<M[i][j]<<" ";
        }
        cout<<endl;
    }

    for(int i=0;i<fila;i++){
        delete[] M[i];
    }
    delete[] M;


    return 0;
}

void valores(int* arr, int n){
    for(int i=0;i<n;i++){
        arr[i]=rand()%10;
    }
}