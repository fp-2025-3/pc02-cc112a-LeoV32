#include <iostream>
#include <cstring>
using namespace std;

struct Estudiante{
    string nombre;
    int nota;
};

int main(){
    int n;
    cout<<"Ingrese el numero de estudiantes: ";
    cin>>n;

    Estudiante* e=new Estudiante[n];
    int indice=0;

    for(int i=0;i<n;i++){
        cout<<"Ingrese el nombre del estudiante "<<i+1<<": ";
        cin.ignore();
        getline(cin,e[i].nombre);
        cout<<"Ingrese la nota del estudiante "<<i+1<<": ";
        cin>>e[i].nota;
        if(e[i].nota>e[indice].nota) indice=i;
    }

    cout<<"El estudiante con la mayor nota es: ";
    cout<<e[indice].nombre<<endl;
    cout<<"Nota: "<<e[indice].nota<<endl;
}