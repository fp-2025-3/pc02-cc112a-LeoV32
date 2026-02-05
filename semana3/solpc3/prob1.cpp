#include <iostream>
#include <cstring>
using namespace std;

bool buscar(int* arr, int n, int k);
int extraer(char* texto,int* arreglo);

int main(){
    char texto[]={"1, 2, 4, 7, 11"};
    int arr[100];
    int k=15,e=10;
    int n=extraer(texto,arr);
    if(buscar(arr,n,k)) cout<<"SI ";
    else cout<<"NO ";
    cout<<"existen 2 numero con suma "<<k<<endl;
    if(buscar(arr,n,e)) cout<<"SI ";
    else cout<<"NO ";
    cout<<"existen 2 numero con suma "<<e<<endl;

    return 0;
}

int extraer(char* texto,int* arreglo){
    int* q=arreglo;
    char* p=texto;
    while(*p!='\0'){
        if(*p>='0' && *p<='9'){
            int n=0;
            while(*p>='0' && *p<='9'){
                n=n*10+(*p-'0');
                p++;
            }
                *q=n;
                q++;
        } else p++;
        
    }
    return q-arreglo;
    
}

bool buscar(int* arr, int n, int k){
    int* i=arr;
    int* j=arr+n-1;

    while(i<j){
        int suma=*i+*j;
        if(suma==k) return true;
        if(suma<k) i++;
        else j--;
    }
    return false;
}
