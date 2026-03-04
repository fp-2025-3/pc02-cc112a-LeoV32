#include <iostream>
#include <fstream>
using namespace std;

struct Venta{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int totalRegistros(const char* nombre);
double montoTotal(const char* nombre);
void vendedorMayor(const char* nombre,int n,const char* reporte);
void productoMayor(const char* nombre,int n,const char* reporte);
void ventasSospechosas(const char* nombre,const char* reporte);

int main(){
    char archivo[]="ventas.dat";
    char reporte[]="reporte.txt";
    ofstream Escritura(reporte, ios::out | ios::app);
    if(!Escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    int n;
    n=totalRegistros(archivo);
    Escritura<<"--- REPORTE GENERAL DE VENTAS ---"<<endl<<endl;
    Escritura<<"Total de registros: "<<n<<endl<<endl;
    Escritura<<"MONTO TOTAL VENDIDO:"<<endl;
    Escritura<<"S/. "<<montoTotal(archivo)<<endl<<endl;
    Escritura<<"---------------------"<<endl;
    vendedorMayor(archivo,n,reporte);
    Escritura<<"---------------------"<<endl;
    productoMayor(archivo,n,reporte);
    ventasSospechosas(archivo,reporte);
    Escritura.close();
    cout<<"Se genero el archivo de reporte correctamente"<<endl;

    return 0;
}

int totalRegistros(const char* nombre){
    ifstream archivo(nombre, ios::in | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    int cont=0;
    Venta e;
    while(archivo.read((char*)&e,sizeof(Venta))){
        cont++;
    }

    archivo.close();

    return cont;
}

double montoTotal(const char* nombre){
    ifstream archivo(nombre, ios::in | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }

    double suma=0.0;
    Venta e;
    while(archivo.read((char*)&e,sizeof(Venta))){
        suma+=e.cantidad*e.precioUnitario;
    }

    archivo.close();

    return suma;
}

void vendedorMayor(const char* nombre,int n,const char* reporte){
    ifstream archivo(nombre, ios::in | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    int k=0;
    Venta e;
    int* arr = new int[n];
    while(archivo.read((char*)&e,sizeof(Venta))){
        bool unico=true;
        for(int i=0;i<k;i++){
            if(e.idVendedor==arr[i]){
                unico=false; 
                break;
            } 
        }
        if(unico){
            arr[k]=e.idVendedor;
            k++;
        }
    }

    int maxID=0;
    double maxTotal=0;

    for(int i=0;i<k;i++){
        archivo.clear();
        archivo.seekg(0, ios::beg);
        double suma=0.0;
        while(archivo.read((char*)&e,sizeof(Venta))){
            if(arr[i]==e.idVendedor) suma+=e.cantidad*e.precioUnitario;
        }
        if(suma>maxTotal){
            maxID=arr[i];
            maxTotal=suma;
        }
    }
    delete[] arr;
    archivo.close();

    ofstream Escritura(reporte, ios::out | ios::app);
    if(!Escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    Escritura<<"VENDEDOR CON MAYOR RECAUDACION: "<<endl;
    Escritura<<"ID Vendedor: "<<maxID<<endl;
    Escritura<<"Total vendido: S/. "<<maxTotal<<endl<<endl;
    Escritura.close();

}

void productoMayor(const char* nombre,int n,const char* reporte){
    ifstream archivo(nombre, ios::in | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    int k=0;
    Venta e;
    int* arr = new int[n];
    while(archivo.read((char*)&e,sizeof(Venta))){
        bool unico=true;
        for(int i=0;i<k;i++){
            if(e.idProducto==arr[i]){
                unico=false; 
                break;
            } 
        }
        if(unico){
            arr[k]=e.idProducto;
            k++;
        }
    }

    int maxID=0;
    int maxTotal=0;

    for(int i=0;i<k;i++){
        archivo.clear();
        archivo.seekg(0, ios::beg);
        int cant=0;
        while(archivo.read((char*)&e,sizeof(Venta))){
            if(arr[i]==e.idProducto) cant+=e.cantidad;
        }
        if(cant>maxTotal){
            maxID=arr[i];
            maxTotal=cant;
        }
    }
    delete[] arr;
    archivo.close();

    ofstream Escritura(reporte, ios::out | ios::app);
    if(!Escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    Escritura<<"PRODUCTO MAS VENDIDO: "<<endl;
    Escritura<<"ID Producto: "<<maxID<<endl;
    Escritura<<"Total unidades: "<<maxTotal<<endl<<endl;
    Escritura.close();
}

void ventasSospechosas(const char* nombre,const char* reporte){
    ifstream archivo(nombre, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    ofstream Escritura(reporte, ios::out | ios::app);
    if(!Escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    Escritura<<"VENTAS SOSPECHOSAS (cantidad>100):"<<endl<<endl;
    Venta e;
    while(archivo.read((char*)&e,sizeof(Venta))){
        if(e.cantidad>100){
            Escritura<<"Id: "<<e.idVenta<<"\t| Vendedor: "<<e.idVendedor<<"\t| Producto: "<<e.idProducto<<"\t| Cantidad: "<<e.cantidad<<endl;
        }
    }
    archivo.close();
    Escritura.close();
}