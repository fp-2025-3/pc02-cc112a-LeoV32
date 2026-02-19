#include <iostream>
#include <cmath>
using namespace std;

struct Punto{
    int x;
    int y;
    int z;
};

double distancia(Punto A1,Punto A2){

    return sqrt(pow(A1.x-A2.x,2)+pow(A1.y-A2.y,2)+pow(A1.z-A2.z,2));
}



int main(){
    Punto E1,E2;
    cout<<"Ingrese las coordenadas del primer punto: "<<endl;
    cout<<"X: ";
    cin>>E1.x;
    cout<<"Y: ";
    cin>>E1.y;
    cout<<"Z: ";
    cin>>E1.z;
    cout<<"Ingrese las coordenadas del segundo punto: "<<endl;
    cout<<"X: ";
    cin>>E2.x;
    cout<<"Y: ";
    cin>>E2.y;
    cout<<"Z: ";
    cin>>E2.z;
    cout<<"La distancia entre los dos puntos es: "<<distancia(E1,E2)<<endl;
    return 0;
}
