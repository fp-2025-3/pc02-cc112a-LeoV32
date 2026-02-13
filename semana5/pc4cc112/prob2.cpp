#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

struct seleccion{
    string nombre;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int puntajeTotal;
    int DG;
    float rendimiento;
};
const int n=5;

void llenandoDatos(seleccion e[n]);
void imprimir(seleccion e[n]);
void intercambiar(seleccion &e1, seleccion &e2);

int main(){
    srand(time(NULL));
    seleccion e[n];
    llenandoDatos(e);
    imprimir(e);

}

void llenandoDatos(seleccion e[n]){
    for(int k=0;k<n;k++){
        e[k].nombre="Pais_"+to_string(k);
        e[k].GF=0;
        e[k].GC=0;
        e[k].PG=0;
        e[k].PE=0;
        e[k].PP=0;

        for(int i=0;i<100;i++){
            int GF=rand()%6;
            int GC=rand()%6;
            e[k].GF+=GF;
            e[k].GC+=GC;
            if(GF>GC) e[k].PG++;
            if(GF==GC) e[k].PE++;
            if(GF<GC) e[k].PP++;
        }
        e[k].DG=e[k].GF-e[k].GC;
        e[k].puntajeTotal=3*e[k].PG+e[k].PE;
        float a=e[k].puntajeTotal;
        e[k].rendimiento=(a*100)/300;
    }
}

void imprimir(seleccion e[n]){
    cout<<"Seleccion   PG   PE   PP   GF   GC   DG   Pts   Rend(%)"<<endl;
    cout<<"--------------------------------------------------------"<<endl;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(e[i].puntajeTotal<e[j].puntajeTotal){
                intercambiar(e[i], e[j]);

            }else if(e[i].puntajeTotal==e[j].puntajeTotal){
                if(e[i].DG<e[j].DG){
                    intercambiar(e[i], e[j]);

                } else if(e[i].DG==e[j].DG){
                    if(e[i].GF<e[j].GF){
                        intercambiar(e[i], e[j]);
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<e[i].nombre<<"      "<<e[i].PG<<"   "<<e[i].PE<<"   "<<e[i].PP<<"  ";
        cout<<e[i].GF<<"  "<<e[i].GC<<"   "<<e[i].DG<<"   ";
        cout<<e[i].puntajeTotal<<"    "<<e[i].rendimiento<<endl;
    }

    cout<<"Campeon: "<<e[0].nombre<<" | Puntaje: "<<e[0].puntajeTotal;
    cout<<" | DG: "<<e[0].DG<<" | Rendimiento: "<<e[0].rendimiento<<endl;
}

void intercambiar(seleccion &e1, seleccion &e2){
    swap(e1.DG,e2.DG);
    swap(e1.GC,e2.GC);
    swap(e1.GF,e2.GF);
    swap(e1.PE,e2.PE);
    swap(e1.PG,e2.PG);
    swap(e1.PP,e2.PP);
    swap(e1.puntajeTotal,e2.puntajeTotal);
    float temp1=e1.rendimiento;
    e1.rendimiento=e2.rendimiento;
    e2.rendimiento=temp1;
    string temp2=e1.nombre;
    e1.nombre=e2.nombre;
    e2.nombre=temp2;
}