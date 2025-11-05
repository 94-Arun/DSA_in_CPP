#include<iostream>
#include<cstring>
using namespace std;

void ValidPalindrom(char word[20],int n){
    int start = 0,end = n-1;
    bool valid = true;
    while(start <= end){
       if(word[start] == word[end]){
        start++;
        end--;
       }
       else{
        valid = false;
        break;
       }
    }
    if(valid){
        cout<<"The Woard is a valid Palindrom "<<endl;
    }else{
        cout<<"Not A Valid Palindrom "<<endl;
        
    }
}

int main(){
    char word[20] = "racecar";
    cout<<word<<endl;
    ValidPalindrom(word,strlen(word));
    return 0;
}