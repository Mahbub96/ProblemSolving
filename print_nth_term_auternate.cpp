#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if(n == i) {
            cout << i << endl;
            break;
        }
        if(i%2) cout << i << " - ";
        else cout << i << " + ";
    }
    
}