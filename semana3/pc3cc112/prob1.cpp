#include <iostream>
#include <cstring>
using namespace std;


int main(){
    char texto[]={"1, 2, 4, 7, 11"};
    
    

    return 0;
}

void procesar(char* texto,int k){
    int arreglo[100];
    int* q=arreglo;
    char* p=texto;
    while(*p!='\0'){
        if(*p!=' '){
            int n=0;
            while(*p!=' ' && *p!='\0'){
                int a=atoi(p);
                n=n+a;
                if(*(p+1)!=' ' && *(p+1)!='\0'){
                    n=n*10;
                }
                p++;
            }
            if(n!=0){
                *q=n;
                q++;
            }
        }
    }
    int n=q-arreglo;
    int suma=0;
    if(k>arreglo[n-1]){
        for(int *i=arreglo+n-1;i>=0;i--){
            suma+=*i;
            if(arreglo[n-1]*3/2<k){
                for(int *j=arreglo+n-1;j>=arreglo;j--){
                    if(suma+*j==k) cout<<"SI ";
                }
            }else{
                for(int *j=arreglo;j<arreglo+n;j++){

                }
            }
             
        }
    }
}
