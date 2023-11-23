#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    float ratio[3] = {0};

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if(temp > 0) ratio[0] += 1;
        else if(temp < 0) ratio[1] += 1;
        else ratio[2] += 1;

    }

    for (int i = 0; i < 3; i++)
    {
        cout << ratio[i]/n << endl;
    }
    
    

    return 0;
}