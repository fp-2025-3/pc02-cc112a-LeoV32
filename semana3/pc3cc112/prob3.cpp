#include <iostream>
using namespace std;

void permutar(int (*matriz)[9]);
void imprimir(int (*matriz)[9]);
void invertir(int* arr,int inicio,int final);
void rotar(int* arr,int k);
void modificar(int (*matriz)[9], int fila,int columna);

int main(){
    int matriz[9][9];
    int fila,columna;
    permutar(matriz);
    cout<<"Matriz inicial:"<<endl;
    imprimir(matriz);
    cout<<"Fila inicial (1-9): ";
    cin>>fila;
    cout<<"Columna inicial (1-9): ";
    cin>>columna;
    cout<<endl<<"Valor seleccionado: "<<matriz[fila-1][columna-1]<<endl;
    modificar(matriz,fila,columna);
    cout<<"Matriz final: "<<endl;
    imprimir(matriz);
    return 0;
}

void permutar(int (*matriz)[9]){
    for(int (*i)[9]=matriz;i<matriz+9;i++){
        bool disponibles[9]={true,true,true,true,true,true,true,true,true};
        for(int* j=*i;j<*i+9;j++){
            int x=0;
            do{
                x=rand()%9+1;
            }while(disponibles[x-1]==false);
            disponibles[x-1]=false;
            *j=x;
        }
    }
}

void imprimir(int (*matriz)[9]){
    for(int (*i)[9]=matriz;i<matriz+9;i++){
        for(int* j=*i;j<*i+9;j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }
}

void invertir(int* arr,int inicio,int final){
    while(inicio<final){
        int temp=*(arr+inicio);
        *(arr+inicio)=*(arr+final);
        *(arr+final)=temp;
        inicio++;
        final--;
    }
}

void rotar(int* arr,int k){ 
    if(k<0) k=k+9;
    k=k%9;
    invertir(arr,0,8);
    invertir(arr,0,k-1);
    invertir(arr,k,8);
}

void modificar(int (*matriz)[9], int fila,int columna){
    int valor=matriz[fila-1][columna-1];
    for(int (*i)[9]=matriz;i<matriz+9;i++){
        int k=0;
        for(int* j=*i;j<*i+9;j++){
            
            if(*j==valor){
                k=j-*i;
                break;
            }
            
        }
        int diferencia=(columna-1)-k;
            rotar(*i,diferencia);
    }
}