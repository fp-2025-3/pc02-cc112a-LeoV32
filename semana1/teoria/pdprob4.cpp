#include <iostream>
using namespace std;

void ordenar(int arr[],int n);
void imprimir(int arr[],int n);

int main(){
    int arreglo[]={9,-3,5,-2,-8,-6,1,3};
    int n=sizeof(arreglo)/sizeof(arreglo[0]);
    imprimir(arreglo,n);
    cout<<endl;
    ordenar(arreglo,n);
    imprimir(arreglo,n);
}


void ordenar(int arr[],int n){
    
    for(int i=0;i<n;i++){
        int k=i;
        if(arr[i]>=0){
            bool e=true;
            for(int j=i+1;j<n;j++){
                if(arr[j]<0 && e==true){
                    k=j;
                    e=false;
                }
            }
        }
        swap(arr[i],arr[k]);
    }
}
void imprimir(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}