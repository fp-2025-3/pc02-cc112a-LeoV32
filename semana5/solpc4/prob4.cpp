#include <iostream>
using namespace std;

struct Item{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido{
    int numPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

int main(){

}

Pedido* crearPedido