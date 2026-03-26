#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui 
    for(int* pd=inicio;pd<fin;pd++){
        if(equivale(*pd,clave)) return pd;
    }
    return NULL;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida

bool igual(int a,int b){
    if(a==b) return true;
    else return false;
}

bool mismaParidad(int a,int b){
    if(a%2==0 && b%2==0) return true;
    return false;
}
bool divideA(int a,int b){
    if(b%a==0){
        return true;
    }
    return false;
}

bool mismaCantidadDigitos(int a,int b){
    int cantA=0;
    int cantB=0;
    while(a/10>0){
        a/=10;
        cantA++;
    }
    while(b/10>0){
        b/=10;
        cantB++;
    }
    if(cantA==cantB) return true;
    return false;

}

bool mismoResiduoMod5(int a,int b){
    if(a%5==b%5) return true;
    return false;
}

void imprimir(int* inicio,int* fin,bool (*equivale)(int, int),int clave){
    
    int* p = buscar(inicio,fin,equivale,clave);
    if(p==NULL) cout<<"No se encontro"<<endl;
    else cout<<"encontrado valor: "<<*p<<" Pos: "<<p<<endl;

}




int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    for(int* pd=inicio;pd<fin;pd++){
        cout<<*pd<<"  ";
    }
    cout<<endl<<endl<<"Clave: "<<clave<<endl<<endl;

    // Llame a la funcion buscar para cada criterio 
    cout<<"Igualdad exacta: ";
    imprimir(inicio,fin,igual,clave);
    cout<<"Misma paridad: ";
    imprimir(inicio,fin,mismaParidad,clave);
    cout<<"Divide a: ";
    imprimir(inicio,fin,divideA,clave);
    cout<<"Misma cantidad de digitos: ";
    imprimir(inicio,fin,mismaCantidadDigitos,clave);
    cout<<"Mismo residuo modulo 5: ";
    imprimir(inicio,fin,mismoResiduoMod5,clave);
 

    return 0;
}
