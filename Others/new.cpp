#include <iostream>
#include <cstdio>

using namespace std;

/*Globally declear for initial value makes zero*/
int notaCounter[7];
int modeaCounter[7];

void calculation(double &n,double *arr,int *counter){
    
    for (int i = 0; i < 6; i++)
        while(n >= arr[i]){
            counter[i] += 1;
            n -= arr[i];
        }
        
    
}

void print(int count[],double arr[]){
    
    for (int i = 0; i < 6; i++)
    {
        printf("%d nota(s) de R$ %.2lf\n",count[i],arr[i]);
    }
    cout << endl;
}

int main(){
    double Notas[] = {100,50,20,10,5,2};
    double Modeas[] = {1,0.5,0.25,0.10,0.05,0.01};

    double n;
    
    cin >> n;
    cout << n;

   
    calculation(n,Notas,notaCounter);

    calculation(n,Modeas,modeaCounter);
    

    print(notaCounter,Notas);
    cout << "MOEDAS\n";
    print(modeaCounter,Modeas);



    return 0;
}
