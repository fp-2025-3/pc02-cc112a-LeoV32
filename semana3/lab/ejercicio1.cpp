#include <iostream>
#include <cstring>
using namespace std;

int separar_palabras(char* texto, char* palabras[]);
int longitud_palabra(const char* p);
void clasificar(char* palabras[], int n,
                char* cortas[], int& nc,
                char* largas[], int& nl);
int comparar_palabras(const char* a, const char* b);
void ordenar(char* v[], int n);
void imprimir_grupo(const char* titulo, char* v[], int n);

int main(){
    char texto[300]={"Programar en C++ requiere logica C++ exige disciplina"};
    char* palabras[60];
    char* cortas[60];
    char* largas[60];
    int nc,nl;
    cout<<longitud_palabra(texto)<<endl;
    int n=separar_palabras(texto,palabras);
    clasificar(palabras,n,cortas,nc,largas,nl);
    cout<<"Palabras cortas: "<<endl;
    ordenar(cortas,nc);
    imprimir_grupo(texto,cortas,nc);
    cout<<endl;
    cout<<"Palabras largas: "<<endl;
    ordenar(largas,nl);
    imprimir_grupo(texto,largas,nl);
    cout<<endl;
    return 0;
}

int separar_palabras(char* texto, char* palabras[]){
    int contador=0;
    
    while(*texto!='\0'){
        if(*texto!=' '){
            palabras[contador]=texto;
            contador++;
                while(*(texto+1)!=' ' && *(texto+1)!='\0') texto++;
            
            texto++;
        }else if(*texto==' '){
            *texto='\0';
            texto++;
        } else texto++;
    }
    return contador;
}

int longitud_palabra(const char* p){
    int cont=0;
    while(*p!=' ' && *p!='\0'){
        cont++;
        p++;
    }
    return cont;
}

void clasificar(char* palabras[], int n,char* cortas[], int& nc,char* largas[], int& nl){
    int ic=0,il=0;
    for(int i=0;i<n;i++){
        if(longitud_palabra(palabras[i])>3){
            largas[il]=palabras[i];
            il++;
        } else{
            cortas[ic]=palabras[i];
            ic++;
        }
        
    }
    
    nc=ic;
    nl=il;

}

int comparar_palabras(const char* a, const char* b){
    while(*a==*b && *a!='\0' && *b!='\0'){
        a++;
        b++;
    }
    return *a-*b;
}

void ordenar(char* v[], int n){
    char* temp=NULL;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(comparar_palabras(v[i],v[j])>0){
                temp=v[i];
                v[i]=v[j];
                v[j]=temp;
            }
        }
    }
    
}

void imprimir_grupo(const char* titulo, char* v[], int n){
    for(int i=0;i<n;i++){
            cout<<v[i]<<endl;
    }
}