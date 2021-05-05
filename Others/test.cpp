#include <iostream>

using namespace std;

class SubDomain{
    public : 
    int subMatrix(
        int a,int b,int c,
        int e,
        int g,int h,int i
        ){
        
        int subDomain[3][3]= 
        {
            a,b,c,
            0,e,0,
            g,h,i       
        };
        return a+b+c+e+g+h+i;
    }
    
};


class Domain
{
    public :
    int domain[6][6];
    Domain()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int tempInp;
                cin >> tempInp;
                domain[i][j] = tempInp;
            }
            
        }
    }

    int maxOutput(SubDomain A){

        int maxValue = 0;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   // First row first col value
                maxValue = A.subMatrix(i,i+1,i+2,i,j,j+1,j+2);
                maxValue = max(maxValue,maxValue);
            }
            
        }
        return maxValue;
    }
};


int main(){
/*
    1 0 1 0 1 0
    0 1 0 1 0 1
    1 0 1 0 1 0
    0 1 0 1 0 1
    1 0 1 0 1 0
    0 1 0 1 0 1
*/
/*
    1 1 1
    0 1 0 
    1 0 1
*/
    Domain ob1;
    SubDomain A;

    cout << ob1.maxOutput(A);
    

     

    return 0;
}