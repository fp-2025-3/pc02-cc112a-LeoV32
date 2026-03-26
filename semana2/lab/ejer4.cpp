#include <iostream>
using namespace std;

bool mayor(int a, int b);
bool menor(int a, int b);
bool mayorValorAbsoluto(int a, int b);
bool parAntesQueImpar(int a, int b);

int main(){

    int A[] = {7, -2, 5, 0, -9, 4};


}

bool mayor(int a, int b){
    if(a>b) return true;
    else return false;
}

bool menor(int a, int b){
    if(a>b) return false;
    else return true;
}

bool mayorValorAbsoluto(int a, int b){
    if(abs(a)>abs(b)) retun true;
    else return false;
}

bool parAntesQueImpar(int a, int b){
    if(a%2==0 && b%2==1) return true;
    else return false;
}

void ordenar(int* inicio,int* fin, bool (*criterio)(int, int)){
    for(int* pd=inicio;pd<fin-1;pd++){
        if(criterio(*pd,*(pd+1))){
            int save=*pd;
            *pd=*(pd+1);
            *(pd+1)=save;
        }
    }
}