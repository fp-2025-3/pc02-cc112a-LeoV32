#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void seleccion(int arr[8][8],int n);
void imprimir(int arr[8][8],int n);

int main(){
    int n;
    int arr[8][8];
    do{
        cout<<"Ingrese el tamaño de la matriz cuadrada de 2-8: ";
        cin>>n;
    }while(n<2 || n>8);

    cout<<endl;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=rand()%101;
        }
    }
    cout<<"Original: "<<endl;
    imprimir(arr,n);
    cout<<endl<<endl;
    cout<<"Ordenada: "<<endl;
    seleccion(arr,n);
    imprimir(arr,n);

}

void seleccion(int arr[8][8],int n){
    int total=n*n;
    for(int p=0;p<total-1;p++){
        int minpos=p;

        for(int q=p+1;q<total;q++){
            int i1=minpos/n;
            int j1=minpos%n;
            int i2=q/n;
            int j2=q%n;
            if(arr[i1][j1]>arr[i2][j2]){
                minpos=q;
            }
        }
        int i1=minpos/n;
        int j1=minpos%n;
        int i2=p/n;
        int j2=p%n;
        swap(arr[i1][j1],arr[i2][j2]);



    }
}

void imprimir(int arr[8][8],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}


