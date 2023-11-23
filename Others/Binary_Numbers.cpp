#include <bits/stdc++.h>

using namespace std;



int main()
{
    stack<int> s;
    int n;
    cin >> n;
    int flag = 0,updateFlag = 0;

    while(n != 0){
        s.push(n%2);
        n /= 2;
    }
    
    while (s.size())
    {
        if(s.top() == 1) flag++;
        else {
            if(flag > updateFlag) updateFlag = flag;
            flag = 0;
        }
        s.pop();
    }
    
    if(flag > updateFlag) updateFlag = flag;
    
    cout << updateFlag;
    
    
    return 0;
}
