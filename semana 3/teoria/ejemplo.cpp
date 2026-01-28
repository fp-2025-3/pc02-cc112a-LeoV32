#include <iostream>
using namespace std;

int main() {
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl;
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;

    char x = '9';

    if (x > '5') {
        cout << "Mayor"<<endl;
    }

    char c = 'A';
    c = c + 1;
    cout << c<<endl;
    // 'A'  = 65
    // 65 + 1 = 66 --> 'B'
    // 'z' + 1 ?

    char d = 'D';
    d = d + ('a' - 'A');
    cout<<d<<endl;
    //'a' - 'A' = 32

    int edad;
    cout<<"Ingresa la edad: ";
    cin>>edad;
    cin.ignore();
    cout<<"Ingresar el nombre: ";
    char nombre[10];
    //ERROR: cin >> nombre;
    // El código puede detener el programa sin avisar
    cin.getline(nombre, 10);
    cout<<edad<<endl;
    cout<<nombre<<endl;
}