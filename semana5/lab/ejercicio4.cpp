#include <iostream>
using namespace std;

struct Polinomio{
    int n;
    int* coef;
};

void Leer(Polinomio e1,Polinomio e2);
void imprimir(Polinomio e);

int main(){
    Polinomio e1,e2;
    Leer(e1,e2);
    imprimir(e1);
    imprimir(e2);
    
}

void Leer(Polinomio e1,Polinomio e2){
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