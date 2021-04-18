#include <iostream>
#include <cstdio>

using namespace std;
int notaCounter[7];
int modeaCounter[7];

void calculation(double n,double *arr,int i,int *counter){
    if(i == 6) return;
    
    if(n >= arr[i]) {
        
        counter[i] += 1;
        
        calculation(n - arr[i],arr,i,counter);
    }
    else calculation(n,arr,i+1,counter);
    
}

void print(int count[],double arr[]){
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d nota(s) de R$ %.2lf\n",count[i],arr[i]);
    }
    cout << endl;
}
int main(){
    double n = 0;
    cin >> n;
    double Notas[] = {100,50,20,10,5,2};
    double Modeas[] = {1,0.5,0.25,0.10,0.05,0.01};

    calculation(n,Notas,0,notaCounter);
    int temp = n - 1;
    n -= temp;

    cout << n << endl;
    calculation(n,Modeas,0,modeaCounter);
    

    print(notaCounter,Notas);
    cout << "MOEDAS\n";
    print(modeaCounter,Modeas);



    return 0;
}
