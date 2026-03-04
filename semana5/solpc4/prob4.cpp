#include <iostream>
#include <cstring>
using namespace std;

struct Item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

Item crearItem(const char* descripcion,int cantidad,double precio);
Pedido* crearPedido(int numero,const char* cliente,int cantidadItems);
double calcularTotal(const Pedido* p);
Item* itemMasCaro(Pedido* p);
void liberarPedido(Pedido* p);

int main(){
    int n,cant;
    cout<<"Ingrese el numero del pedido: ";
    cin>>n;
    cout<<"Ingrese el nombre del cliente: ";
    char nombre[20]; 
    cin.ignore();
    cin.getline(nombre,20);
    cout<<"Ingrese la cantidad de items: ";
    cin>>cant;
    Pedido* a=crearPedido(n,nombre,cant);
    
    cout<<"Pedido N°: "<<n<<endl;
    cout<<"Cliente: "<<nombre<<endl<<endl;
    cout<<"Items: "<<endl;
    for(int i=0;i<cant;i++){
        cout<<"-"<<a->items[i].descripcion<<" | ";
        cout<<"Cant: "<<a->items[i].cantidad<<" | ";
        cout<<"Precio: "<<a->items[i].precioUnitario<<endl;
    }
    cout<<endl<<"Total: "<<calcularTotal(a);
    Item* b=itemMasCaro(a);
    cout<<"Item mas caro: "<<b->descripcion<<" | Precio: "<<b->precioUnitario<<endl;
    
    liberarPedido(a);

}

Item crearItem(const char* descripcion,int cantidad,double precio){
    Item nuevo;
    int l=strlen(descripcion);
    nuevo.descripcion=new char[l+1];
    char* e=nuevo.descripcion;
    for(const char* i=descripcion;i<descripcion+l+1;i++,e++){
        *e=*i;

    }
    nuevo.cantidad=cantidad;
    nuevo.precioUnitario=precio;

    return nuevo;
}

Pedido* crearPedido(int numero,const char* cliente,int cantidadItems){
    Pedido* nuevo=new Pedido;
    nuevo->numPedido=numero;
    int l=strlen(cliente);
    nuevo->nombreCliente=new char[l+1];
    char* inicio=nuevo->nombreCliente;
    for(const char* i=cliente;i<cliente+l+1;i++,inicio++){
        *inicio=*i;
    }
    nuevo->items=new Item[cantidadItems];
    nuevo->cantidadItems=cantidadItems;
    for(int i=0;i<nuevo->cantidadItems;i++){
        char texto[30];
        int cant;
        double p;
        cout<<"Item "<<i+1<<": "<<endl;
        cout<<"Ingrese la descripcion: ";
        cin.ignore();
        cin.getline(texto,30);
        cout<<"Ingrese la cantidad: ";
        cin>>cant;
        cout<<"Ingrese el precio: ";
        cin>>p;

        nuevo->items[i]=crearItem(texto,cant,p);
    }
    return nuevo;
}

double calcularTotal(const Pedido* p){
    double total=0;
    for(int i=0;i<p->cantidadItems;i++){
        total+=p->items[i].cantidad*p->items[i].precioUnitario;
    }

    return total;
}

Item* itemMasCaro(Pedido* p){
    int caro=0;
    for(int i=0;i<p->cantidadItems;i++){
        if(p->items[caro].precioUnitario<p->items[i].precioUnitario) caro=i;
    }
    return &p->items[caro];
}

void liberarPedido(Pedido* p){
    delete[] p->nombreCliente;
    for(int i=0;i<p->cantidadItems;i++){
        delete[] p->items[i].descripcion;
    }
    delete[] p->items;
    delete p;
}
