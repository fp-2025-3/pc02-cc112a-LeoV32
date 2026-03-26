#include <iostream>
using namespace std;

class Libro{
    private:
    string titulo;
    string autor;
    int paginas;

    public:

    Libro(string t,string a, int p): titulo(t),autor(a),paginas(p){};
    Libro(){titulo="desconocido",autor="desconocido",paginas=0;};
    ~Libro(){};

    string getTitulo() const{
        return titulo;
    }
    string getAutor() const{
        return autor;
    }
    int getPaginas() const{
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
        cout<<"Titulo: "<<titulo<<", Autor: "<<autor<<", Paginas: "<<paginas;
    }

};

class LibroDigital:public Libro{
    private:
    string formato;
    public:
    LibroDigital(string t, string a, int p, string f): Libro(t,a,p),formato(f){};
    LibroDigital():Libro(),formato("Desconocido") {};
    ~LibroDigital(){};

    string getFormato() const {
        return formato;
    }
    void setFormato(string f){
        formato=f;
    }
    void mostrarInfoDigital(){
        mostrarInfo();
        cout<<", Formato: "<<formato<<endl;
    }

};


int main(){
    LibroDigital ld("Cien años de soledad", "Marquez", 400, "PDF");

    ld.mostrarInfoDigital();
}