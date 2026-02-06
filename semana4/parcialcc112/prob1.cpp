#include <iostream>
using namespace std;

int costoTotal(int A[],int n,int i);

int main(){

    int A[]={1,2,3,4,5};
    int nA=sizeof(A)/sizeof(A[0]);
    if(nA<=15 && nA>=1){
        cout<<"Costo total del arreglo A: "<<costoTotal(A,nA,0)<<endl;
    } else cout<<"ERROR"<<endl;

    int B[]={2,1,3};
    int nB=sizeof(B)/sizeof(B[0]);
    if(nA<=15 && nA>=1){
        cout<<"Costo total del arreglo B: "<<costoTotal(B,nB,0)<<endl;
    } else cout<<"ERROR"<<endl;

    return 0;
}

int costoTotal(int A[],int n,int i){
    if(n==i) return 0;

    int producto=1;
    int minimo=1e9;
    int suma=0;
    for(int j=i;j<n;j++){
        producto*=A[j];
        suma=producto+costoTotal(A,n,j+1);
        if(minimo>suma) minimo=suma;
    }
    return minimo;
}

/*
Si el arreglo fuera A={2,1,3}
entra al for y los segmentos que va tener en orden seran
{2},{1},{3} = 6
{2},{1,3}   = 5
{2,1},{3}   = 5
{2,1,3}     = 6
y evaluando todos esos casos retorna 5.

*/