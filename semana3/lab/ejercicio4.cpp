#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void generarMatriz(int (*matriz)[9]);
void imprimir(int (*matriz)[9]);
void invertir(int* arreglo,int inicio,int fin);
void rotar(int* arreglo,int k);
void cambio(int (*matriz)[9],int f, int c);

int main(){
    int matriz[9][9]={
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };
    srand(time(NULL));
    generarMatriz(matriz);
    cout<<"Arreglo original: "<<endl;
    imprimir(matriz);
    cambio(matriz,2,3);
    cout<<"Arreglo cambiado:"<<endl;
    imprimir(matriz);
}

void generarMatriz(int (*matriz)[9]){
    
    for(int (*i)[9]=matriz;i<matriz+9;i++){
        bool usado[9]={true,true,true,true,true,true,true,true,true};
        for(int* j=*i;j<*i+9;j++){
            int x;
            do{
                x=rand()%9+1;
            }while(usado[x-1]==false);
            *j=x;
            usado[*j-1]=false;
        }
    }
}

void imprimir(int (*matriz)[9]){
    for(int (*i)[9]=matriz;i<matriz+9;i++){
        for(int* j=*i;j<*i+9;j++){
            cout<<*j<<"  ";
        }
        cout<<endl;
    }
}

void invertir(int* arreglo,int inicio,int fin){
    while(inicio<fin){
        int temp=arreglo[inicio];
        arreglo[inicio]=arreglo[fin];
        arreglo[fin]=temp;
        inicio++;
        fin--;
        
    }
}

void rotar(int* arreglo,int k){
    if(k < 0) k += 9;
k = k % 9;
    invertir(arreglo,0,8);
    invertir(arreglo,0,k-1);
    invertir(arreglo,k,8);
}
void cambio(int (*matriz)[9],int f, int c){
    int valor=*(*(matriz+f-1)+c-1);
    for(int (*i)[9]=matriz;i<matriz+9;i++){

        int k=0;
        for(int* j=*i;j<*i+9;j++){
            if(*j==valor){
                k = (c-1) - (j - *i);
               break;
            }
        }
               if(k!=0) rotar(*i,k);
    }
}