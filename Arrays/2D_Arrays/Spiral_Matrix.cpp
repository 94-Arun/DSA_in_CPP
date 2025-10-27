#include<iostream>
using namespace std;

void Spiral_Matrix(int mat[][4],int n, int m){
    int srow = 0,scol = 0;
    int ecol = m-1,erow = n-1;

    while(srow<=erow && scol <= ecol){

        // Top 
        for(int j = scol;j<=ecol;j++){
            cout<<mat[srow][j]<<" ";
        }
        // Right
        for(int i = srow+1;i<=erow;i++){
            cout<<mat[i][ecol]<<" ";
        }
        //Bottem
        for(int j = ecol-1;j>=scol;j--){
            if(srow == erow){
                break;
            }
            cout<<mat[erow][j]<<" ";
        }
        // Left
        for(int i = erow-1;i>=srow+1;i--){
            if(scol == ecol){
                break;
            }
            cout<<mat[i][scol]<<" ";
        }
        srow++;scol++;
        erow--;ecol--;
    }
    cout<<endl;
}


int main(){
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};

    // for(int i = 0;i<4;i++){
    //     for(int j = 0;j<4;j++){
    //         cout<<matrix[i][j]<<" ";
    //     }
    // }  
    // cout<<endl;
    
    Spiral_Matrix(matrix,4,4);

    return 0;                
}