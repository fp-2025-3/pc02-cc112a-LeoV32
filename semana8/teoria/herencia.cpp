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

class Moto : public Vehiculo{
    private:
    bool conCasco;

    public:
    Moto(int r, string c, bool cC) : Vehiculo(r,c), conCasco(cC){};
    ~Moto(){
        cout<<"Destructor Moto: "<<endl;
    }
    void mostrarMoto(){
        mostrarInfo();
        cout<<"Tiene casco "<<conCasco<<endl;
    }

};

int main(){

    Vehiculo v1(4,"Azul");
    v1.mostrarInfo();

    Coche c1(4, "Rojo", 4);
    c1.mostrarCoche();

    Moto m1(2, "Negro",true);
    m1.mostrarMoto();

    return 0;
}