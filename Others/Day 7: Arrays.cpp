#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    
    while(--n+1){
        cout << arr[n] << " ";
    }
    
    
    return 0;
}