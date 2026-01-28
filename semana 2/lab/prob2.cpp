#include <iostream>
using namespace std;

void imprimirMatriz(int (*inicio)[4], int (*fin)[4]);
int* obtenerFila(int (*inicio)[4], int (*fin)[4], int fila);
int* obtenerElementoColumna(int (*inicio)[4], int (*fin)[4], int col, int fila);

int main(){
    int M[3][4] = {
    {  2, -1,  4,  6 },
    { -3,  5, -2,  1 },
    {  7, -4,  0,  8 }};

    int (*inicio)[4]=M;
    int (*fin)[4]=M+3;
    imprimirMatriz(inicio,fin);
    
    int n;
    cout<<"Ingrese la fila a ingresar:";
    cin>>n;
    int *p=obtenerFila(inicio,fin,n);
    if(n>0 && n<=3){
        cout<<"Primer elemento de la fila "<<n<<" es "<<*p<<endl;
    } else cout<<"No se encontro el la fila con direccion "<<p<<endl;

    int* q=obtenerElementoColumna(inicio,fin,1,2);
    if(n>0 && n<=3){
        cout<<"El elemento es "<<n<<" es "<<*q<<endl;
    } else cout<<"No se encontro el elemento con direccion "<<q<<endl;

}

void imprimirMatriz(int (*inicio)[4], int (*fin)[4]){
    for(int (*pd)[4]=inicio;pd<fin;pd++){
        for(int *c=*pd;c<*pd+4;c++){
            cout<<*c<<" ";
        }
        cout<<endl;
    }
}

int* obtenerFila(int (*inicio)[4], int (*fin)[4], int fila){

    if(fila>0 && fila<=3){
        int (*p)[4]=inicio+fila-1;
        return *p;
    } else return NULL;
    
}

int* obtenerElementoColumna(int (*inicio)[4], int (*fin)[4], int col, int fila){
    if(fila>0 && fila<=3 && col>0 && col<=4){
        int* p=*(inicio+fila-1)+col-1;
        return p;
    } else return NULL; 
}