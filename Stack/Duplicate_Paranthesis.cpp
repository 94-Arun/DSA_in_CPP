#include<iostream>
#include<string>
#include<stack>
using namespace std;

// duplicate Parenthesis
bool duplicateParanthesis(string str){
    stack<char> s;
    
    for(int i = 0; i<str.size();i++){
        char ch = str[i];

        if(ch != ')') s.push(ch);
        else{
            if(s.top() == '(') return true;
            while(s.top() != '(') s.pop();
            s.pop();
        }
    }
    return false;
}

// main function
int main(){
    string str1 = "((a+b))";
    string str2 = "((a+b)+(a+b))";

    cout<<duplicateParanthesis(str1)<<endl;
    cout<<duplicateParanthesis(str2)<<endl;

    return 0;
}