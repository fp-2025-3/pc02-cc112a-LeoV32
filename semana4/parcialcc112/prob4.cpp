#include <iostream>
using namespace std;

void agregarEstudiantes(int* &codigo,double* &promedios,int &capacidad,int n);
void eliminarEstudiantes(int* &codigo,double* &promedios,int &n);

int main(){
    int capacidad=3;
    int* codigo=new int[capacidad];
    double* promedios=new double[capacidad];
    int n;

    cout<<"Colocar la cantidad de estudiantes a ingresar: ";
    cin>>n;
    agregarEstudiantes(codigo,promedios,capacidad,n);

    cout<<"Estudiantes Registrados:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
    }

    eliminarEstudiantes(codigo,promedios,n);

    cout<<"Estudiantes Aprobados:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"Codigo: "<<codigo[i]<<" Promedio: "<<promedios[i]<<endl;
    }

    delete[] codigo;
    delete[] promedios;
    return 0;
}

void agregarEstudiantes(int* &codigo,double* &promedios,int &capacidad,int n){
    int cantidad=0;
        do{
            for(int i=cantidad;i<capacidad;i++,cantidad++){
                cin.ignore();
                cout<<"Ingrese el codigo del estudiante "<<i+1<<": ";
                cin>>codigo[i];
                cin.ignore();
                cout<<"Ingrese el promedio del estudiante "<<i+1<<": ";
                cin>>promedios[i];
            }

            int* nuevoCodigo=new int[2*capacidad];
            double* nuevoPromedio=new double[2*capacidad];

            for(int i=0;i<capacidad;i++){
                nuevoCodigo[i]=codigo[i];
                nuevoPromedio[i]=promedios[i];
            }
            capacidad*=2;
            delete[] promedios;
            promedios=nuevoPromedio;
            delete[] codigo;
            codigo=nuevoCodigo;
        }while(n>=capacidad);

    
        for(int i=cantidad;i<n;i++){
            cin.ignore();
            cout<<"Ingrese el codigo del estudiante "<<i+1<<": ";
            cin>>codigo[i];
            cin.ignore();
            cout<<"Ingrese el promedio del estudiante "<<i+1<<": ";
            cin>>promedios[i];
        
        }
}

void eliminarEstudiantes(int* &codigo,double* &promedios,int &n){
    int cont=0;
    for(int i=0;i<n;i++){
        if(promedios[i]>=10) cont++;
    }

    int* nuevoCodigo=new int[cont];
    double* nuevoPromedio=new double[cont];

    for(int i=0;i<cont;i++){
        if(promedios[i]>=10.0){
            nuevoCodigo[i]=codigo[i];
            nuevoPromedio[i]=promedios[i];
        }      
    }
    n=cont;
    delete[] promedios;
    promedios=nuevoPromedio;
    delete[] codigo;
    codigo=nuevoCodigo;
    cout<<endl<<"Filtrando desaprobados..."<<endl<<endl;
}