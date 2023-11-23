#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long int sum = 0;
    for (int i = 0; i < n; i++)
    {
        long long int temp;
        /* code */
        cin >> temp;
        sum += temp;
    }

    cout << sum;
    

    return 0;
}