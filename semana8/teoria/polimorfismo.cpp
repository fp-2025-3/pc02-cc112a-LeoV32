#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void id(){
        cout<<"Animal"<<endl;
    }
    virtual ~Animal(){
        cout<<"Destructor animal"<<endl;
    }
};

class Cat : public Animal{
    public:
    void id() override{
        cout<<"Cat"<<endl;
    }
    ~Cat() override{
        cout<<"Destructor cat"<<endl;
    }
};

class Dog : public Animal{
    public:
    void id() override{
        cout<<"Dog"<<endl;
    }
    ~Dog() override{
        cout<<"Destructor dog"<<endl;
    }
};

int main(){

    Animal* e[]={new Animal,new Cat, new Dog};
    
    for(int i=0;i<3;i++){
        e[i]->id();
    }

    for(int i=0;i<3;i++){
        delete e[i];
    }

    return 0;

}