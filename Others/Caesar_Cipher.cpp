#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {
    k %= 26;
    
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += k;
            if(s[i] > 'Z'){
                int t = s[i] - 'Z';
                s[i] = 64 + t;
            } 
        }
        else if(s[i] >= 'a' && s[i] <= 'z') {
            /*we definitely need val variable because ASCII limit is 127*/
            int val = s[i];
            
            s[i] += k;
            val += k;
            if(val > 'z'){
                int t = val - 122;
                s[i] = 96 + t;
            } 
        }
    }  
    return s;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = caesarCipher(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
