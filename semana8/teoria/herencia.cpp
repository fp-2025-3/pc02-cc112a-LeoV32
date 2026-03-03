#include <iostream>
using namespace std;

class Vehiculo{
    protected:
    int ruedas;
    string color;

    public:
    Vehiculo(int r, string c) : ruedas(r),color(c) {};
    ~Vehiculo(){
        cout<<"Destructor Vehiculo: "<<endl;
    };
    void mostrarInfo() {
        cout << "Numero de ruedas del vehiculo: " << ruedas <<endl;
        cout << "Color del vehiculo: " << color <<endl;
    }
};

class Coche : public Vehiculo{
    private:
    int numeroPuertas;

    public:
    Coche(int r,string c, int np) : Vehiculo(r,c),numeroPuertas(np){};
    ~Coche(){
        cout<<"Destructor Coche: "<<endl;
    }
    void mostrarCoche(){
        mostrarInfo();
        cout<<"Numero de ruedas del coche: "<<numeroPuertas<<endl;
    }

};

int main(){

}