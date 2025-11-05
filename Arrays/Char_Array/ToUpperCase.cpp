#include<iostream>
using namespace std;

void toUpper(char word[20],int n){
    
    for(int i=0;i<n;i++){
        char ch = word[i];
        if(ch >= 'A' && ch <= 'Z'){
            continue;
        }else{
           word[i] = ch - 'a' + 'A';
        }
    }

}

int main(){
    char word[20] = "AruN";
    cout<<"Woard is : "<<word<<endl;
    toUpper(word,strlen(word));
    cout<<"Woard is : "<<word<<endl;
    
}