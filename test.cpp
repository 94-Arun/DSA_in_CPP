#include <iostream>
#include<vector>
#include<string>
using namespace std;

char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;

        while(low<high){
            int mid = low+(high-low)/2;
            if(letters[mid] > target) high = mid;
            else if(letters[mid] < target) low = mid;
            else return letters[mid+1];
        }
        return letters[high];    
    };

int main() {
    vector<char> v = {'c','f','j'};
    char s = nextGreatestLetter(v,'c');

    // cout << s;

    char i = 'A';
    cout<<char(i+32)<<endl;

}