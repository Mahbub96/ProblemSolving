#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */
string timeConversion(string s) {
    if(s[8] == 'A'){
        string newS = s.substr(0,2);
        int n = stoi(newS);
        if(n == 12){
            n = 0;
            newS = to_string(n);
            s[0] = newS[0];
            s[1] = '0';
        }
        return s.substr(0,8);
    }
    string newS = s.substr(0,2);
    int n = stoi(newS);
    n += 12;
    if(n > 23){
        n = 12;
        newS = to_string(n);
        s[0] = newS[0];
        s[1] = newS[1];
    } 
    else {
        newS = to_string(n);
        s[0] = newS[0];
        s[1] = newS[1];
    }

    return s.substr(0,8);
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    cout << result << "\n";

    // fout.close();

    return 0;
}
