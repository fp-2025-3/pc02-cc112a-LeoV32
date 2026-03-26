#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
   double x;
   double y;
};

void leerPunto(Punto* p);
double distanciaOrigen(const Punto* p);
Punto* masLejano(Punto* p1,Punto* p2);


int main(){
    Punto* a=new Punto;
    Punto* b=new Punto;
    cout<<"Punto A:"<<endl;
    leerPunto(a);
    cout<<"Punto B:"<<endl;
    leerPunto(b);
    Punto* res=masLejano(a,b);
    cout<<"Punto mas lejano:"<<endl;
    cout<<"x: "<<res->x<<endl;
    cout<<"y: "<<res->y<<endl;

    delete a;
    delete b;
    return 0;
}

void leerPunto(Punto* p){
    cout<<"Ingrese la coordenada x: ";
    cin>>p->x;
    cout<<"Ingrese la coordenada y: ";
    cin>>p->y;
    cout<<endl;
}

double distanciaOrigen(const Punto* p){
    double res=0;
    res = sqrt(pow(p->x,2)+pow(p->y,2));
    return res;
}

Punto* masLejano(Punto* p1,Punto* p2){
    double a=distanciaOrigen(p1);
    double b=distanciaOrigen(p2);
    if(a>=b) return p1;
    else return p2;
}