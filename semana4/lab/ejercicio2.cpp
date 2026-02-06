#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void llenar(int (*M)[5],const int N){
    for(int (*pd)[5]=M;pd<M+N;pd++){
        for(int* col=*pd;col<*pd+N;col++){
            *col=rand()%10;
        }
    }
}

void imprimir(int (*M)[5],const int N){
    for(int (*pd)[5]=M;pd<M+N;pd++){
        for(int* col=*pd;col<*pd+N;col++){
            cout<<*col<<"  ";
        }
        cout<<endl;
    }
}

bool esFilaDominante(int (*M)[5], int fila){
    bool dominante=true;
    for(int i=0;i<5;i++){
        for(int (*pd)[5]=M;pd<M+5;pd++){
            if(*(*(M+fila)+i)<=*(*pd+i) && (M+fila)!=pd){
                dominante=false;
                break;
            }   
        }
        if(!dominante) break;
    }
    return dominante;
}
int contarColumnasCriticas(int (*M)[5]){
    int max=-1e9;
    for(int (*pd)[5]=M;pd<M+5;pd++){
        int suma=0;
        for(int* col=*pd;col<*pd+5;col++){
            suma+=*col;
        }
        if(max<suma) max=suma;
    }
    int cont=0;
    for(int i=0;i<5;i++){
        int suma=0;
        for(int (*pd)[5]=M;pd<M+5;pd++){
            suma+=*(*pd+i);
        }
        if(max<suma) cont++;
    }
    return cont;
}

bool esMatrizEscalonada(int (*M)[5]){
    int anterior=-1;
    for(int (*pd)[5]=M;pd<M+5;pd++){
        int actual=-1;
        int cont=0;

        for(int* col=*pd;col<*pd+5;col++,cont++){
            if(*col!=0){
                actual=cont;
                break;
            }
        }
        if(actual<=anterior) return false;
        anterior=actual;
    }
    return true;
}

int nucleo(int (*M)[5]){
    for(int (*pd)[5]=M;pd<M+5;pd++){
        for(int* col=*pd;col<*pd+5;col++){
            int valor=*col;
            bool maxfila=true;
            bool mincol=true;
            for(int* p=*pd;p<*pd+5;p++){
                if(*p>valor){
                    maxfila=false;
                    break;
                }
            }
            int C=col-*pd;
            for(int (*pd2)[5]=M;pd2<M+5;pd2++){
                if(*(*pd2+C)<valor){
                    mincol=false;
                    break;
                }
            }
            if(maxfila && mincol) return valor;
        }
        
    }
    return -1;
}

int main(){
    srand(time(NULL));
    const int N = 5;
    int M[N][N];
    llenar(M,N);
    imprimir(M,N);
    if(esFilaDominante(M,2)){
        cout<<"La fila 2 es dominante"<<endl;
    }else cout<<"La fila 2 no es dominante"<<endl;
    cout<<"Hay "<<contarColumnasCriticas(M)<<" columnas criticas"<<endl;
    if(esMatrizEscalonada(M)) cout<<"La matriz es escalonada"<<endl;
    else cout<<"La matriz no es escalonada"<<endl;
    cout<<"El numero nucleo es: "<<nucleo(M)<<endl;
    return 0;
}