#include <iostream>
using namespace std;

// Binary to Decimal Conversion
int binaryToDecimal(int binaryNum) {
    int n = binaryNum;
    int decimalNum = 0;
    int pow = 1;

    while(n > 0){
        int lastdigit = n % 10;
        decimalNum += lastdigit * pow;
        n = n / 10;
        pow = pow * 2;
    }

    return decimalNum;
}


// Decimal to Binary Conversion
int decimalToBinary(int decimalNum){
    int n = decimalNum;
    int pow = 1;
    int binaryNumber = 0;

    while(n>0){
        int rem = n % 2;
        binaryNumber += rem * pow;
        n = n/2;
        pow = pow * 10;
    }
    return binaryNumber;
}

int main(){
    // int binarynumber;
    // cout<<"Enter a binary number:";
    // cin>>binarynumber;
    // cout<<"Decimal number is:"<<binaryToDecimal(binarynumber)<<endl;

    int decimalnumber;
    cout<<"Enter a decimal number:";
    cin>>decimalnumber;
    cout<<"Binary number is:"<<decimalToBinary(decimalnumber)<<endl;
    return 0;
}