#include <iostream>
using namespace std;

int main() {
    int matriz[2][3] = {{1,2,3},{4,5,6}};
    int* p = matriz[1];

    cout << p[0] << endl;
    cout << p[1] << endl;
    cout << p[2] << endl;
    
}
