#include <iostream>
using namespace std;

int suma(int (*matriz)[5],int i1,int j1,int i2,int j2);
void sumamaxima(int (*matriz)[5],int F,int C);

int main(){
    int matriz[][5]={
        {-2,1,-3,4,-1},
        {2,3,-2,1,-5},
        {-1,4,2,-3,2},
        {1,-2,3,4,-1}
    };
    int col=5;
    int fila=4;
    int (*inicio)[5]=matriz;
    cout<<"Matriz: "<<endl;
    for(int (*pd)[5]=matriz;pd<matriz+fila;pd++){
        for(int *c=*pd;c<*pd+col;c++){
            cout<<*c<<"  ";
        }
        cout<<endl;
    }
    sumamaxima(inicio,fila,col);

}

int suma(int (*matriz)[5],int i1,int j1,int i2,int j2){
    int sumatoria=0;
    for(int (*pd)[5]=matriz+i1;pd<=matriz+i2;pd++){
        for(int *col=*pd+j1;col<=*pd+j2;col++){
            sumatoria+=*col;
        }
    }
    return sumatoria;
}

void sumamaxima(int (*matriz)[5],int F,int C){
    
    int i1=0,j1=0;
    int i2=0,j2=0;
    int s=-99999;
    for(int (*pd)[5]=matriz;pd<matriz+F;pd++){
        for(int *col=*pd;col<*pd+C;col++){
            for(int (*p)[5]=matriz;p<matriz+F;p++){
                for(int *co=*p;co<*p+C;co++){
                    int ai1=pd-matriz;
                    int aj1=col-*pd;
                    int bi2=p-matriz;
                    int bj2=co-*p;
                    if(ai1<=bi2 && aj1<=bj2){
                        int e=suma(matriz,ai1,aj1,bi2,bj2);
                        if(s<e){
                        s=e;
                        i1=ai1;
                        j1=aj1;
                        i2=bi2;
                        j2=bj2;
                        }
                    }
                }
            
            }
        }
    }
    cout<<"Submatriz de suma maxima: "<<endl;
    cout<<"Esquina superior izquierda: ("<<i1<<","<<j1<<")"<<endl;
    cout<<"Esquina inferior derecha: ("<<i2<<","<<j2<<")"<<endl;
    cout<<"Suma maxima: "<<s<<endl;
    
}