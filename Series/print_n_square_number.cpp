#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if(n == i) {
            cout << pow(i,2) << endl;
            break;
        }
        cout << pow(i,2)  << " + ";
    }
    
}