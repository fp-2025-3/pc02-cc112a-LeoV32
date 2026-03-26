#include <iostream>
using namespace std;

void construirEstructura(int* filas[],size_t tamanios[],int* f0, size_t t0,int* f1, size_t t1,int* f2, size_t t2);
int* obtenerFila(int* filas[], size_t tamanios[], size_t n, size_t i);
int sumaAlternada(int* fila, size_t tam);
int* filaMayorSuma(int* filas[],size_t tamanios[],size_t n);
int sumaTotal(int* filas[], size_t tamanios[], size_t n);

int main() {
    int f0[] = {1, 2, 3};
    int f1[] = {4, 5, 6, 7, 8};
    int f2[] = {9, 10};

    int* filas[3];
    size_t tamanios[3];

    construirEstructura(
        filas, tamanios,
        f0, 3,
        f1, 5,
        f2, 2
    );

    for(size_t i = 0; i < 3; i++){
        cout << "Suma alternada fila " << i << ": "
             << sumaAlternada(filas[i], tamanios[i]) << endl;
    }

    int* mejor = filaMayorSuma(filas, tamanios, 3);
    cout << "Fila con mayor suma alternada inicia en direccion: "
         << mejor << endl;

    cout << "Suma total: "
         << sumaTotal(filas, tamanios, 3) << endl;

    return 0;
}

void construirEstructura(int* filas[],size_t tamanios[],int* f0, size_t t0,int* f1, size_t t1,int* f2, size_t t2){
    *(filas+0)=f0;
    *(tamanios+0)=t0;
    *(filas+1)=f1;
    *(tamanios+1)=t1;
    *(filas+2)=f2;
    *(tamanios+2)=t2;
    
}

int* obtenerFila(int* filas[], size_t tamanios[], size_t n, size_t i){
    if(i<n){
        return *(filas + i);
    }
    return NULL;
}

int sumaAlternada(int* fila, size_t tam){
    int suma=0;
    int sig=1;
    for(int* pd=fila;pd<fila+tam;pd++){
        suma+=(*pd) * sig;
        sig=-sig;
        
    }
    return suma;
}

int* filaMayorSuma(int* filas[], size_t tamanios[], size_t n){
    int* mejorFila = *filas;
    int mejorSuma = sumaAlternada(*filas, *tamanios);

    for(size_t i = 1; i < n; i++){
        int suma = sumaAlternada(*(filas + i), *(tamanios + i));
        if(suma > mejorSuma){
            mejorSuma = suma;
            mejorFila = *(filas + i);
        }
    }
    return mejorFila;
}

int sumaTotal(int* filas[], size_t tamanios[], size_t n){
    int total = 0;

    for (size_t i = 0; i < n; i++) {
        int* fila = *(filas + i);
        size_t tam = *(tamanios + i);

        for (int* p = fila; p < fila + tam; p++) {
            total += *p;
        }
    }
    return total;
}

