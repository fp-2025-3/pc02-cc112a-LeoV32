#include <iostream>
using namespace std;

struct Producto{
    int codigo;
    float precio;
    Producto* siguiente;
};

int main(){
    Producto* cabeza =NULL;

    for(int i=0;i<2;i++){
        Producto* nuevo=new Producto;
        cout<<"Ingrese codigo: ";
        cin>>nuevo->codigo;
        cout<<"Ingrese precio: ";
        cin>>nuevo->precio;
        cout<<endl;
        nuevo->siguiente=cabeza;
        cabeza=nuevo;
    }
    Producto* n=cabeza;
    while(n!=NULL){
        cout<<"Producto: "<<endl;
        cout<<"Codigo: "<<n->codigo<<endl;
        cout<<"Precio: "<<n->precio<<endl;
        cout<<endl;
        n=n->siguiente;
    }

    while(cabeza!=NULL){
        Producto* nuevo=new Producto;
        nuevo=cabeza->siguiente;
        delete[] cabeza;
        cabeza=nuevo;
    }
}