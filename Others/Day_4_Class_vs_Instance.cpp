using namespace std;
#include <iostream>

class Person{
    public:
        int age;
        Person(int initialAge){
            if( initialAge < 0) {
                initialAge = 0;
                cout << "Age is not valid, setting age to 0." << endl;
            }
            age = initialAge;
        }
        // Do some computations in here and print out the correct statement to the console 
        void yearPasses();
        void amIOld(){
            if(age < 13) cout << "You are young." << endl;
            else if( age >= 13 && age < 18) cout << "You are a teenager." << endl;
            else cout << "You are old." << endl;
        }

    };

    void Person::yearPasses(){
        // Increment the age of the person in here
        age++;
    }

int main(){
    int t;
	int age;
    cin >> t;
    for(int i=0; i < t; i++) {
    	cin >> age;
        Person p(age);
        p.amIOld();
        for(int j=0; j < 3; j++) {
        	p.yearPasses(); 
        }
        p.amIOld();
      
		cout << '\n';
    }

    return 0;
}