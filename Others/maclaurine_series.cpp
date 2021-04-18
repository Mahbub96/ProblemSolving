#include <iostream>
#include <cmath>

using namespace std;

double fact(int n){
    if(n <= 1) return 1;
    return n * fact(n-1);
}

int main(){
    int n,x;
    cin >> n >> x;

    for (int i = 0; i < n; i++)
    {
        if( (i+1) == n) cout << ((pow(x,2*i))/fact(2*i)) << endl;
        else cout << ((pow(x,2*i))/fact(2*i)) << " + ";
        // if( (i+1) == n) cout << ((pow(x,2*i))/fact(2*i)) << endl;
        
        // else if((i%2) && (i > 0)) cout << ((pow(x,2*i))/fact(2*i)) << " + ";
        
        // else cout << ((pow(x,2*i))/fact(2*i)) << " - ";
    }
    cout << endl;
 


    return 0;
}