#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream archivo("laguna.txt", ios::in);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    int n,v;
    archivo>>n;
    archivo>>v;
    double* x=new double[v];
    double* y=new double[v];
    for(int i=0;i<v;i++){
        archivo>>x[i]>>y[i];
    }
    int a,b,c;

    ofstream Escritura("output/area.txt", ios::out | ios::app);
    if(!Escritura){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    
    for(int i=0;i<n;i++){
        double suma=0.0;
        archivo>>a>>b>>c;
        suma+=abs(x[a-1]*(y[c-1]-y[b-1]) + x[b-1]*(y[a-1]-y[c-1]) + x[c-1]*(y[b-1]-y[a-1]));
        suma/=2;
        Escritura<<suma<<endl;
    }
    delete[] x;
    delete[] y;
    archivo.close();
    Escritura.close();

    return 0;
}