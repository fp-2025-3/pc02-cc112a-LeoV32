#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(const double* coef,int grado, int k, double* res, int& gradoRes) {
    // Escriba su codigo aqui
    int i=k;
    for(const double* pd=coef+k;pd<coef+grado+1;pd++){
        int g=i;
        int cont=0;
        *res=*pd;
        while(cont<k){
            *res = *res * g;
            
            g--;
            cont++;
        }
        i++;
        res++;
    }
    gradoRes = grado - k;

}




// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) {
    int i=grado;
   for(const double* pd=p+grado;pd>=p;pd--){
    if(i>0){
        cout<<*pd<<"x^"<<i<<" + ";
        i--;
    } else{
        cout<<*pd<<endl;
    }
    
   }
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK
    derivadaK(coef,grado,k,resultado,gradoResultado);

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada
    cout<<"Arreglo original: "<<endl;
    imprimirPolinomio(coef,grado);
    cout<<endl;
    cout<<"Arreglo modificado: "<<endl;
    imprimirPolinomio(resultado,gradoResultado);
    cout<<endl;

    return 0;
}
