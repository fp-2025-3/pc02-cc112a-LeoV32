#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

int main(){

}

long buscarCuenta(const char* nombre, long numero){
    ifstream archivo(nombre, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    CuentaBancaria e;
    long inicio=0;
    long fin=0;

    while(archivo.read((char*)&e,sizeof(CuentaBancaria))){
        fin++;
    }

    while(inicio<=fin){
        long medio=(inicio+fin)/2;
        archivo.clear();
        archivo.seekg(medio*sizeof(CuentaBancaria), ios::beg);
        archivo.read((char*)&e,sizeof(CuentaBancaria));

        if(e.numeroCuenta==numero){
            archivo.close();
            return medio;
        } 

        if(e.numeroCuenta<numero) inicio=medio+1;
        else fin=medio-1;
    }
    
    archivo.close();
    return -1;
}

void ingresarCuentas(const char* nombre,int n){
    fstream archivo(nombre, ios::binary | ios::out | ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    CuentaBancaria e;

    for(int i=0;i<n;i++){

        cout<<"CUENTA: "<<endl;
        cout<<"Ingrese el numero de cuenta: ";
        cin>>e.numeroCuenta;
        cout<<"Ingrese el nombre del titular: ";
        cin.ignore();
        cin.getline(e.titular,40);
        cout<<" Ingrese el saldo: ";
        cin>>e.saldo;
        e.activa=true;
        cout<<endl;

        if(buscarCuenta(nombre,e.numeroCuenta)==-1){
            CuentaBancaria a;
            archivo.clear();
            archivo.seekg(0, ios::beg);
            int cont=0;
            while(archivo.read((char*)&a,sizeof(CuentaBancaria))){
                if(a.numeroCuenta>e.numeroCuenta) break;
                cont++;
            }
            

        }else cout<<"Esa cuenta ya a sido registrada"<<endl;

    }
}