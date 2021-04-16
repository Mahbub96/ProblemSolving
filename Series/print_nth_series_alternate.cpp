#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    int number = 1;
    for (int i = 1; i <= n; i++)
    {
        if(i > 1) cout << " + ( ";

        for (int j = 1; j <= i; j++)
        {
            if(j == i) {
                cout << number++ << " ";
            }
            else if(!(j%2)) cout << number++ << " * ";
            else  cout << number++ << " + ";
             
        }
        if(i > 1) cout << ")";
        
        
    }
    
}

