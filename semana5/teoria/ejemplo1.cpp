
#include <iostream>
using namespace std;

struct Estudiante{
    int codigo;
    double promedio;
    char sexo;
};

struct Fecha{
    int dia;
    int mes;
    int anio;
};

struct alumno{
    int codigo;
    Fecha nacimiento;
};

void mostrar(Estudiante e1);
void aumentarPromedio(Estudiante &e1);
double calcularPromedio(Estudiante e1[],int n);

int main(){
    //1. Inicializando todo
    Estudiante e1 = {25694,18.2,'M'};

    //2. Inicializando miembro a miembro
    Estudiante e2;
    e2.codigo=3324;
    e2.promedio=12.5;
    e2.sexo='F';

    //3. Inicializando estructura a estructura
    Estudiante e3=e2;

    //4. Lectura y escritura de estructuras
    Estudiante e4;
    cout<<"Ingrese el codigo: ";
    cin>>e4.codigo;
    cout<<"Ingrese el promedio: ";
    cin>>e4.promedio;
    cout<<"Ingrese el sexo: ";
    cin>>e4.sexo;

    cout<<endl;

    cout<<"Codigo: "<<e4.codigo<<endl;
    cout<<"Promedio: "<<e4.promedio<<endl;
    cout<<"Sexo: "<<e4.sexo<<endl;

    cout<<endl;

    //5. Arreglo de estructuras
    Estudiante A[3];
    for(int i=0;i<3;i++){
        cout<<"Ingrese el codigo "<<i+1<<": ";
    cin>>A[i].codigo;
    cout<<"Ingrese el promedio "<<i+1<<": ";
    cin>>A[i].promedio;
    cout<<"Ingrese el sexo "<<i+1<<": ";
    cin>>A[i].sexo;
    cout<<endl;
    }

    

    for(int i=0;i<3;i++){
        cout<<"Estudiante "<<i+1<<endl;
        cout<<"Codigo: "<<A[i].codigo<<endl;
        cout<<"Promedio: "<<A[i].promedio<<endl;
        cout<<"Sexo: "<<A[i].sexo<<endl;
        cout<<endl;
    }

    //6. Estructuras anidadas
    alumno a1;
    a1.codigo=1234;
    a1.nacimiento.dia=12;
    a1.nacimiento.mes=10;
    a1.nacimiento.anio=2025;

    //7. Punteros a estructuras
    Estudiante e5={123,14.5,'F'};
    Estudiante* ptr;
    ptr=&e5;
        //Primera forma
    cout<<ptr->codigo<<endl;
    cout<<ptr->promedio<<endl;
    cout<<ptr->sexo<<endl;
        //Segunda forma
    cout<<(*ptr).codigo<<endl;
    cout<<(*ptr).promedio<<endl;
    cout<<(*ptr).sexo<<endl;

}
    //8. Paso de estructuras como parametros de funciones
        //Paso por valor (copiamos contenido)
void mostrar(Estudiante e1){
    cout<<e1.codigo;
}
        //Paso por referencia (uitl para programas eficientes y modificar)
void aumentarPromedio(Estudiante &e1){
    e1.promedio+=1;
}

double calcularPromedio(Estudiante e1[],int n){
    double suma=0;
    for(int i=0;i<n;i++){
        suma+=e1[i].promedio;
    }
    return suma/n;
}