
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Global Variables*/
int fruits = 0;
vector<int> f;
bool reachedDestination = false;

/*functions*/
void haveFruits(vector<vector<char>> &map, int x, int y)
{
    if (map[x][y] == 'f')
        ++fruits;
}
void destination()
{
    reachedDestination = true;
    f.push_back(fruits);
    fruits = 0;
}
int isSafe(vector<vector<char>> &map, int x, int y)
{

    if (map.size() > x && map.size() > y && map[x][y] != 'r')
        return 1;

    return 0;
}

void ratAndMage(vector<vector<char>> &map, int x, int y)
{

    haveFruits(map, x, y);

    if (x + 1 == map.size() && y + 1 == map.size()) // For findling End position
        destination();

    if (isSafe(map, x, y + 1))
        ratAndMage(map, x, ++y);
    if (isSafe(map, x + 1, y))
        ratAndMage(map, ++x, y);
}

int main()
{
    int times;
    cin >> times;

    while (times--)
    {
        int n;
        cin >> n;

        vector<vector<char>> roadMap(n);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                char temp;
                cin >> temp;
                roadMap[i].push_back(temp);
            }

        ratAndMage(roadMap, 0, 0);
        if (!reachedDestination)
            cout << "-1" << endl;
        else
        {
            sort(f.begin(), f.end());
            int Fruits = f[f.size() - 1];
            int ways = 0;
            /*for path finding */
            for (int i = f.size() - 1; i >= 0; i++)
            {

                if (f[i] != Fruits)
                    break;
                ++ways;
            }

            cout << Fruits << ' ' << ways << endl;
        }
        reachedDestination = false;
        f.erase(f.begin(), f.end());
    }
    return 0;
}
