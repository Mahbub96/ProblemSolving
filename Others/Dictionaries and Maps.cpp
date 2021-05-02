#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    string name,num;
    cin >> n;
    map <string, string> pBook,phoneBook;
    for (int i = 0; i < n; i++) {
        cin >> name >> num;
        pBook[name] = num;
    }

    while (cin >> name) {
        
        if (pBook.find(name) != pBook.end()) {
            cout << name << "=" << pBook.find(name)->second << endl;
        } else {
            cout << "Not found" << endl;
        }
    }
    return 0;
}