#include "matrix.h"

int main()
{
    vector<vector<int>> m1 = matrixInput(3, 1);
    // vector<vector<int>> m2 = matrixInput(3, 2);
    // vector<vector<int>> m3 = matrixMul(m1, m2);
    vector<vector<int>> m3 = transpose(m1);
    // vector<vector<int>> I = identityMatrix(3);

    show(m3);
    // showRec(m, 0, 0);
    return 0;
}