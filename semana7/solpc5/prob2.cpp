#include <iostream>
#include <fstream>
using namespace std;

struct Empleado{
    int id;
    char nombre[30];
    double salario;
};

int main(){
    int n;
    cout<<"Ingrese el ID de empleado: ";
    cin>>n;

    fstream archivo ("empleados.dat", ios::in | ios::out | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    archivo.seekg((n-1)*sizeof(Empleado),ios::beg);
    Empleado e;
    double nuevo;
    archivo.read((char*)&e,sizeof(Empleado));
    cout<<endl<<"--- DATOS DEL EMPLEADO ---"<<endl;
    cout<<"ID: "<<e.id<<endl;
    cout<<"Nombre: "<<e.nombre<<endl;
    cout<<"Salario: "<<e.salario<<endl;

    cout<<"Ingrese el nuevo salario: ";
    cin>>nuevo;
    
    e.salario=nuevo;
    archivo.clear();
    archivo.seekp((n-1)*sizeof(Empleado),ios::beg);
    archivo.write((char*)&e,sizeof(Empleado));

    cout<<endl<<"Salario actualizado correctamente"<<endl;

    archivo.close();
    return 0;
}