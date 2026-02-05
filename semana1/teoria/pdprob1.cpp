#include <iostream>
using namespace std;

double busquedaBinaria(double arr[],int n,double number);

int main(){
    double A[]={8.8,10.1,14.4,16.6,18.8,20.5};
    int n=sizeof(A)/sizeof(A[0]);
    double peso;
    cout<<"Peso de una galleta (en gramos): ";
    cin>>peso;
    cout<<"Precio sugerido: S/. "<<busquedaBinaria(A,n,peso)/20<<endl;
    return 0;
}

double busquedaBinaria(double arr[],int n,double number){

    if(arr[0]>=number){
        return arr[0];
    } else if(arr[n-1]<=number){
        return arr[n-1];
    } else {
        int inicio=0, final=n-1;

        while(inicio<=final){
            int medio=(inicio+final)/2;
            if(arr[medio]==number){
                return arr[medio];
            } else if(arr[medio]<number){
                inicio=medio+1;
            } else {
                final=medio-1;
            }
        }
            return (arr[inicio]+arr[final])/2;
    }
}