#include <iostream>
using namespace std;

void imprimirMatriz(int (*inicio)[4], int (*fin)[4]);
int* obtenerFila(int (*inicio)[4], int (*fin)[4], int fila);
int* obtenerElementoColumna(int (*inicio)[4], int (*fin)[4], int col, int fila);
int sumaFila(int* filaInicio, int columnas);

int main(){

    int M[3][4] = {
    {  2, -1,  4,  6 },
    { -3,  5, -2,  1 },
    {  7, -4,  0,  8 }};

    int (*inicio)[4]=M;
    int (*fin)[4]=M+3;
    int n;
    int col=4;
    imprimirMatriz(inicio,fin);
    cout<<"Ingrese la fila: ";
    cin>>n;
    cout<<"La direccion de el primer elemento de la fila es: ";
    int* p=obtenerFila(inicio,fin,n);
    cout<<p<<endl;
    cout<<"La suma de la fila "<<n<<": "<<sumaFila(obtenerFila(inicio, fin, n), col)<<endl;

}

void imprimirMatriz(int (*inicio)[4], int (*fin)[4]){
    for(int (*pd)[4]=inicio;pd<fin;pd++){
        for(int* col=*pd;col<*pd+4;col++){
            cout<<*col<<"  ";
        }
        cout<<endl;
    }
}

int* obtenerFila(int (*inicio)[4], int (*fin)[4], int fila){
    if(fila>0 && fila<=3){
        int* p=*(inicio+fila-1);
        return p;
    } return NULL;
}

int* obtenerElementoColumna(int (*inicio)[4], int (*fin)[4], int col, int fila){
    if(fila>0 && fila<=3 && col>0 && col<=4){
        int* p=*(inicio+fila-1)+col-1;
        return p;
    } return NULL;
}

int sumaFila(int* filaInicio, int columnas){
    int suma=0;
    for(int*pd=filaInicio;pd<filaInicio+columnas;pd++){
        suma+=*pd;
    }
    return suma;
}