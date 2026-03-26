#include <iostream>
using namespace std;

void derivar(int A[],int* n);

int main(){
    int A[6]={1,2,3,4,5,6};
    int n=sizeof(A)/sizeof(A[0]);
    int* p=&n;
    int k=3;
    for(int i=0;i<*p;i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl;
    derivar(A,p);
    
    for(int i=0;i<*p;i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl;
}

void derivar(int A[],int* n){
    int i=0;
    for(int* pd=A;pd<A+*n;pd++){
        *pd=*pd * i;
        i++;
    }
    for(int* pd=A;pd<A+*n-1;pd++){
      *pd=*(pd+1);
    }
    *n=*n-1;

}