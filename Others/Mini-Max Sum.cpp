#include <iostream>

using namespace std;

int main(){
    long int temp;

    cin >> temp;
    long int maxValue = temp;
    long int minValue = temp;
    long int sum = temp;
    for (long int i = 1; i < 5; i++)
    {
        cin >> temp;
        sum += temp;


        maxValue = max(maxValue,temp);
        minValue = min(minValue,temp);

        
    }
        
    cout << sum-maxValue << " " << sum-minValue << endl;

    return 0;
}