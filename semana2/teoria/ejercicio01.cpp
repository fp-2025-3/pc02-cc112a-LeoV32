#include <iostream>
using namespace std;

int potenciaIterativa(int a, int n);
int potenciaRecursiva(int a, int n);
int potenciaRapida(int a, int n);

int main(){
    int a1=2,a2=2,a3=2;
    int n1=0,n2=5,n3=-3;
    cout<<a1<<" elevado a "<<n1<<": "<<potenciaIterativa(a1,n1)<<endl;
    cout<<a2<<" elevado a "<<n2<<": "<<potenciaIterativa(a2,n2)<<endl;
    cout<<a3<<" elevado a "<<n3<<": "<<potenciaIterativa(a3,n3)<<endl;

    return 0;
}

int potenciaIterativa(int a, int n){
    if(n>=0){
        int r=1;
        for(int i=0;i<n;i++){
            r=r*a;
        }
        return r;
    } else{
        return -1;
    }
}

int potenciaRecursiva(int a, int n){
    if(n==0) return 1;

    return a*potenciaRecursiva(a,n-1);
}

int potenciaRapida(int a,int n){
    if(n==0) return 1;

    if(n%2==0){
        int r=potenciaRapida(a,n/2);
        return r*r;
    } else{
        return a*potenciaRapida(a,n-1);
    }
}