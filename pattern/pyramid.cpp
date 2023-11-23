// Print Pyramid 
#include <iostream>

using namespace std;

void dot(int n){
    for (int i = 0; i < n; i++) {
        cout << ".";
    }
    
}

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        
        dot(n-i);
        
        for (int j = 0; j <= (i*2) - 2; j++) {
            cout << "*";
        }
        
        dot(n-i);
        
        cout << endl;
        
    }
    

    return 0;
}

