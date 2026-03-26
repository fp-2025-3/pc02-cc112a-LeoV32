#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

void crearArchivo(const char* nombre);
CuentaBancaria buscarCuenta(const char* nombre,int numero);
void desactivaCuenta(const char* nombre,int numero);
void mostrarCuentas(const char* nombre);

int main(){
    char nombre[]="cuentas.dat";
    crearArchivo(nombre);
    CuentaBancaria e=buscarCuenta(nombre,23);
    if(e.numeroCuenta==23){
        cout<<"Cuenta:"<<endl;
        cout<<"Numero de cuenta: "<<e.numeroCuenta<<endl;
        cout<<"Titular: "<<e.titular<<endl;
        cout<<"Saldo: "<<e.saldo<<endl<<endl;
    }
    desactivaCuenta(nombre,23);
    mostrarCuentas(nombre);

    return 0;
}

void crearArchivo(const char* nombre){
    int n;
    cout<<"Ingrese el numero de cuentas a ingresar: ";
    cin>>n;
    fstream archivo(nombre, ios::binary | ios:: out | ios::in);
    if(!archivo){
        archivo.open(nombre,ios::binary);
        archivo.close();
        archivo.open(nombre, ios::binary | ios:: out | ios::in);
    }
    CuentaBancaria cuenta;
    for(int i=0;i<n;i++){

        cout<<"Ingrese el numero de cuenta: "<<endl;
        cin>>cuenta.numeroCuenta;
        
        archivo.seekg(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));
        CuentaBancaria temp;
        archivo.read((char*)&temp,sizeof(CuentaBancaria));
        archivo.clear();
        if(temp.numeroCuenta==cuenta.numeroCuenta){
            cout<<"Esa cuenta ya fue registrada"<<endl;
            i--;
        }else{
            archivo.seekp(sizeof(CuentaBancaria)*(cuenta.numeroCuenta-1));
            cout<<"Ingrese el nombre del titular: "<<endl;
            cin.ignore();
            cin.getline(cuenta.titular,40);
            cout<<"Ingrese el saldo: "<<endl;
            cin>>cuenta.saldo;
            cuenta.activa=true;
            cout<<endl;

            archivo.write((char*)&cuenta,sizeof(CuentaBancaria));
        }
    }

    archivo.close();
}

CuentaBancaria buscarCuenta(const char* nombre,int numero){
    ifstream archivo(nombre, ios::binary | ios::in);
    CuentaBancaria e;
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return e;
    }
        archivo.seekg(sizeof(CuentaBancaria)*(numero-1));
        archivo.read((char*)&e,sizeof(CuentaBancaria));
        archivo.close();
    
        return e;
}

void desactivaCuenta(const char* nombre,int numero){
    fstream archivo(nombre, ios::binary | ios::out | ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    CuentaBancaria e;
    archivo.seekg(sizeof(CuentaBancaria)*(numero-1));
    archivo.read((char*)&e,sizeof(CuentaBancaria));
    e.activa=false;
    archivo.seekp(sizeof(CuentaBancaria)*(numero-1));
    archivo.write((char*)&e,sizeof(CuentaBancaria));

    archivo.close();
}

void mostrarCuentas(const char* nombre){
    fstream archivo(nombre, ios::binary | ios::out | ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    CuentaBancaria e;
    while(archivo.read((char*)&e,sizeof(CuentaBancaria))){
        archivo.clear();
        if(e.activa==true){
            cout<<"Cuenta Bancaria: "<<endl;
            cout<<"Numero de cuenta: "<<e.numeroCuenta<<endl;
            cout<<"Titular: "<<e.titular<<endl;
            cout<<"Saldo: s/."<<e.saldo<<endl<<endl;
        }
    }
    archivo.close();
}