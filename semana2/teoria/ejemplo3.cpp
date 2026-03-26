#include <iostream>
using namespace std;
void duplicarconindices(int* arr,int n);
void imprimir(int* arr,int n);
void duplicarconpuntero(int* arr,int n);

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);

    imprimir(arr,n);
    duplicarconindices(arr,n);
    imprimir(arr,n);
    duplicarconpuntero(arr,n);
    imprimir(arr,n);


}

void duplicarconindices(int* arr,int n){
    for(int i=0;i<n;i++){
        *(arr+i)=*(arr+i) * 2;
    }
}

void imprimir(int* arr,int n){
    cout<<"Arreglo: "<<endl;
    for(int* pd=arr;pd<arr+n;pd++){
        cout<<*pd<<"  ";
    }
    cout<<endl<<endl;
}

void duplicarconpuntero(int* arr,int n){
    int* pd=NULL;
    for(pd=arr;pd<arr+n;pd++){
        *pd=(*pd) * 2;
    }
}