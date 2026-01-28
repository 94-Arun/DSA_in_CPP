#include<iostream>
using namespace std;
#include<list>
#include<iterator>

void PrintList(list<int> ll){
    list<int>::iterator itr;
    for(itr = ll.begin();itr != ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int> ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.push_back(5);
    PrintList(ll);
    cout<<ll.size()<<endl;

}