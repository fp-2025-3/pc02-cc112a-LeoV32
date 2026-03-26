#include <iostream>
using namespace std;

int cantidad(const char* cad[],int n);
int longitud(const char* a);

int main(){
    const char* cad[]={"Lesly",
        "Americo",
        "Xingbeck",
        "William",
        "Julio",
        "Darwin",
        "Kevin" };//5 7 8 7 5 6 5
    int n=7;

    cout<<"Cantidad de cadenas con longitud mayor al promedio: "<<cantidad(cad,n)<<endl;

    return 0;

}

int longitud(const char* a){
    const char* b=a;
    while(*b!='\0'){
        b++;
    }
    return b-a;
}

int cantidad(const char* cad[],int n){
    int cant=0;
    double longitudPromedio=0;
    for(const char** pd=cad;pd<cad+n;pd++){
        longitudPromedio+=longitud(*pd);
    }
    longitudPromedio=longitudPromedio/n;
    for(const char** pd=cad;pd<cad+n;pd++){
        if(longitudPromedio<longitud(*pd)) cant++;
    }
    return cant;
}