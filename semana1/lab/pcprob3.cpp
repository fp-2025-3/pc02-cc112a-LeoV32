#include <iostream>
#include <cstring>
using namespace std;

int main(){
    int n;
    string nombre[30];
    int notas[30];

    cout<<"Cuantos alumnos ingresara: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Ingrese el nombre "<<i<<": ";
        cin>>nombre[i];
        cout<<"Ingresa la nota "<<i<<": ";
        cin>>notas[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(nombre[j][0]>nombre[j+1][0]){
                swap(nombre[j][0],nombre[j+1][0]);
                swap(notas[j],notas[j+1]);
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(notas[j]>notas[j+1] && nombre[j][0]==nombre[j+1][0]){
                swap(nombre[j][0],nombre[j+1][0]);
                swap(notas[j],notas[j+1]);
            }
        }
    }
    cout<<endl<<"Lista ordenada: "<<endl;
    for(int i=0;i<n;i++){
        cout<<nombre[i]<<"  "<<notas[i]<<endl;
    }
}

