#include<iostream>
using namespace std;

void reverse(char word[20],int n){
    int start = 0,end = n-1;
    while(start < end){
        swap(word[start],word[end]);
        start++;
        end--;
    }
}

int main(){
    char word[20] = "GurugramUniversity";
    cout<<word<<endl;
    reverse(word,strlen(word));
    cout<<word<<endl;
}