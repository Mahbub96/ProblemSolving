#include <iostream>
using namespace std;

int checkGrade(int n){
    if( n < 38) return n;

    for (int i = 8; i <= 20; i++)
    {
        if(i*5 < n) continue; 
        else if( (i*5 - n) <= 2 ) n += (i*5) - n;
    }
    return n;
    
}
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int marks;
        cin >> marks;
        cout << checkGrade(marks) << endl;
    }
    
    
}