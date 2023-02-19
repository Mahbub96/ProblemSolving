#include <iostream>
using namespace std;
class MyArr
{
public:
    int pos, value;
};

int findDistance(MyArr arr[], int &s)
{
    int sum = 0;
    for (int i = 0; i < s - 1; i++)
    {
        sum += abs(arr[i].value - arr[i + 1].value);
    }
    return sum;
}

int main()
{
    int l;
    std::cin >> l;
    MyArr arr[l];
    for (int i = 0; i < l; i++)
    {
        std::cin >> arr[i].value;
        arr[i].pos = i;
    }

    int d = findDistance(arr, l);

    /* partially sort values */
    for (int i = 0; i < l - 1; i++)
    {
        if (arr[i].value > arr[i + 1].value && (arr[i].pos + 1 == i + 1 || arr[i].pos - 1 == i - 1 || arr[i].pos == i))
        {
            MyArr temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    int d1 = findDistance(arr, l);
    for (size_t i = 0; i < l; i++)
    {
        cout << arr[i].value << " ";
    }

    std::cout << std::min(d, d1);

    return 0;
}