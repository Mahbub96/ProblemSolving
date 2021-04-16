#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){

    string str,str1;
    cin >> str;
    str1 = str;
    reverse(str.begin(),str.end());

    if(str == str1) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;


    return 0;
}