#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n][n];
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    
    // first diagonal 
    int firstDiaSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) firstDiaSum += arr[i][j];
        }
    }
    
    // last diagonal 
    int lastDiaSum = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == n-i-1) lastDiaSum += arr[i][j];
        }
    }
    
    cout << abs(firstDiaSum-lastDiaSum);
    
    
    return 0;
}