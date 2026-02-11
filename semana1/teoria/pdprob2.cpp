#include <iostream>
using namespace std;

int dias(int n);

int main(){
    int n=10;
    cout << "Numero minimo de dias para comer " << n << " manzanas: ";
    cout << dias(n) <<endl;
}

int dias(int n){
    if(n<=0) return 0;

    int minfinal=1+dias(n-1);

    if(n%2==0){
        int opcion2=1+dias(n/2);

        if(opcion2<minfinal) minfinal=opcion2;
    }

    if(n%3==0){
        int opcion3=1+dias(n/3);
        if(opcion3<minfinal) minfinal=opcion3;
    }

    return minfinal;
}