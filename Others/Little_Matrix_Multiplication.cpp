#include <iostream>

using namespace std;

void print(int a[][2]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
        
    }
    
}

void matInput(int A[2][2]){
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int temp;
            cin >> temp;
            A[i][j] = temp;
        }
        
    }
}

void matrixMul(int A[][2],int B[][2]){
    int matC[2][2];
    
    
    matC[0][0] = (A[0][0]*B[0][0]) + (A[0][1]*B[1][0] );
    matC[0][1] = (A[0][0]*B[0][1]) + (A[0][1]*B[1][1]);
    matC[1][0] = (A[1][0]*B[0][0]) + (A[1][1]*B[1][0]);
    matC[1][1] = (A[1][0]*B[0][1]) + (A[1][1]*B[1][1]);

    
    print(matC);
    
    

}

int main(){
    int matA[2][2],matB[2][2];

    matInput(matA);
    matInput(matB);
    
    matrixMul(matA,matB);
    return 0;
}