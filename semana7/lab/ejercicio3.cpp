#include <iostream>
#include <fstream>
using namespace std;

struct Venta {
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int totalRegistrados(const char* venta);
double montoTotal(const char* venta);
void mayorVendedor(const char* venta);

int main(){
    char venta[]="entradas/ventas.dat";

    cout<<"--- REPORTE GENERAL DE VENTAS ----"<<endl<<endl;
    cout<<"Total de registros: "<<totalRegistrados(venta)<<endl<<endl;
    cout<<"Monto total vendido: "<<endl<<"S/. "<<montoTotal(venta)<<endl<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<"VENDEDOR CON MAYOR RECAUDACIÓN: "<<endl;
    mayorVendedor(venta);
}

int totalRegistrados(const char* venta){
    ifstream archivo(venta, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return -1;
    }
    Venta e;
    int cont=0;
    
    while(archivo.read((char*)&e,sizeof(Venta))){
        cont++;
    }
    archivo.close();
    return cont;
}

double montoTotal(const char* venta){
    ifstream archivo(venta, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return -1;
    }
    Venta e;
    double suma=0.00;
    
    while(archivo.read((char*)&e,sizeof(Venta))){
        suma=suma+e.cantidad*e.precioUnitario;
    }
    archivo.close();
    return suma;
}

void mayorVendedor(const char* venta){
    ifstream archivo(venta, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return;
    }
    Venta e;
    int IDvendedor[200];
    int k=0;
    
    while(archivo.read((char*)&e,sizeof(Venta))){
        bool nuevo=true;
        for(int i=0;i<k;i++){
            if(IDvendedor[i]==e.idVendedor){
                nuevo=false;
                break;
            }
        }
        if(nuevo){
            IDvendedor[k]=e.idVendedor;
            k++;
        }
    }
    
    double maxCantidad=0.0;
    int IDmax=0;
    for(int i=0;i<k;i++){
        double suma=0.0;
        archivo.clear();
        archivo.seekg(0,ios::beg);
        while(archivo.read((char*)&e,sizeof(Venta))){
            if(IDvendedor[i]==e.idVendedor){
                suma+=e.precioUnitario*e.cantidad;
            }
        }
        if(suma>maxCantidad){
            maxCantidad=suma;
            IDmax=IDvendedor[i];
        }
    }
    archivo.close();
    cout<<"ID Vendedor: "<<IDmax<<endl;
    cout<<"Total vendido: "<<maxCantidad<<endl;
}