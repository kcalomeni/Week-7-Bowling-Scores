// Week7BowlingScores.cpp : This program calculates a bowling league's average bowling scores.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// Create a structure for each bowler in the league.
struct Bowler {
	string name;
	int scores[5]{};
	int averageScore{};
};

// List the prototypes of each function.
bool GetBowlingData(const string& fileName, Bowler bowlers[], int& count);
void GetAverageScore(Bowler bowlers[], int count);
void PrettyPrintResults(Bowler bowlers[], int count);

int main() {
	// Declare the variables.
	int count = 0;

	// Call the functions and define the file name.
	string fileName = "BowlingScores.txt";
	Bowler bowlers[100];

	// Set a precision to use for formatting output operations.
	cout << setprecision(2) << fixed << showpoint;

	// Define functions in our main().
	if (GetBowlingData(fileName, bowlers, count)) {
		GetAverageScore(bowlers, count);
		PrettyPrintResults(bowlers, count);
	}

	// If file cannot be opened, print a statement.
	else {
		cout << "\nError, file cannot be opened or found. Try again." << endl;
	}
	return 0;

	// Call GetBowlingData to be able to read the text file BowlingScores.txt.
	bool GetBowlingData(const string & fileName, Bowler bowlers[], int& count); {

		// Create an input stream for our given data file.
		ifstream dataInput;

		// Open our input file for the data.
		dataInput.open(fileName.c_str());

		// To see whether the file is valid or not.
		if (dataInput.fail()) {
			return false;
		}
		else {
			while (dataInput >> bowlers[count].name) {
				for (int& score : bowlers[count].scores) {
					dataInput >> score;
				}
				count++;
			}

			// To close our input file.
			dataInput.close();

		}
		return true;


	}
}

bool GetBowlingData(const string& fileName, Bowler bowlers[], int& count)
{
	return false;
}

// GetAverageScore to calculate the average bowling scores.
void GetAverageScore(Bowler bowlers[], int count) {
	double total;

	// Create a for loop to show all the scores of each bowler.
	for (int i = 0; i < count; i++) {
		total = 0;
		for (int score : bowlers[i].scores) {
			total += score;
		}

		// To calculate the average.
		bowlers[i].averageScore = (int)(total / 5);
	}

}

// Use PrettyPrintResults to display the file output.
void PrettyPrintResults(Bowler bowlers[], int count) {

	// Create a header to display for program output.
	cout << setw(10) << left << "Name" << setw(6) << left << "S1" << setw(8) << left << "S2";
	cout << setw(8) << left << "S3" << setw(6) << left << "S4" << setw(6) << left << "Average" << endl;
	cout << setw(10) << left << "----" << setw(6) << left << "----" << setw(8) << left << "----";
	cout << setw(8) << left << "----" << setw(6) << left << "----" << setw(6) << left << "----" << endl;


	// Have our for loop print all the names and scores of the bowlers.
	for (int i = 0; i < count; i++) {
		cout << setw(10) << left << bowlers[i].name;
		for (int score : bowlers[i].scores) {
			cout << score << "\t";
		}

		// Display the average of every bowler
		cout << setw(5) << bowlers[i].averageScore << endl;
	}
}

