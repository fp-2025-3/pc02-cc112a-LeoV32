#include <iostream>
#include <fstream>
using namespace std;

struct Producto
{
    int id;          // Identificador único
    char nombre[30]; // Nombre del producto
    double precio;   // Precio unitario
    int stock;       // Cantidad disponible
    bool activo;     // true = activo, false = eliminado lógicamente
};

void registrarProducto(const char *nombreArchivo);
void mostrarProductos(const char *nombreArchivo);
int buscarProductoPorID(const char *nombreArchivo, int idBuscado);
void modificarPrecio(const char *nombreArchivo, int id, double nuevoPrecio);
void eliminarProducto(const char *nombreArchivo, int id);
double calcularValorInventario(const char *nombreArchivo);

int main(){
    char nombre[]={"output/inventario.dat"};
    int n,id;
    do{
        cout<<"MENU:"<<endl;
        cout<<"--------------------------------"<<endl;
        cout<<"1. Registrar producto"<<endl;
        cout<<"2. Mostrar productos"<<endl;
        cout<<"3. Buscar producto"<<endl;
        cout<<"4. Modificar precio"<<endl;
        cout<<"5. Eliminar producto"<<endl;
        cout<<"6. Calcular valor total"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<"Opcion: ";
        cin>>n;

        switch (n){
            case 1:
            {registrarProducto(nombre);
            break;}

            case 2:
            {mostrarProductos(nombre);
            break;}

            case 3:
            {cout<<"Ingrese el ID: ";
            cin>>id;
            int a=buscarProductoPorID(nombre,id);
            if(a!=-1) cout<<"Se encontro el producto en la posicion "<<a<<endl;
            else cout<<"No se encontro"<<endl;
            break;}

            case 4:
            {double precio;
            
                cout<<"Ingrese el ID: ";
                cin>>id;
            if(buscarProductoPorID(nombre,id)==-1) break;
            do{
                cout<<"Ingrese el precio: ";
                cin>>precio;
            }while(precio<=0);
            modificarPrecio(nombre,id,precio);
            break;}

            case 5:
            {cout<<"Ingrese el ID: ";
            cin>>id;
            eliminarProducto(nombre,id);
            break;}

            case 6:
            {cout<<"El valor del inventario es: "<<calcularValorInventario(nombre)<<endl;
            break;}

            case 7:
            {cout<<"Saliendo..."<<endl;
            break;}
        }
    }while(n!=7);

    return 0;
}

int buscarProductoPorID(const char *nombreArchivo, int idBuscado){
    ifstream archivoLectura(nombreArchivo, ios::in | ios::binary);

    if (!archivoLectura)
    {
        cerr << "Error al leer el archivo" << endl;
        return -1;
    }
    Producto e;
    int cont = 0;
    while (archivoLectura.read((char *)&e, sizeof(Producto)))
    {
        if (e.id == idBuscado)
        {
            archivoLectura.close();
            return cont;
        }
        cont++;
    }
    archivoLectura.close();
    return -1;
}

void registrarProducto(const char *nombreArchivo){
    cout << "Producto: " << endl;
    Producto e;
    e.activo = true;
    cout << "Ingrese el ID: ";
    cin >> e.id;
    if(buscarProductoPorID(nombreArchivo, e.id) != -1 ){
        cout<<"El ID es el mismo "<<endl;
        return;
    } 
    cout << "Ingrese el nombre: ";
    cin.ignore();
    cin.getline(e.nombre, 30);
    do
    {
        cout << "Ingrese el precio: ";
        cin >> e.precio;
    } while (e.precio <= 0);
    do
    {
        cout << "Ingrese el stock: ";
        cin >> e.stock;
    } while (e.stock < 0);

    ofstream archivoEscritura(nombreArchivo, ios::out | ios::app | ios::binary);

    if (!archivoEscritura)
    {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }

    archivoEscritura.write((char *)&e, sizeof(Producto));

    archivoEscritura.close();
}

void mostrarProductos(const char *nombreArchivo){
    ifstream archivoLectura(nombreArchivo, ios::out | ios::binary);

    if (!archivoLectura){
        cerr << "Error al abrir el archivo" << endl;
        return;
    }
    Producto e;
    cout << "Mostrando Productos: " << endl;
    cout << "---------------------" << endl;
    int cont = 0;
    while (archivoLectura.read((char *)&e, sizeof(Producto))){
        if(e.activo==true){
            cout<<"Producto "<<cont<<": "<<endl;
            cout<<"ID: "<<e.id<<endl;
            cout<<"Nombre: "<<e.nombre<<endl;
            cout<<"Precio: "<<e.precio<<endl;
            cout<<"Stock: "<<e.stock<<endl;
            cout<<endl;
        }
        cont++;
    }
    archivoLectura.close();
}

void modificarPrecio(const char *nombreArchivo, int id, double nuevoPrecio){
    fstream archivo(nombreArchivo,ios::in | ios::out | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    int posicion=buscarProductoPorID(nombreArchivo,id);

    archivo.seekg(posicion*sizeof(Producto),ios::beg);
    
    Producto e;

    archivo.read((char*)&e,sizeof(Producto));

    e.precio=nuevoPrecio;

    archivo.seekp(posicion*sizeof(Producto),ios::beg);

    archivo.write((char*)&e,sizeof(Producto));

    archivo.close();
}

void eliminarProducto(const char* nombreArchivo, int id){
    fstream archivo(nombreArchivo, ios::in | ios::out | ios::binary);

    if(!archivo){
        cerr<<"Error al abrir el archivo"<<endl;
        return;
    }

    int posicion=buscarProductoPorID(nombreArchivo,id);

    archivo.seekg(posicion*sizeof(Producto),ios::beg);
    Producto e;
    archivo.read((char*)&e,sizeof(Producto));
    e.activo=false;
    archivo.seekp(posicion*sizeof(Producto),ios::beg);
    archivo.write((char*)&e,sizeof(Producto));
    archivo.close();
}

double calcularValorInventario(const char* nombreArchivo){
    
    ifstream archivoLectura(nombreArchivo,ios::in | ios::binary);

    if(!archivoLectura){
        cerr<<"Error al abrir el archivo"<<endl;
        return -1;
    }
    double resultado=0;

    Producto e;
    while(archivoLectura.read((char*)&e,sizeof(Producto))){
        if(e.activo==true){
            resultado=+e.stock*e.precio;
        }
    }
    return resultado;
}