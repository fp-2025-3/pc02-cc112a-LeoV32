#include <iostream>
using namespace std;

void imprimir(int arr[],int n);
void dominantesIterativo(int arr[],int n);
void dominantesRecursivo(int arr[],int n,int i);

int main(){
    int A[]={5,3,8,6,2,1};
    int i=0;
    int n=sizeof(A)/sizeof(A[0]);
    imprimir(A,n);
    cout<<endl;
    cout<<"Los elementos dominantes son: ";
    dominantesRecursivo(A,n,i);
    cout<<endl;
    return 0;
}

void dominantesIterativo(int arr[],int n){
    for(int i=0;i<n;i++){
        bool mayor=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                mayor=false;
            }
        }
        if(mayor==true){
            cout<<arr[i]<<"  ";
        }
    }
}

void dominantesRecursivo(int arr[],int n,int i){
    if(i>=n) return;

    bool mayor=true;
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                mayor=false;
            }
        }
        if(mayor==true){
            cout<<arr[i]<<"  ";
        }
    dominantesRecursivo(arr,n,i+1);
}

void imprimir(int arr[],int n){
    cout<<"Arreglo: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}