#include <iostream>
#include <map>

using namespace std;
void star(int n){
    for (int i = 0; i < n; i+=2)
    {
        for (int j = 0; j < n; j+=2)
        {
            cout << " * ";
        }
        cout << endl;
        
    }
    
}
void stars(int n){
    for (int i = 0; i < n; i+=1)
    {
        for (int j = 0; j < n; j+=1)
        {
            cout << " . ";
        }
        cout << endl;
        
    }
    
}

int main(){
    int n;
    while (true) {
        star(10);
        system("clear");
        stars(10);
        system("clear");

    }
    
    return 0;
}