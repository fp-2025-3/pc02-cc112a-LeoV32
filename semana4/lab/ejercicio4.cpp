#include <iostream>
using namespace std;

int costomin(int A[],int n,int i);

int main(){
    int A[]={2,3,4};
    int n=sizeof(A)/sizeof(A[0]);
    cout<<"El costo minimo es: "<<costomin(A,n,0)<<endl;
}

int costomin(int A[],int n,int i){
    if(i==n) return 0;
    int minimo=1e9;
    int producto=1;
    for(int j=i;j<n;j++){
        producto*=A[j];
        int costo=producto+costomin(A,n,j+1);
        if(costo<minimo) minimo=costo;
    }
    return minimo;
}