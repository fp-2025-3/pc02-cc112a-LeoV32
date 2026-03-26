#include <iostream>
#include <fstream>
using namespace std;

struct Proyecto{
    int id;
    char titulo[40];
    double presupuesto;
    int duracionMeses;
};

void almacenarProyectos(const char* nombre);
void mostrarRegistro(const char* nombre);

int main(){
    char nombre[]="proyectos.dat";
    almacenarProyectos(nombre);
    mostrarRegistro(nombre);

    return 0;
}

void almacenarProyectos(const char* nombre){
    fstream archivo(nombre, ios::binary | ios::out | ios::in);

    if(!archivo){
        archivo.open(nombre, ios::binary);
        archivo.close();
        archivo.open(nombre, ios::binary | ios::out | ios::in);
    }
    int N;
    cout<<"Ingrese la cantidad de proyectos a almacenar: ";
    cin>>N;
    cout<<endl;
    
    Proyecto nuevos;
    Proyecto e;
    for(int i=0;i<N;i++){
        
        cout<<"Ingrese su id:";
        cin>>nuevos.id;
        cout<<"Ingrese el titulo: ";
        cin.ignore();
        cin.getline(nuevos.titulo,40);
        cout<<"Ingrese el presupuesto: ";
        cin>>nuevos.presupuesto;
        cout<<"Ingrese la duracion (en meses): ";
        cin>>nuevos.duracionMeses;
        int p=nuevos.presupuesto;
        archivo.seekg(sizeof(Proyecto)*p);
        archivo.read((char*)&e,sizeof(Proyecto));
        archivo.clear();
        if(e.presupuesto>=nuevos.presupuesto){
            archivo.seekp(sizeof(Proyecto)*(p+1));
            archivo.write((char*)&nuevos,sizeof(Proyecto));
        }else{
            archivo.seekp(sizeof(Proyecto)*(p-1));
            archivo.write((char*)&nuevos,sizeof(Proyecto));
        }

        archivo.close();
    }
}

void mostrarRegistro(const char* nombre){
    ifstream archivo(nombre, ios::binary | ios::in);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    Proyecto e;
    cout<<"Mostrando registro: "<<endl<<endl;
    while(archivo.read((char*)&e,sizeof(Proyecto))){
        if(e.presupuesto!=0){
            cout<<"Cuenta:"<<endl;
            cout<<"ID: "<<e.id<<endl;
            cout<<"Titulo: "<<e.titulo<<endl;
            cout<<"Presupuesto: "<<e.presupuesto<<endl;
            cout<<"Duracion (meses): "<<e.duracionMeses<<endl;
            cout<<endl;
        }
        
    }

    archivo.close();
}