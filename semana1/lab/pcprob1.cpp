#include <iostream>
using namespace std;

void crear(int arr[100][100],int n,int i);
void imprimir(int arr[100][100],int n);

int main(){
    int n;
    int arr[100][100];
    int i=0;
    cout<<"Ingrese el tamanio de la matriz: ";
    cin>>n;
    cout<<endl;
    crear(arr,n,i);
    imprimir(arr,n);

}

void crear(int arr[100][100],int n,int i){
    
    if(i>=n) return;

    arr[i][0]=1;
    arr[i][i]=1;
    for(int j=0;j<n;j++){
        if(i>=2 && j<i){
            arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
        } else if(j>=1 && j>i){
            arr[i][j]=0;
        }
    }
    crear(arr,n,i+1);    
}

void imprimir(int arr[100][100],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}