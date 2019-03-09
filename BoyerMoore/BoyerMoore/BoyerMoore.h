#pragma once

#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;


class BoyerMoore
{

private:
	vector<int> right;
	vector<int> Occurences;
	string pat;

public:
	BoyerMoore(string pat);
	~BoyerMoore();

	vector<int> search(string txt);
	

};

