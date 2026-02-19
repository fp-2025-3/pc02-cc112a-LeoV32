#include <iostream>
using namespace std;

bool estaOrdenadoIterativa(const int arr[], int n);
bool estaOrdenadoRecursiva(const int arr[], int n);


int main(){
    int arr1[]={1,3,2,4};
    int n1=sizeof(arr1)/sizeof(arr1[0]);
    int arr2[]={1,2,3,4};
    int n2=sizeof(arr2)/sizeof(arr2[0]);
    if(estaOrdenadoIterativa(arr1,n1)){
        cout<<"el arreglo esta ordenado"<<endl;
    } else cout<<"no esta ordenado"<<endl;
    if(estaOrdenadoRecursiva(arr2,n2)){
        cout<<"el arreglo esta ordenado"<<endl;
    } else cout<<"no esta ordenado"<<endl;
}

bool estaOrdenadoIterativa(const int arr[], int n){
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}

bool estaOrdenadoRecursiva(const int arr[], int n){

    if(n<=2) return true;

    if(arr[n-2]>arr[n-1]){
            return false;
        } else return estaOrdenadoRecursiva(arr,n-1);
}