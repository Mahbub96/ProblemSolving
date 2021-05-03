#include <iostream>

using namespace std;

int compare(int a,int b){
    if(a == b) return 0;
    return a > b ? 1 : -1;
}


int main(){
    int a[3],b[3];
    
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> b[i];
    }
    
    int result[2] = {0};
    for (int i = 0; i < 3; i++)
    {
        int temp = compare(a[i],b[i]);
        if(temp == 1) result[0] += 1;
        if(temp == -1) result[1] += 1;
    }
    
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << " ";
    }
    


    return 0;
}