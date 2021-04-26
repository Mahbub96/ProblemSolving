#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

/*Globally declear for initial value makes zero*/
int notaCounter[7];
int modeaCounter[7];

void calculation(double &n,double* arr,int* counter){
    
    for (int i = 0; i < 6; i++)
        while(n >= arr[i]) { 
            counter[i] += 1; 
            n -= arr[i];
        }
        
}

void print(int count[],char* str,double arr[]){
    
    for (int i = 0; i < 6; i++) printf("%d %s %.2lf\n",count[i],str,arr[i]);
    
    cout << endl;
}

int main(){

    double Notas[] = {100,50,20,10,5,2};
    double Modeas[] = {1,0.5,0.25,0.10,0.05,0.01};

    double n;
    
    cin >> n;

   
    calculation(n,Notas,notaCounter);

    calculation(n,Modeas,modeaCounter);
    

    /*Just Printing sector here*/
    char str[20];
    cout << "NOTAS\n";
    strcpy(str,"nota(s) de R$");
    print(notaCounter,str,Notas);

    cout << "MOEDAS\n";
    strcpy(str,"Moedas(s) de R$");
    print(modeaCounter,str,Modeas);



    return 0;
}
