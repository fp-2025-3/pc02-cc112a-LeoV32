#include <iostream>
using namespace std;

void intercambiar(int &a, int &b){
    int temp=a;
    a=b;
    b=temp;
}

void BurbujaRecursivo(int* arr,int n,bool ascendente){
    if(n<=1) return;
    for(int j=1;j<n;j++){
        if(ascendente==true){
            if(arr[j]>arr[0]) intercambiar(arr[0],arr[j]);
        }else{
            if(arr[j]<arr[0]) intercambiar(arr[0],arr[j]);
        }
    }
    BurbujaRecursivo(arr+1,n-1,ascendente);
}


void CreateVector(int* &vec,int size){
    vec=new int[size];
}

void ReadArray(int* vec,int size){
    for(int i=0;i<size;i++){
        cout<<"Ingresa el elemento "<<i<<" de la matriz:";
        cin>>vec[i];
    }
}

void PrintArray(int* vec,int size){
    for(int i=0;i<size;i++){
        cout<<vec[i]<<" ";
        
    }
    cout<<endl;
}

void DestroyVector(int* vec){
    delete[] vec;
}

void Intercambiar(int* vec1,int* vec2){
    int* temp=vec1;
    vec1=vec2;
    vec2=temp;
}

int main(){
    int *vec1=NULL,size=10;
    int* vec2=NULL;

    CreateVector(vec1, size); // Crear la memoria para este puntero
    ReadArray(vec1, size); // Lee los datos desde el cin
    BurbujaRecursivo(vec1, size,false); // Funcion definida arriba
    PrintArray(vec1, size); // Imprime los datos en el cout

    CreateVector(vec2, size); // Crear la memoria para este puntero
    ReadArray(vec2, size); // Lee los datos desde el cin
    BurbujaRecursivo(vec2, size,true); // Funcion definida arriba
    PrintArray(vec2, size);

    Intercambiar(vec1, vec2); // Parte 2 del ejercicio
    PrintArray(vec1, size);
    PrintArray(vec2, size);
    DestroyVector(vec1); // Destruye el vector y deja en nullptr vec1
    DestroyVector(vec2); // Destruye el vector y deja en nullptr vec2

    return 0;
}

