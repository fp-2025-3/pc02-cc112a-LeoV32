#include <iostream>
using namespace std;

void imprimir(int (*matriz)[5],int F,int C);
void encontrarPicos(int (*matriz)[5],int F,int C);

int main(){
    int matriz[][5]={
        {3,3,3,3,3},
        {3,4,4,2,3},
        {3,4,5,4,3},
        {3,3,3,3,3}
    };
    int fila=4;
    int col=5;
    int (*max)[5]=matriz;
    imprimir(max,fila,col);
    cout<<"Elemento pico: "<<endl;
    encontrarPicos(max,fila,col);
}

void imprimir(int (*matriz)[5],int F,int C){
    for(int (*A)[5]=matriz;A<matriz+F;A++){
        for(int* e=*A;e<*A+C;e++){
            cout<<*e<<"  ";
        }
        cout<<endl;
    }
}

void encontrarPicos(int (*matriz)[5],int F,int C){
    for(int (*A)[5]=matriz;A<matriz+F;A++){
        for(int* e=*A;e<*A+C;e++){
            int i=A-matriz;
            int j=e-*A;

            bool pico=true;
            int cont=0;

            if(i>0){
                if(*(*(matriz+i)+j)<*(*(matriz+i-1)+j)){
                    pico=false;
                } else if(*(*(matriz+i)+j)>*(*(matriz+i-1)+j)) cont++;
            }

            if(j>0){
                if(*(*(matriz+i)+j)<*(*(matriz+i)+j-1)){
                    pico=false;
                } else if(*(*(matriz+i)+j)>*(*(matriz+i)+j-1)) cont++;
            }

            if(i<F-1){
                if(*(*(matriz+i)+j)<*(*(matriz+i+1)+j)){
                    pico=false;
                } else if(*(*(matriz+i)+j)>*(*(matriz+i+1)+j)) cont++;
            }

            if(j<C-1){
                if(*(*(matriz+i)+j)<*(*(matriz+i)+j+1)){
                    pico=false;
                } else if(*(*(matriz+i)+j)>*(*(matriz+i)+j+1)) cont++;
            }

            if(pico==true && cont>0){
                cout<<"Pico en ("<<i<<","<<j<<"): "<<*(*(matriz+i)+j)<<endl;
            }
        }
    }
}