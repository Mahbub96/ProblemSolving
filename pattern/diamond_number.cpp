// print Number Pyramid 
#include <iostream>

using namespace std;

void dot(int n) {
    for (int i = 0; i < n; i++) {
        cout << ".";
    }
    
}

void numFor(int n){
    for (int i = 1; i <= n; i++)
    {
        cout << i;
    }
    
}
void numRev(int n){
    while(n-1){
        cout << --n;
    }

    
}

int main(){
    int n;
    cin >> n;
    /*Before mid*/
    for (int i = 1; i < n; i++) {
        
        dot(n-i);
    
        numFor(i);
        numRev(i);
        
        dot(n-i);
        
        cout << endl;
        
    }

    /*after mid*/
    for (int i = 1; i <= n; i++) {
        
        dot(i - 1);
        
        numFor(n - (i - 1));
        numRev(n - (i - 1));
        
        dot(i-1);
        
        cout << endl;
        
    }
    

    return 0;
}

