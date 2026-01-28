#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void prom(double promedio[],char estados[],int N);
void lista(int notas[][5],double promedio[],char estados[],int N);
void quicksort(double promedio[],int N,int inicio,int final);
int partition(double promedio[],int N,int inicio,int final);

int main(){
    int N=5;
    do{
        cout<<"Ingrese la cantidad de alumnos (5-30): ";
        cin>>N;
    }while(N<5 || N>30);
    
    srand(time(NULL));
    int notas[30][5];
    double promedios[30];
    char estados[30];

    for(int i=0;i<N;i++){
        estados[i]='D';
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            notas[i][j]=rand()%21;
        }
    }
    for(int i=0;i<N;i++){
        double p=0;
        for(int j=0;j<5;j++){
            p=p+notas[i][j];
        }
        promedios[i]=p/5;
        if(promedios[i]>=10){
            estados[i]='A';
        }
    }
    prom(promedios,estados,N);
    cout<<endl<<endl<<"---LISTA ORIGINAL---"<<endl;
    lista(notas,promedios,estados,N);

    quicksort(promedios,N,0,N-1);
    lista(notas,promedios,estados,N);

    return 0;

}

void prom(double promedio[],char estados[],int N){
    double promGeneral=0;
    double promAprobados=0;
    int cantidad=0;
    int min=20;
    int max=0;
    for(int i=0;i<N;i++){
        promGeneral=promGeneral+promedio[i];
        if(estados[i]=='A'){
            cantidad++;
            promAprobados=promAprobados+promedio[i];
        } 
        if(promedio[i]<min) min=promedio[i];
        if(promedio[i]>max) max=promedio[i];

    }
    promAprobados=promAprobados/cantidad;
    promGeneral=promGeneral/N;
    cout<<"Promedio general de la clase: "<<promGeneral<<endl;
    cout<<"Cantidad de aprobados: "<<cantidad<<endl;
    cout<<"Nota maxima: "<<max<<endl;
    cout<<"Nota minima: "<<min<<endl;

} 
void lista(int notas[][5],double promedio[],char estados[],int N){
    cout<<"Alumno   Promedio   Estado   Notas"<<endl;
    for(int i=0;i<N;i++){
        cout<<"A"<<i+1<<"        "<<promedio[i]<<"          "<<estados[i]<<"       "<<notas[i][0]<<", "<<notas[i][1]<<", "<<notas[i][2]<<", "<<notas[i][3]<<", "<<notas[i][4]<<endl;
    }
}

void quicksort(double promedio[],int N,int inicio,int final){
    if(inicio<=final){
        int pivote=partition(promedio,N,inicio,final);
        quicksort(promedio,N,inicio,pivote-1);
        quicksort(promedio,N,pivote+1,final);
    }
}
int partition(double promedio[],int N,int inicio,int final){
    int pivot=promedio[final];
    int k=inicio;

    for(int i=0;i<N;i++){
        if(promedio[i]>pivot){
            swap(promedio[i],promedio[k]);
            k++;
        }
        swap(promedio[k+1],promedio[final]);
    }
    return k+1;
}