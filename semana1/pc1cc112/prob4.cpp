#include <iostream>
using namespace std;

void concatena(int C[],int A[],int B[],int n);

int main(){
    int A[]={10,8,6,4};
    int n=sizeof(A)/sizeof(A[0]);//Como me dicen mismo tamaño puedo hallarlo de uno de ellos
    int B[]={9,7,6,5};
    int arr[8];

    concatena(arr,A,B,n);

    cout<<"Lista intercalada L: "<<endl;
    cout<<"Indices: ";
    for(int i=0;i<2*n;i++){
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"Valores: ";
    for(int i=0;i<2*n;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<endl;

    return 0;
}

void concatena(int C[],int A[],int B[],int n){
    int i=0,j=0;
    for(int k=0;k<2*n;k++){
        if(k%2==0){
            C[k]=B[i];
            i++;
        }else{
            C[k]=A[j];
            j++;
        }
    }
}