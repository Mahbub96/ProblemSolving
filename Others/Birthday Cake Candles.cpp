#include <iostream>

using namespace std;

int main(){
    int n,maxLength = 0,maxValue = 0;
    cin >> n;
    long int candles[n];

    for (int i = 0; i < n; i++)
    {
        /* code */
        int temp;
        cin >> temp;
        candles[i] = temp;
        maxLength = max(maxLength,temp);
    }

    for (int i = 0; i < n; i++)
    {
        if(maxLength == candles[i]) maxValue++;
    }
    
    cout << maxValue;
    

    return 0;
}