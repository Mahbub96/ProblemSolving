// print Diamond
#include <iostream>

using namespace std;

void dot(int n) {
    for (int i = 0; i < n; i++) {
        cout << ".";
    }
    
}
void star(int n){
    for (int i = 0; i < n; i++)
    {
        cout << "*";
    }
    
}


int main(){
    int n;
    cin >> n;
    for (int i = 1; i < n ; i++) {
        
        dot(n-i);
        
        star((i*2) - 1);
        
        dot(n-i);
        
        cout << endl;
        
    }
    for (int i = 0; i < n; i++) {
        
        dot(i);
        
        star((((n-i)*2)-1));
   
        dot(i);
        
        cout << endl;
        
    }
    

    return 0;
}

