#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void quicksort(double arr[],int inicio,int final);
int partition(double arr[],int inicio,int final);
void imprimir(double palumnos[]);

int main(){
    int notas[10][5];
    double palumnos[10];

    srand(time(NULL));
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){
            notas[i][j]=rand()%21;
        }
        double p=0;
        for(int j=0;j<5;j++){
            p=p+notas[i][j];
        }
        palumnos[i]=p/5;
    }
    imprimir(palumnos);
    quicksort(palumnos,0,9);
    cout<<endl;
    cout<<"Puesto 1: "<<palumnos[9]<<endl;
    cout<<"Puesto 2: "<<palumnos[8]<<endl;
    cout<<"Puesto 3: "<<palumnos[7]<<endl;
    cout<<endl;
}

void imprimir(double palumnos[]){
    cout<<"Promedios de los alumnos: "<<endl<<endl;
    for(int i=0;i<10;i++){
        cout<<"pAlumnos["<<i<<"]="<<palumnos[i]<<endl;
    }
    

}

void quicksort(double arr[],int inicio,int final){
    if(inicio<final){
        int pivote=partition(arr,inicio,final);
        quicksort(arr,inicio,pivote-1);
        quicksort(arr,pivote+1,final);
    }
}

int partition(double arr[],int inicio,int final){
    int pivot=arr[final];
    int k=inicio-1;

    for(int i=inicio;i<final;i++){
        if(arr[i]<=pivot){
            k++;
            swap(arr[i],arr[k]);
        }

    }
    swap(arr[k+1],arr[final]);
    return k+1;
}