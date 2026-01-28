#include <iostream>
using namespace std;

int my_strlen(const char* str);
char *my_strcpy(char* destination,const char* source);
char *my_strcat(char *string1, const char *string2);
int my_strcmp(const char *string1, const char *string2);

int main() {
    // ====== 1. strlen ======
    char password[20] = "abc123";

    cout << "Password: " << password << endl;
    cout << "Longitud del password: " << my_strlen(password) << endl;

    if (my_strlen(password) < 8) {
        cout << "La contraseña es muy corta\n\n";
    }

    // ====== 2. strcpy ======
    char nombreEntrada[20] = "Leo";
    char nombreGuardado[20];

    my_strcpy(nombreGuardado, nombreEntrada);
    cout << "Nombre guardado: " << nombreGuardado << endl << endl;

    // ====== 3. strcat ======
    char nombre[20] = "Leo";
    char apellido[20] = "Velasquez";
    char nombreCompleto[50];

    my_strcpy(nombreCompleto, nombre);   // primero copiar
    my_strcat(nombreCompleto, " ");      // agregar espacio
    my_strcat(nombreCompleto, apellido);

    cout << "Nombre completo: " << nombreCompleto << endl << endl;

    // ====== 4. strcmp ======
    char usuarioCorrecto[] = "admin";
    char usuarioIngresado[20] = "admin";

    if (my_strcmp(usuarioCorrecto, usuarioIngresado) == 0) {
        cout << "Acceso permitido\n";
    } else {
        cout << "Acceso denegado\n";
    }

    return 0;
}

int my_strlen(const char* str){
    
    const char* a=str;
    while(*a!='\0'){
        a++;
        
    }
    return a-str;
}

char *my_strcpy(char* destination,const char* source){
    char* inicio = destination;
    while(*source!='\0'){
        *destination=*source;
        destination++;
        source++;
    }
    *(destination)='\0';
    return inicio;
}

char *my_strcat(char *string1, const char *string2){
    char* inicio=string1;
    while(*string1!='\0'){
        string1++;
    }
    while(*string2!='\0'){
        *string1=*string2;
        string1++;
        string2++;
    }
    return inicio;
}

int my_strcmp(const char *string1, const char *string2){
    while(*string1==*string2 && *string1!='\0' && *string2!='\0'){
        string1++;
        string2++;
    }
    return *string1-*string2;
}