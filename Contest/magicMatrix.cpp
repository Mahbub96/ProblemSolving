#include <iostream>
#include <vector>

using namespace std;

void printArray(vector<vector<int>> &v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j]<<",";
        }
        cout << endl;
        
    }
    
}


void fixDiagonal(int row,int col,vector<vector<int>> &v,int d[]){
    for (int i = 0; i < 4; i++)
    {
        if(v[row][col] == d[i]){
            v[2-row][2-col] = d[3-i];
            d[i] = -1;
            d[3-i] = -1;
        }
    }
    
}

void fixBetween(vector<vector<int>> &v){
    v[0][1] = 15 - v[0][0] - v[0][2];
    v[1][0] = 15 - v[0][0] - v[2][0];
    v[1][2] = 15 - v[0][2] - v[2][2];
    v[2][1] = 15 - v[2][0] - v[2][2];
}

int findDistance(vector<vector<int>> init,vector<vector<int>> &newInp){
    int d = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            d += abs(init[i][j] - newInp[i][j]);
        }
        
    }
    return d;
    
}

int main(){
    int diagonals[] = {2,4,6,8};

    vector<vector<int>> v(3),initialInp(3);


    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int temp;
            cin >> temp;
            v[i].push_back(temp);
        }
        
    }

    initialInp = v;
    // printArray(v);

    if(v[1][1] != 5)  v[1][1] = 5;  

    for (int i = 0; i < 3; i+=2)
    {
        for (int j = 0; j < 3; j+=2)
        {
            fixDiagonal(i,j,v,diagonals);
        }
        
    }
   
    
    fixBetween(v);
    printArray(v);

    cout << findDistance(initialInp,v);
    



    return 0;
}