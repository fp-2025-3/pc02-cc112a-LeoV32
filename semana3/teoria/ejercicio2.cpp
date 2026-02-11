#include <iostream>
#include <cstring>
using namespace std;

void ordenar(char (*nombres)[20],int n);
void imprimir(char (*nombres)[20],int n);

int main(){
        char nombres[][20]={"Lesly",
        "Americo",
        "Xingbeck",
        "William",
        "Julio",
        "Darwin",
        "Kevin" };
    int n=7;
    imprimir(nombres,n);
    cout<<endl;
    ordenar(nombres,n);
    imprimir(nombres,n);


}

void ordenar(char (*nombres)[20],int n){
    char temp[30];
    for(char (*i)[20]=nombres;i<nombres+n-1;i++){
        for(char (*j)[20]=i+1;j<nombres+n;j++){
            if(strcmp(*i,*j)>0){
                strcpy(temp,*i);
                strcpy(*i,*j);
                strcpy(*j,temp);
            }
        }
    }
}

void imprimir(char (*nombres)[20],int n){
    for(int i=0;i<n;i++){
        cout<<*(nombres+i)<<endl;
    }
}