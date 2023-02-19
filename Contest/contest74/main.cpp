#include <iostream>

using namespace std;


int main(){
    int T;
    double w,g;

    cin >> T;
    while(T--){
        cin >> w >> g; 
        cout << (w - g)/2;
    }
    return 0;
}