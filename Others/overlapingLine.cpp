#include <iostream>

using namespace std;

int main()
{

    int a1, a2, b1, b2;

    cin >> a1 >> b1 >> a2 >> b2;
    bool isOverlapped = false;

    // overlapping condition for point a2
    if (a1 <= a2 && b1 >= a2)
    {
        isOverlapped = true;
    }

    // overlapping condition for point b2
    else if (a1 <= b2 && b1 >= b2)
    {
        isOverlapped = true;
    }

    // overlapping condition for point a1
    else if (a2 <= a1 && b2 >= a1)
    {
        isOverlapped = true;
    }

    // overlapping condition for point b1
    else if (a2 <= b1 && b2 >= b1)
    {
        isOverlapped = true;
    }

    if (isOverlapped)
    {
        cout << "Overlapped " << endl;
    }
    else
    {
        cout << "No overlapping " << endl;
    }

    return 0;
}
