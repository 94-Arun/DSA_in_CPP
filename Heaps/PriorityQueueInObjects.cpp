#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Student{
public:    
    string name ;
    int marks;
    
    Student(string name,int marks){
        this->name = name;
        this->marks = marks;
    }
//  for max heap
    bool operator < (const Student &obj) const{
        return this->marks < obj.marks;
    }
};

int main(){
    priority_queue<Student> s;

    s.push(Student("arun",500));
    s.push(Student("jack",400));
    s.push(Student("jaat",1000));
    s.push(Student("brad",300));

    cout << s.top().marks << endl;

    return 0;
}