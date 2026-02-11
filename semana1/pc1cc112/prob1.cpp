#include <iostream>
using namespace std;

int superdigito(int n);

int main(){
   cout <<"Salida: "<<superdigito(4);
    return 0;
}

int superdigito(int n){
    if(n-9<=0){// Ya que sies 9 o menor retorna el valor
        return n;
    }
    int res=0;
    while(n/10>0){
        
        int unidad=n%10;
        n=n/10;
        res=res+unidad;
        if(n/10<=0){
            res=res+n;
        }
    }
    return superdigito(res);

}