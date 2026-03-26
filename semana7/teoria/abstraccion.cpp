#include <iostream>
using namespace std;

class Libro{
    private:
    string titulo;
    string autor;
    int paginas;

    public:
    
    Libro(string t,string a,int p): titulo(t),autor(a),paginas(p){};

    Libro(){
        titulo="Dosconocido";
        autor="Desconocido";
        paginas=0;
    };

    ~Libro(){};

    string getTitulo() const {
        return titulo;
    }
    string getAutor() const {
        return autor;
    }
    int getPaginas() const {
        return paginas;
    }

    void setTitulo(string t){
        titulo=t;
    }
    void setAutor(string a){
        autor=a;
    }
    void setPaginas(int p){
        paginas=p;
    }
    void mostrarInfo(){
        cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas<<endl;
    }
};

int main(){

    Libro libro1;
    Libro libro2("Don Quijote","Cervantes",800);
    libro1.mostrarInfo();
    libro2.mostrarInfo();
    libro1.setTitulo("El viejo y el mar");
    libro1.setAutor("Anonimo");
    libro1.setPaginas(100);
    cout<<"Mostrando libro1 despues de coambiar datos: "<<endl;
    libro1.mostrarInfo();

    return 0;
}