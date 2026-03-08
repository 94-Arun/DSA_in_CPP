#include<iostream>
#include<string>
using namespace std;


// oops basics in c++
class Car{
    string name;
    string colour;

public:
    Car(string nameVal ,string colourVal){
        cout<<"Constructor is created and called automatically : \n";
        name = nameVal;
        colour = colourVal;
    }
    // Start method
    void start(){
        cout<<"Car is started:\n";
    }
    
    void stop(){
        cout<<"Car is stopped :\n";
    }

    void getname(){
        cout<<"Name of the Car is : "<<name<<endl;
    }

};

// main function 
int main(){

    Car c1("Virtus","Black");
    c1.start();
    c1.getname();

    return 0;
}