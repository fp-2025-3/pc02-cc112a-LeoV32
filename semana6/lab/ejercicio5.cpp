#include <iostream>
#include <fstream>
using namespace std;

struct Terminos{
    int numero;
};

void escribirFibonacciBinario(const char* nombre);
void leerFibonacciBinario(const char* nombre);

int main(){
    char archivo[]="Fibonacci.bin";
    escribirFibonacciBinario(archivo);
    leerFibonacciBinario(archivo);
    return 0;
}

void escribirFibonacciBinario(const char* nombre){
    ofstream archivo(nombre, ios::out | ios::app | ios::binary );
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    Terminos e;
    
    int ter1=0;
    int ter2=1;
    for(int i=0;i<20;i++){
        if(i%2==0){
            e.numero=ter1;
            ter1+=ter2;
        } 
        else{
            e.numero=ter2;
            ter2+=ter1;
        }
        archivo.write((char*)&e,sizeof(Terminos));
    }
    archivo.close();
}

void leerFibonacciBinario(const char* nombre){
    ifstream archivo(nombre, ios::in | ios::binary);
    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }
    
    Terminos e;
    int cont=0;
    while(archivo.read((char*)&e,sizeof(Terminos))){
        cout<<"Termino "<<cont+1<<": "<<e.numero<<endl;
        cont++;
    }
    archivo.close();
}