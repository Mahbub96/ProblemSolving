#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n, m;
        std::cin >> n >> m;

        bool isPositive = true;
        int res = 0;

        for (int j = 0; j < n; j++)
        {
            if ((j % m) == 0)
            {
                isPositive = !isPositive;
            }
            if (isPositive)
            {
                res += j + 1;
            }
            else
            {
                res -= j + 1;
            }
        }
        std::cout << "Case " << i + 1 << ": " << res << std::endl;
    }

    return 0;
}