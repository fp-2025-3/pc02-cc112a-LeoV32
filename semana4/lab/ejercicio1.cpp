#include <iostream>
#include <cstring>
using namespace std;

void normalizar(char* &texto,int &n){
    char* p=texto;
    char arr[n];
    int cont=0;
    while(*p!='\0'){
        arr[cont]=*p;
        cont++;
        if(*p==' ' && *(p+1)==' '){
            p++;
            while(*p==' ') p++;
        } else p++;
    }
    p=arr;
    while(*p!='\0'){
        if(!isspace(*p)){
            *p=tolower(*p);
        }
        p++;
    }
    n=cont;
    delete[] texto;
    for(int i=0;i<n;i++){
        *texto=arr[i];
        texto++;
    }
    
}

int main(){
    char texto[100];
    cout<<"Ingrese el texto: "<<endl;
    cin.getline(texto,100);
    int n=strlen(texto);

    char* t=new char[n];
    t=texto;
    normalizar(t,n);
    cout<<t<<endl;
    return 0;
}