#include "matrix.h"

int main()
{
    vector<vector<int>> m1 = matrixInput(3, 3);
    vector<vector<int>> m2 = matrixInput(3, 1);
    vector<vector<int>> m3 = matrixMul(m1, m2);

    show(m3);
    // showRec(m, 0, 0);
    return 0;
}