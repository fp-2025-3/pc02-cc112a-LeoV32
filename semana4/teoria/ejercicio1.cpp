#include <iostream>
using namespace std;

void leerEstudiante(int &n);
float* reservaMemoria(int n);
void leerNotas(float* notas,int inicio, int fin);
float promedioCurso(float* notas,int n);
float maximaNota(float* notas,int n);
float minimaNota(float* notas,int n);
void CalculaPromedioMaxMin(float* notas,int n);
void redimencionar(float* &notas,int &n,int k);
//memoria dinamica para leer notas de los estudiantes 
//y calcular el promedio del curso y la nota maxima y minima;
int main(){
    int n;
    int opcion=0;
    cout<<"Sistema de gestion de notas: "<<endl;
    int k=5;
    while(n<=0){
        leerEstudiante(n);
    }
    float* notas=reservaMemoria(n);
    leerNotas(notas,0,n-1);
    CalculaPromedioMaxMin(notas,n);

    do{
        cout<<"1: Agregar mas notas "<<endl;
        cout<<"2: Salir"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        if(opcion==1){
            redimencionar(notas,n,k);
            leerNotas(notas,n-k,n-1);
            CalculaPromedioMaxMin(notas,n);
        }
    }while(opcion!=2);
    
    delete[] notas;
    return 0;
}

void leerEstudiante(int &n){
    cout<<"Ingrese el numero de estudiantes: "<<endl;
    cin>>n;
}

float* reservaMemoria(int n){
    return new float[n];
}

void leerNotas(float* notas,int inicio,int fin){
    for(int i=inicio;i<fin+1;i++){
        cout<<"Estudiante "<<i+1<<": "<<endl;
        cout<<"Ingrese la nota: ";
        cin>>notas[i];
        cout<<endl;
    }
}

float promedioCurso(float* notas,int n){
    float suma=0;
    for(int i=0;i<n;i++){
        suma+=notas[i];
    }
    return suma/n;
}

float maximaNota(float* notas,int n){
    float max=notas[0];
    for(int i=0;i<n;i++){
        if(notas[i]>max) max=notas[i];
    }
    return max;
}

float minimaNota(float* notas,int n){
    float min=notas[0];
    for(int i=0;i<n;i++){
        if(notas[i]<min) min=notas[i];
    }
    return min;
}

void CalculaPromedioMaxMin(float* notas,int n){
    cout<<"El promedio del curso es: "<<promedioCurso(notas,n)<<endl;
    cout<<"El maximo es: "<<maximaNota(notas,n)<<endl;
    cout<<"El minimo es: "<<minimaNota(notas,n)<<endl;
}

void redimencionar(float* &notas,int &n,int k){
    float* nuevo=new float[n+k];
    for(int i=0;i<n;i++){
        nuevo[i]=notas[i];
    }
    delete[] notas;
    notas=nuevo;
    n+=k;
}