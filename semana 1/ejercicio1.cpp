#include <iostream>
using namespace std;

void burbuja(int arr[],int n);
void BurbujaRecursiva(int arr[],int n,int i);
void seleccion(int arr[],int n);
void SeleccionRecursiva(int arr[],int n,int i);
void insercion(int arr[],int n);
void InsercionRecursiva(int arr[],int n,int i);
void MergeShort(int arr[],int inicio,int final);
void merge(int arr[],int l,int m,int r);
void imprimir(int arr[],int n);

int main(){
    const int n=3;
    int i=0;
    int arreglo[n]={23,5,16};
    imprimir(arreglo,n);
    cout<<endl;
    MergeShort(arreglo,0,2);
    imprimir(arreglo,n);
    cout<<endl;
    return 0;
}

void imprimir(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}

void burbuja(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    }
}

void BurbujaRecursiva(int arr[],int n,int i){
    if(n-1 <= i) return;

        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
    BurbujaRecursiva(arr,n,i+1);
}

void seleccion(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
}

void SeleccionRecursiva(int arr[],int n,int i){
    if(n-1<=i) return;

    int min=i;
    for(int j=i+1;j<n;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    
    SeleccionRecursiva(arr,n,i+1);
}

void insercion(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int nuevo=arr[i+1];
        int k=i;
        while(k>=0,nuevo<arr[k]){
            arr[k+1]=arr[k];
            k=k-1;
        }
        arr[k+1]=nuevo;
    }
}

void InsercionRecursiva(int arr[],int n,int i){
    if(n-1<=i) return;

    int nuevo=arr[i+1];
        int k=i;
        while(k>=0,nuevo<arr[k]){
            arr[k+1]=arr[k];
            k=k-1;
        }
        arr[k+1]=nuevo;
    return InsercionRecursiva(arr,n,i+1);
}

void MergeShort(int arr[],int inicio,int final){

    if(inicio<final){
        int mitad=(inicio+final)/2;
        MergeShort(arr,inicio,mitad);
        MergeShort(arr,mitad+1,final);
        merge(arr,inicio,mitad,final);
    }
    

}
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[100],R[100];

    for(int i=0;i<n1;i++){
        L[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j]=arr[m+j+1];
    }

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=L[i];
        i++;int arr[n1+n2];
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
            j++;
            k++;
    }
}



