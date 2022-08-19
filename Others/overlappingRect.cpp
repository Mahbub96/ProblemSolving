#include <iostream>

using namespace std;

int main()
{
    int a1, b1, a2, b2, a3, b3, a4, b4;

    cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3 >> a4 >> b4;

    int rightA1, rightB1, topA1, topB1, rightA2, rightB2, topA2, topB2;

    // find all points for first rect
    rightA1 = a2;
    rightB1 = b1;

    topA1 = a1;
    topB1 = b2;

    // find all points for second rect
    rightA2 = a4;
    rightB2 = b3;

    topA2 = a3;
    topB2 = b4;

    // find is overlapped or not
    int resX, resY;
    if ((max(a1, a2) <= min(rightA1, rightA2)) && (max(b1, b2) <= min(topB1, topB2)))
    {
        resX = min(rightA1, rightA2) - max(a1, a3);
        resY = min(b2, b4) - b1;

        cout << "Overlapped area : (" << resX << "*" << resY << ")\t" << resX * resY << endl;
        return 0;
    }

    return 0;
}