// print Number Pyramid Using recursion  
#include <iostream>

using namespace std;

void dot(int n) {
    if(n == 0) return;
    cout << ".";
    dot(n-1);
    
}
/*Number Print*/
void printNum(int init,int n){
    cout << init;
    if(init == n ) return;
    printNum(init+1,n);
    cout << init;
}

/*vertical stack */
void vertical(int i,int n){

    /*before Middle */
    dot(n-i);
    printNum(1,i);
    dot(n-i);
    cout << endl;
    
    /*Condition for return */
    if(i == n) return;

    vertical(i+1,n);

    /*after middle point*/
    dot(n-i);
    printNum(1,i);
    dot(n-i);
    cout << endl;
    
}

int main(){
    int n;
    cin >> n;
    vertical(1,n);
    return 0;
}

