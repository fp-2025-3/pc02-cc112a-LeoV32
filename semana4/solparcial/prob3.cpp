#include <iostream>
using namespace std;

const int N=4;

bool esFilaDominanteEstricta(int (*M)[N],int f);
bool esFilaFuertementeDominante(int (*M)[N],int f);

int main(){
    
    int M[N][N]={
        {2,3,1,4},
        {1,2,3,2},
        {5,6,7,8},
        {0,1,2,1}};

    cout<<"Fila    Dominante Estricta      Fuertemente Dominante"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0;i<N;i++){
    cout<<i<<"       ";
    if(esFilaDominanteEstricta(M,i)) cout<<"SI                       ";
    else cout<<"NO                       ";
    if(esFilaFuertementeDominante(M,i)) cout<<"SI"<<endl;
    else cout<<"NO"<<endl;
    }


    return 0;
}

bool esFilaDominanteEstricta(int (*M)[N],int f){
    int (*pf)[N]=M+f;
    bool dominante=true;
    bool estricMayor=false;

    for(int* colF=*pf;colF<*pf+N;colF++){
        int cont=0;

        for(int (*pd)[N]=M;pd<M+N;pd++){
            if(pf!=pd){
                int* colD= *pd + (colF-*pf);
                if(*colD>*colF){
                    dominante=false;
                    break;
            } else if(*colD<*colF) cont++;
            }
        }

        if(cont>=3) estricMayor=true;
        if(!dominante) break;
    }

    return dominante && estricMayor;
}

bool esFilaFuertementeDominante(int (*M)[N],int f){
    if(esFilaDominanteEstricta(M,f)){
        int (*pf)[N]=M+f;
        int maxsuma=0;

        for(int* p=*pf;p<*pf+N;p++) maxsuma+=*p;

        for(int (*pd)[4]=M;pd<M+N;pd++){
            int suma=0;

            for(int* col=*pd;col<*pd+N;col++){
                suma+=*col;
            }
            
            if(maxsuma<=suma && pf!=pd) return false;
        }

        return true;

    } else return false;
}
