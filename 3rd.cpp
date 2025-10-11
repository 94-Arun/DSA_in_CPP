#include <iostream>
using namespace std;

// class Student {
// private:
//     string name;
//     int age;

// public:
//     // Default Constructor
//     Student() {
//         name = "Arun Kumar";
//         age = 20;
//         cout << "Default constructor called!" << endl;
//     }

//     // Function to display data
//     void display() {
//         cout << "Name: " << name << "\nAge: "<< age << endl;
//     }
// };

// int main() {
//     // Object created using default constructor
//     Student s1;

//     s1.display();

//     return 0;
// }

// Friend Function Example

class ClassB; // forward declaration

class ClassA {
private:
    int numA;
public:
    ClassA(int a) : numA(a) {}
    friend int add(ClassA, ClassB); // friend function
};

class ClassB {
private:
    int numB;
public:
    ClassB(int b) : numB(b) {}
    friend int add(ClassA, ClassB); // same friend
};

int add(ClassA objA, ClassB objB) {
    return objA.numA + objB.numB; // direct access to private members
}

int main() {
    ClassA a(5);
    ClassB b(10);

    cout << "Sum = " << add(a, b) << endl;
    return 0;
}
