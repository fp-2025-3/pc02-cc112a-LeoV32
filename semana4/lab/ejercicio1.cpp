#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char* leer(){
    char texto[100];
    cout<<"Ingrese el texto: "<<endl;
    cin.getline(texto,100);
    int n=strlen(texto);

    char* t=new char[n+1];
    for(int i=0;i<n+1;i++){
        t[i]=texto[i];
    }
    return t;
}

char* normalizar(char* texto){
    char temp[100];
    int i=0;
    int j=0;
    
    while(texto[i]!='\0'){
        if(!isspace(texto[i])){
            temp[j]=tolower(texto[i]);
            j++;
            i++;
        }else{
            temp[j]=texto[i];
            j++;
            i++;
            while(texto[i]==' ') i++;
        }
    }
    char* nuevo=new char[j+1];
    for(int k=0;k<j+1;k++){
        nuevo[k]=temp[k];
    }
    return nuevo;
}

int contarPalabras(char* texto){
    int i=0;
    int cont=0;
    while(texto[i]!='\0'){
        if(i==0 && texto[i]!=' ') cont++;
        else if(texto[i]==' ' && texto[i+1]!=' ') cont++;
        i++;
    }
    return cont;
}

char** palabras(char* texto,int n){
    int i=0;
    int z=0;
    char** P=new char*[n];

    while(texto[i]!='\0'){
        if(texto[i]==' ') i++;
        int j=i;
        int len=0;
        while(texto[i]!=' ' && texto[i]!='\0'){
            i++;
            len++;
        }
        P[z]=new char[len+1];
        P[z][len]='\0';
        for(int k=0;k<len;k++){
            P[z][k]=texto[j+k];
        }
        z++;
    }
    return P;
}

void imprimir(char** M,int n){
    for(int i=0;i<n;i++){
        int j=0;
        while(M[i][j]!='\0'){
            cout<<M[i][j];
            j++;
        }
        cout<<"  "<<strlen(M[i])<<endl;
    }
    
}

void liberar(char** M,int n){
    for(int i=0;i<n;i++) delete[] M[i];
    delete[] M;
}

int main(){
    char* texto=leer();
    char* normalizada=normalizar(texto);
    int n=contarPalabras(normalizada);
    char** Palabra=palabras(normalizada,n);
    delete[] texto;
    delete[] normalizada;
    cout<<"Palabras: "<<endl;
    imprimir(Palabra,n);
    liberar(Palabra,n);
    

    return 0;
}