#include <iostream>
#include <cmath>
using namespace std;

struct Termino{
    double coeficiente;
    int exponente;
};
struct Polinomio{
    Termino* terminos;
    int cantTerminos;
};

void crearPolinomio(Polinomio &p, int n);
void leerPolinomio(Polinomio &p);
void mostrarPolinomio(const Polinomio &p);
double evaluarPolinomio(const Polinomio &p, double x);
void derivarPolinomio(const Polinomio &p, Polinomio &der);
void liberarPolinomio(Polinomio &p);

    int main(){
    Polinomio p1;

    int n1;

    cout << "Ingrese la cantidad de términos: ";
    cin >>n1;

    crearPolinomio(p1,n1);
    leerPolinomio(p1);

    cout << "Polinomio p1: "<<endl;
    mostrarPolinomio(p1);

    double x = 1;

    cout << "p1(" << x << ") = " << evaluarPolinomio(p1,x) <<endl;

    Polinomio derivada;

    cout << "Polinomio derivado" << endl;
    derivarPolinomio(p1,derivada);

    mostrarPolinomio(derivada);



    liberarPolinomio(p1);
    liberarPolinomio(derivada);

    return 0;
}


void crearPolinomio(Polinomio &p, int n){
    p.cantTerminos=n;
    p.terminos=new Termino[n];
}

void leerPolinomio(Polinomio &p){
    cout<<"Ingresa los grados y coeficientes: "<<endl<<endl;

    for(int i=0;i<p.cantTerminos;i++){
        cout<<"Coeficiente "<<i<<": ";
        cin>> p.terminos[i].coeficiente;
        cout<<"Exponente "<<i<<": ";
        cin>>p.terminos[i].exponente;
    }
    cout<<endl;
}

void mostrarPolinomio(const Polinomio &p){
    for(int i=p.cantTerminos-1;i>=0;i--){
        cout<<p.terminos[i].coeficiente<<"x^"<<p.terminos[i].exponente;
        if(i>0) cout<<" + ";
    }
    cout<<endl;
}

double evaluarPolinomio(const Polinomio &p, double x){
    double suma=0.0;
    for(int i=0;i<p.cantTerminos;i++){
        suma+=p.terminos[i].coeficiente*pow(x,p.terminos[i].exponente);
    }
    return suma;
}

void derivarPolinomio(const Polinomio &p, Polinomio &der){
    int n=0;
    for(int i=0;i<p.cantTerminos;i++){
        if(p.terminos[i].exponente!=0) n++;
    }
    

    crearPolinomio(der,n);

    for(int i=0;i<p.cantTerminos;i++){
        if(p.terminos[i].exponente!=0){
            der.terminos[i].coeficiente = p.terminos[i].coeficiente*p.terminos[i].exponente;
            der.terminos[i].exponente = p.terminos[i].exponente-1;
        }
    }
}

void liberarPolinomio(Polinomio &p){
    delete[] p.terminos;
    p.terminos=NULL;
}
