#include <iostream>
using namespace std;

bool esFilaDominanteEstricta(int (*M)[4],int f);
bool esFilaFuertementeDominante(int (*M)[4],int f);

int main(){
    const int N=4;
    int M[N][N]={
        {2,3,1,4},
        {1,2,3,2},
        {5,6,7,8},
        {0,1,2,1}};

    cout<<"Fila    Dominante Estricta      Fuertemente Dominante"<<endl;
    cout<<"-----------------------------------------------------"<<endl;
    for(int i=0;i<4;i++){
    cout<<i<<"       ";
    if(esFilaDominanteEstricta(M,i)) cout<<"SI                       ";
    else cout<<"NO                       ";
    if(esFilaFuertementeDominante(M,i)) cout<<"SI"<<endl;
    else cout<<"NO"<<endl;
    }


    return 0;
}

bool esFilaDominanteEstricta(int (*M)[4],int f){
    int (*pf)[4]=M+f;
    bool dominante=true;
    bool estricMayor=false;

    for(int i=0;i<4;i++){
        int cont=0;

        for(int (*pd)[4]=M;pd<M+4;pd++){
            if(*(*pd+i)>*(*pf+i)){
                dominante=false;
                break;
            } else if(*(*pd+i)<*(*pf+i) && pf!=pd) cont++;
        }

        if(cont>=3) estricMayor=true;
        if(!dominante) break;
    }

    if(dominante && estricMayor) return true;
    return false;
}

bool esFilaFuertementeDominante(int (*M)[4],int f){
    if(esFilaDominanteEstricta(M,f)){
        int (*pf)[4]=M+f;
        int maxsuma=0;

        for(int* i=*pf;i<*pf+4;i++) maxsuma+=*i;

        for(int (*pd)[4]=M;pd<M+4;pd++){
            int suma=0;

            for(int* col=*pd;col<*pd+4;col++){
                suma+=*col;
            }
            
            if(maxsuma<=suma && pf!=pd) return false;
        }

        return true;

    } else return false;
}
