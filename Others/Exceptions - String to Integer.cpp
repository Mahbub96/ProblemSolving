#include <iostream>

using namespace std;

void check(string s){
    int n;
    try{
        n = stoi(s);
    }catch(exception e){
        cout << "Bad String" <<  endl;
        return;
    }

    cout << n << endl;

}
int main(){
    string str;
    cin >> str;
    check(str);
    return 0;
}