#include <iostream>
#include <cstring>
using namespace std;
struct Producto{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

Producto crearProducto(int codigo,const char* nombre,double precio,int stock);
Producto* crearInventario(int n);
void mostrarInventario(Producto* inventario,int n);
Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado);

int main(){
    int n,buscar;
    cout<<"Ingrese la cantidad de productos: "<<endl;
    cin>>n;
    Producto* a= crearInventario(n);
    mostrarInventario(a,n);
    cout<<"Ingrese el codigo del producto a buscar: "<<endl;
    cin>>buscar;
    cout<<"Buscando producto con codigo "<<buscar<<"..."<<endl;
    Producto* b=buscarProducto(a,n,buscar);
    if(b!=NULL) cout<<"Producto encontrado: "<<b->nombre<<" | Precio: "<<b->precio<<endl;
    else  cout<<"No se encontro el producto "<<endl;

    for(int i=0;i<n;i++){
        delete[] a[i].nombre;
    }

    delete[] a;

    return 0;
}

Producto crearProducto(int codigo,const char* nombre,double precio,int stock){
    Producto nuevo;
    nuevo.codigo=codigo;
    int l=strlen(nombre);
    nuevo.nombre=new char[l+1];
    char* inicio=nuevo.nombre;
    for(const char* i=nombre;i<=nombre+l;i++,inicio++){
        *inicio=*i;
    }
    nuevo.precio=precio;
    nuevo.stock=stock;

    return nuevo;
}

Producto* crearInventario(int n){
    
    Producto* arreglo=new Producto[n];
    for(int i=0;i<n;i++){
        int codigo;
        char nombre[20];
        double precio;
        int stock;

        cout<<"Producto "<<i+1<<": "<<endl;
        cout<<"Codigo: ";
        cin>>codigo;
        cout<<"Nombre: ";
        cin.ignore();
        cin.getline(nombre,20);
        cout<<"Precio: ";
        cin>>precio;
        cout<<"Stock: ";
        cin>>stock;

        arreglo[i]=crearProducto(codigo,nombre,precio,stock);
    }
    return arreglo;
}

Producto* buscarProducto(Producto* inventario,int n,int codigoBuscado){
    for(Producto* i=inventario;i<inventario+n;i++){
        if(codigoBuscado==i->codigo) return i;
    }
    return NULL;
}

void mostrarInventario(Producto* inventario,int n){
    cout<<"             Inventario: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<inventario[i].codigo<<" | ";
        cout<<"Nombre: "<<inventario[i].nombre<<" | ";
        cout<<"Precio: "<<inventario[i].precio<<" | ";
        cout<<"Stock: "<<inventario[i].stock<<" | "<<endl;
    }
}
