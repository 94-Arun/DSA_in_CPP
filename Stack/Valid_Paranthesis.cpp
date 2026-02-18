#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isValid(string str){
    stack<char> s;

    for(int i = 0;i<str.size();i++){
        char ch = str[i];
        //opening
        if(ch == '('|| ch == '{' || ch == '['){
            s.push(ch);
        }
        //closing
        else{
            if(s.empty()) return false;
            
        // match
            char top = s.top();
            if(top =='(' && ch == ')' || 
                top == '{' && ch == '}' ||
                top == '[' && ch == ']')
                s.pop();
            else{
                return false;
            }
        }
    }
    return s.empty();
}


int main(){
    string s1 = "(({[]}))"; //valid
    string s2 = "({[[]})"; //invalid

    cout<<isValid(s1)<<endl;
    cout<<isValid(s2)<<endl;
    return 0;
}