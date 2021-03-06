#include<iostream>
#include<string>
#include<fstream>
#include "RabinKarp.h"
#include <chrono>
#include <thread>

using namespace std;
using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::cout;
using std::endl;

typedef std::chrono::steady_clock the_clock;

string readIntoFile() {
	string line;
	string txt = "";

	ifstream myFile("sampleQuad.txt");		//Open text file - (quad size file in this example)

	if (myFile.is_open()) {
		while (getline(myFile, line)) {
			txt += line;
		}

		myFile.close();
	}
	else {
		cout << "File not found.";
	}

	return txt;
}

int main() 
{
	ofstream myfile;
	myfile.open("outputRabinQuad1.txt");		//Open file to print output to

	for (int i = 0; i < 10; i++)		//For loop to run algorithm X times to find the mean result (10 times in this case)
	{
		string pat = "semper";			//The pattern wished to be searched for
		string txt = readIntoFile();
		RabinKarp searcher(pat);

		cout << "text:    " << txt << endl;
		// Start timing
		the_clock::time_point start = the_clock::now();

		vector<int> Occurence = searcher.search(txt);

		// Stop timing
		the_clock::time_point end = the_clock::now();

		if (Occurence.size() == 0) {		//provides not found message if the is no occurences
			cout << "Not Found" << endl;
		}
		else {
			cout << "Number of Occurences: " << Occurence.size() << endl;		//otherwise print the number of occurences
		}

		// Compute the difference between the two times in milliseconds
		auto time_taken = duration_cast<milliseconds>(end - start).count();

		myfile << time_taken << endl;
	}
	myfile.close();		//close output file once completed
	system("pause");
	return 0;
}