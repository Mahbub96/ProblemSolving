// Incomplete project
#include <iostream>
#include <unistd.h>

using namespace std;

class Box
{
    int max_X_length;
    int max_Y_length;
    float angle;
    int **matrixs;

public:
    Box(int x, int y)
    {
        max_X_length = x;
        max_Y_length = y;
        angle = 0;
        generateMatrix();
    }
    void generateMatrix()
    {
        matrixs = new int *[max_X_length];

        for (int i = 0; i < max_X_length; i++)
        {
            matrixs[i] = new int[max_Y_length];

            /* code */

            for (int j = 0; j < max_Y_length; j++)
            {
                if (j == 0 || (j + 1 == max_Y_length))
                {
                    matrixs[i][j] = 1;
                }
                else if (i == 0 || (i + 1 == max_X_length))
                {
                    matrixs[i][j] = 1;
                }
                else
                    matrixs[i][j] = 0;
            }
        }
    }

    void printMatrix()
    {
        for (size_t i = 0; i < max_X_length; i++)
        {
            for (size_t j = 0; j < max_Y_length; j++)
            {
                cout << matrixs[i][j];
            }
            cout << endl;
        }
    }
    void print()
    {
        for (int i = 0; i < max_X_length; i++)
        {
            /* code */

            for (int j = 0; j < max_Y_length; j++)
            {
                if (i == 0 || (i + 1 == max_X_length))
                {
                    cout << '-';
                }
                else if (j == 0 || (j + 1 == max_Y_length))
                {
                    cout << '|';
                }

                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Box b(4, 4);
    b.print();
    b.printMatrix();
}