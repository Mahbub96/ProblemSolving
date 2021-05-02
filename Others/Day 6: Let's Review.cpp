#include <iostream>
#include <string>
using namespace std;
class Separation{
public:
    string s;
    Separation(string str){
        s = str;
    }
    void evenOddSeparator(){
        string even,odd;
        for (int i = 0; i < s.size(); i++)
        {
            
            if(i%2) odd.push_back(s[i]);
            else even.push_back(s[i]);
        }
        cout << even << " " << odd << endl;
        
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++)
    {
        string str;
        getline(cin,str);
        Separation s(str);
        s.evenOddSeparator();
    }
       
    return 0;
}
