#include<iostream>
#include<string>
using namespace std;

void subsets(string str,string subset,int n){
    char ch = str[0];
    if(str.size() == 0){
        cout<<subset<<"";
        return ;
    }

    subsets(str.substr(1,n-1),subset + ch,n);// yes
    subsets(str.substr(1,n-1),subset,n);// no

}

int main(){
    string str = "abc";
    string subset = " ";
    int n = str.size();
    subsets(str,subset,n);
    return 0;
}