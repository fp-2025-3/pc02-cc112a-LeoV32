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
void mayorVendedor(const char* venta,const char* reporte);
void mayorProducto(const char* venta,const char* reporte);
void ventasSospechosas(const char* venta,const char* reporte);

int main(){
    char venta[]="entradas/ventas.dat";
    char reporte[]="output/reporte.txt";
    
    ofstream archivo(reporte, ios::out | ios::app);
    if(!archivo){
        cerr<<"Error al abrir el reporte"<<endl;
        return -1;
    }

    archivo<<"--- REPORTE GENERAL DE VENTAS ----"<<endl<<endl;
    archivo<<"Total de registros: "<<totalRegistrados(venta)<<endl<<endl;
    archivo<<"Monto total vendido: "<<endl<<"S/. "<<montoTotal(venta)<<endl<<endl;
    archivo<<"---------------------------------------"<<endl;
    mayorVendedor(venta,reporte);
    archivo<<"---------------------------------------"<<endl;
    mayorProducto(venta,reporte);
    archivo<<"---------------------------------------"<<endl;
    ventasSospechosas(venta,reporte);
    cout<<"Se realizo el reporte correctamente."<<endl;

    return 0;
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

void mayorVendedor(const char* venta,const char* reporte){
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
    ofstream archivoEscritura(reporte, ios::out | ios::app);
    if(!archivoEscritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    archivoEscritura<<"VENDEDOR CON MAYOR RECAUDACIÓN: "<<endl;
    archivoEscritura<<"ID Vendedor: "<<IDmax<<endl;
    archivoEscritura<<"Total vendido: "<<maxCantidad<<endl<<endl;
    archivoEscritura.close();
}

void mayorProducto(const char* venta,const char* reporte){
    ifstream archivo(venta, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return;
    }

    int Prod[200];
    Venta e;
    int k=0;
    
    while(archivo.read((char*)&e,sizeof(Venta))){
        bool unico=true;

        for(int i=0;i<k;i++){
            if(Prod[i]==e.idProducto){
                unico=false;
                break;
            }
        }
        if(unico){
            Prod[k]=e.idProducto;
            k++;
        }
    }
    int max=0;
    int idMax=0;
    for(int i=0;i<k;i++){
        int cont=0;
        archivo.clear();
        archivo.seekg(0,ios::beg);
        while(archivo.read((char*)&e,sizeof(Venta))){
            if(Prod[i]==e.idProducto) cont++;
        }
        if(max<cont){
            idMax=Prod[i];
            max=cont;
        }
    }
    archivo.close();
    ofstream archivoEscritura(reporte, ios::out | ios::app);
    if(!archivoEscritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    
    archivoEscritura<<"PRODUCTO MÁS VENDIDO: "<<endl;
    archivoEscritura<<"ID Producto: "<<idMax<<endl;
    archivoEscritura<<"Total unidades: "<<max<<endl<<endl;
    archivoEscritura.close();
}

void ventasSospechosas(const char* venta,const char* reporte){
    ifstream archivo(venta, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al leer el archivo"<<endl;
        return;
    }

    ofstream archivoEscritura(reporte, ios::out | ios::app);
    if(!archivoEscritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    Venta e;
    archivoEscritura<<"VENTAS SOSPECHOSAS (cantidad > 100): "<<endl<<endl;
    while(archivo.read((char*)&e,sizeof(Venta))){
        if(e.cantidad>100){
            archivoEscritura<<"ID Venta: "<<e.idVenta<<" | Vendedor: "<<e.idVendedor;
            archivoEscritura<<" | Producto: "<<e.idProducto<<" | Cantidad: "<<e.cantidad<<endl;
        } 
    }
    archivo.close();
    archivoEscritura.close();
}
