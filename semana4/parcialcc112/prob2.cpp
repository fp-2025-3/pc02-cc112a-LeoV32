#include <iostream>
#include <cstring>
using namespace std;

void leer(char* corredores[],int* tiempo);

int main(){
    char** corredor=NULL;
    int* tiempo=NULL;

    leer(corredor,tiempo);

    return 0;
}

void leer(char* corredores[],int* tiempo){
    int n;
    cout<<"Ingrese el numero de corredores: ";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<"Nombre del corredor "<<i+1<<": ";
        cin.getline(corredores[i],' ',20);
        cout<<"Tiempo (en segundos): ";
        cin>>tiempo[i];
    }
}