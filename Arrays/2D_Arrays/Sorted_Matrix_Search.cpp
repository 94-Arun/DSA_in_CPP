#include<iostream>
using namespace std;

bool Search(int mat[][4],int n,int m,int key){
    int i = 0,j = m-1;

    while(i<n && j>=0){

        if(key == mat[i][j]){
            cout<<"Key found on the Index : ("<<i<<","<<j<<")"<<endl;
            return true;
        }
        else if(key < mat[i][j]){
            j--;
        }else{
            i++;
        }  
    }
    cout<<"Key Not Found"<<endl;
    return false;
}

int main(){
    int matrix[4][4] = {{10,20,30,40},
                        {15,25,35,45},
                        {27,29,37,48},
                        {32,33,39,50}};

    Search(matrix,4,4,33);                    
    

    return 0;                
}