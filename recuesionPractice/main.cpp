#include <iostream>
#include <vector>

using namespace std;

void generate(vector<int> &sub, int i, vector<int> &v)
{
    if (i == v.size())
        return;
    generate(sub,i+1,v);
    
}

int main()
{
    vector<int> v;
    vector<int> sub;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    generate(sub, 0, v);

    for (int i = 0; i < n; i++)
    {
        cout << sub[i] << " ";
    }
}