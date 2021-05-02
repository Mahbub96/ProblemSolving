#include <iostream>
#include <vector>

using namespace std;


class Person{
	protected:
		string firstName;
		string lastName;
		int id;
	public:
		Person(string firstName, string lastName, int identification){
			this->firstName = firstName;
			this->lastName = lastName;
			this->id = identification;
		}
		void printPerson(){
			cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n"; 
		}
	
};

class Student :  public Person{
	private:
		vector<int> testScores;  
	public:
    
        /*	
        *   Class Constructor
        *   
        *   Parameters:
        *   firstName - A string denoting the Person's first name.
        *   lastName - A string denoting the Person's last name.
        *   id - An integer denoting the Person's ID number.
        *   scores - An array of integers denoting the Person's test scores.
        */
        // Write your constructor here
        Student(string firstName, string lastName, int identification,vector<int> testScore):Person(firstName, lastName, identification){
			this->testScores = testScore;
            
            if(firstName.size()  > 10 || lastName.size() > 10 ) exit(1);
            else if(identification > 9999999 || identification < 1000000) exit(1);
            
		}
        
        
        /*	
        *   Function Name: calculate
        *   Return: A character denoting the grade.
        */
        // Write your function here
        char calculate(){
            int AvgScore = 0;
            int size = testScores.size();
            while (testScores.size()) {
                if(testScores.back() < 0 || testScores.back() > 100) exit(1);
                AvgScore += testScores.back();
                testScores.pop_back();
            }

            AvgScore /= size;

            if(100 >= AvgScore && 90 <= AvgScore) return 'O';
            else if(90 > AvgScore && 80 <= AvgScore) return 'E';
            else if(80 > AvgScore && 70 <= AvgScore) return 'A';
            else if(70 > AvgScore && 55 <= AvgScore) return 'P';
            else if(55 > AvgScore && 40 <= AvgScore) return 'D';
            else if(40 > AvgScore) return 'T';

            return 'x';
           
        }
};



int main() {
	string firstName;
  	string lastName;
	int id;
  	int numScores;
	cin >> firstName >> lastName >> id >> numScores;

  	vector<int> scores;
  	for(int i = 0; i < numScores; i++){
	  	int tmpScore;
	  	cin >> tmpScore;
		scores.push_back(tmpScore);
	}

	Student* s = new Student(firstName, lastName, id, scores);

	s->printPerson();

	cout << "Grade: " << s->calculate() << "\n";

	return 0;
}