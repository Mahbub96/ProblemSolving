#include <bits/stdc++.h>

using namespace std;



int main()
{
    int N;
    cin >> N;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < N; i++)
    {
        /* code */
        if(!(i%2)) cout << i << " ";
    }
    
    
    return 0;
}
