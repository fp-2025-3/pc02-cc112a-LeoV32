#include <iostream>
using namespace std;
void rotarderecha(int *arr,int n,int m);
void rotarizquierda(int *arr,int n,int m);
void imprimir(int *arr,int n);

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int r;
    char direc;
   // int m;
   // cout<<"Ingrese el tamaño del arreglo (max 100): ";
    //cin>>m;
    imprimir(arr,n);
    cout<<endl<<endl;
    cout<<"Ingrese el valor de k (cantidad de posiciones a rotar)";
    cin>>r;
    cout<<"Seleccionar la direccion derecha(d) o izquierda(i): ";
    cin>>direc;

    if(direc=='d'){
        rotarderecha(arr,n,r);
    }else{
        rotarizquierda(arr,n,r);
    }
    imprimir(arr,n);
}

void rotarderecha(int *arr,int n,int m){
    int *pd=arr+m%n;
    arr=pd;
}

void rotarizquierda(int *arr,int n,int m){
    int *pd=arr+n-m%n-1;
    arr=pd;
}

void imprimir(int *arr,int n){
    for(int *pd=arr;pd<arr+n;pd++){
        cout<<*pd<<"  ";
    }
}