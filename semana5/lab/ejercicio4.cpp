#include <iostream>
#include <cmath>
using namespace std;

struct Polinomio{
    int n;
    int* coef;
};

void Leer(Polinomio &e1,Polinomio &e2);
void imprimir(Polinomio e);
Polinomio suma(Polinomio e1,Polinomio e2);
Polinomio producto(Polinomio e1,Polinomio e2);
int evaluandoValor(Polinomio e,int n);

int main(){
    Polinomio e1,e2;
    Leer(e1,e2);
    cout<<"Primer polinomio: ";
    imprimir(e1);
    cout<<"Segundo polinomio: ";
    imprimir(e2);
    Polinomio sumas=suma(e1,e2);
    cout<<"La suma de polinomios es: ";
    imprimir(sumas);
    Polinomio productos=producto(e1,e2);
    cout<<"El producto de polinomios es: ";
    imprimir(productos);
    cout<<"El primer polinomio evaluado en x=2 es: "<<evaluandoValor(e1,2)<<endl;
    
    delete[] e1.coef;
    delete[] e2.coef;
    delete[] sumas.coef;
    delete[] productos.coef;

    return 0;
}

void Leer(Polinomio &e1,Polinomio &e2){
    cout<<"Ingrese el grado del primer polinomio: ";
    cin>>e1.n;
    e1.coef=new int[e1.n+1];
    for(int i=e1.n;i>=0;i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>e1.coef[i];
    }
    cout<<"Ingrese el grado del segundo polinomio: ";
    cin>>e2.n;
    e2.coef=new int[e2.n+1];
    for(int i=e2.n;i>=0;i--){
        cout<<"Ingrese el coeficiente de x^"<<i<<": ";
        cin>>e2.coef[i];
    }
}

void imprimir(Polinomio e){

    for(int i=e.n;i>=0;i--){
        if(i>0) cout<<e.coef[i]<<"x^"<<i<<" + ";
        else cout<<e.coef[i];
    }
    cout<<endl;
}

Polinomio suma(Polinomio e1,Polinomio e2){
    Polinomio resultado;
    if(e1.n<e2.n) resultado.n=e2.n;
    else resultado.n=e1.n;
    
    resultado.coef=new int[resultado.n+1];
    for(int i=0;i<=resultado.n;i++){
        if(e1.n>=i && e2.n>=i) resultado.coef[i]=e1.coef[i]+e2.coef[i];
        else{
                if(e1.n<i) resultado.coef[i]=e2.coef[i];
                if(e2.n<i) resultado.coef[i]=e1.coef[i];
        }
    }
    return resultado;
}

Polinomio producto(Polinomio e1,Polinomio e2){
    Polinomio resultado;
    resultado.n=e1.n+e2.n;
    
    resultado.coef=new int[resultado.n+1]{0};
        for(int i=0;i<=e1.n;i++){
            for(int j=0;j<=e2.n;j++){
                resultado.coef[i+j]+=e1.coef[i]*e2.coef[j];
            }
        }
    
    return resultado;
}

int evaluandoValor(Polinomio e,int n){
    int suma=0;
    for(int i=e.n;i>=0;i--){
        suma+=e.coef[i]*pow(n,i);
    }
    return suma;
}