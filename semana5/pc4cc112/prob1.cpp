#include <iostream>
using namespace std;

struct Polinomio{
    int* coeficientes;
    int n;
};

Polinomio sumarTres(Polinomio e1,Polinomio e2,Polinomio e3);
Polinomio multiplicarTres(Polinomio e1,Polinomio e2,Polinomio e3);
void imprimir(Polinomio e);

int main(){
    Polinomio e1,e2,e3;
    e1.n=2;
    e1.coeficientes=new int[e1.n];
    e1.coeficientes[0]=3;
    e1.coeficientes[1]=0;
    e1.coeficientes[2]=2;

    e2.n=1;
    e2.coeficientes=new int[e2.n];
    e2.coeficientes[0]=5;
    e2.coeficientes[1]=-4;

    e3.n=2;
    e3.coeficientes=new int[e3.n];
    e3.coeficientes[0]=1;
    e3.coeficientes[1]=0;
    e3.coeficientes[2]=3;
    Polinomio suma=sumarTres(e1,e2,e3);
    Polinomio producto=multiplicarTres(e1,e2,e3);

    cout<<"Polinomio 1: ";
    imprimir(e1);
    cout<<"Polinomio 2: ";
    imprimir(e2);
    cout<<"Polinomio 3: ";
    imprimir(e3);
    cout<<"Suma de los tres polinomios: ";
    imprimir(suma);
    cout<<"Producto de los tres polinomios: ";
    imprimir(producto);

    return 0;
}

Polinomio sumarTres(Polinomio e1,Polinomio e2,Polinomio e3){
    int mayor=0;
    if(e1.n>=e2.n && e1.n>=e3.n) mayor=e1.n;
    else if(e2.n>=e1.n && e2.n>=e3.n) mayor=e2.n;
    else mayor=e3.n;

    Polinomio resultado;
    resultado.n=mayor;
    resultado.coeficientes=new int[mayor+1];

    for(int i=0;i<=mayor;i++){
        int suma=0;
        if(e1.n>=i) suma+=e1.coeficientes[i];
        if(e2.n>=i) suma+=e2.coeficientes[i];
        if(e3.n>=i) suma+=e3.coeficientes[i];
        resultado.coeficientes[i]=suma;
    }

    return resultado;
}

Polinomio multiplicarTres(Polinomio e1,Polinomio e2,Polinomio e3){

    Polinomio resultado;
    resultado.n=e1.n+e2.n+e3.n;
    resultado.coeficientes=new int[resultado.n+1];

    for(int i=0;i<=resultado.n;i++){
        resultado.coeficientes[i]=0;
    }

    for(int i=0;i<=e1.n;i++){
        for(int j=0;j<=e2.n;j++){
            for(int k=0;k<=e3.n;k++){
                resultado.coeficientes[i+j+k]+=e1.coeficientes[i]*e2.coeficientes[j]*e3.coeficientes[k];
            }
        }
    }

    return resultado;
}

void imprimir(Polinomio e){
    for(int i=e.n;i>=0;i--){
        if(i!=0) cout<<e.coeficientes[i]<<"x^"<<i<<" + ";
        else cout<<e.coeficientes[i];
    }
    cout<<endl;
}
