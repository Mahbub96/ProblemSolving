#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int i = 4;
    double d = 4.0;
    string s = "HackerRank ";
    
    
    // Declare second integer, double, and String variables.
  
    int newI;
    double newD;
    string newS;
        
    // Read and save an integer, double, and String to your variables.
    cin >> newI;
    cin >> newD;
    cin.ignore();
    getline(cin,newS);
    // Note: If you have trouble reading the entire string, please go back and review the Tutorial closely.
    
    // Print the sum of both integer variables on a new line.
    cout << i+newI << endl;
    
    // Print the sum of the double variables on a new line.
    cout << d+newD << endl;
    // Concatenate and print the String variables on a new line
    cout << s+newS << endl;
    // The 's' variable above should be printed first.

    return 0;
}