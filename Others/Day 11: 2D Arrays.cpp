#include <iostream>

using namespace std;

int main(){
    int Domain[6][6];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            int tempInp;
            cin >> tempInp;
            Domain[i][j] = tempInp;
        }
        
    }
    
    int maxSum = -999999;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int temp = 0;
            temp += Domain[i][j];
            temp += Domain[i][j+1];
            temp += Domain[i][j+2];

            temp += Domain[i+1][j+1];

            temp += Domain[i+2][j];
            temp += Domain[i+2][j+1];
            temp += Domain[i+2][j+2];

            maxSum = max(maxSum,temp);

        }
        
    }
    cout << maxSum << endl;
    return 0;
    
}