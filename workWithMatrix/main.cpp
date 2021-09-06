#include "matrix.h"

int main()
{
    vector<vector<int>> m1 = matrixInput(3, 3);
    // vector<vector<int>> m2 = matrixInput(2, 2);
    vector<vector<int>> I = identityMatrix(3);
    vector<vector<int>> m3 = matrixMul(m1, I);
    // vector<vector<int>> m3 = transpose(m1);

    show(m3);
    cout << endl;
    showRec(m3, 0, 0);
    return 0;
}