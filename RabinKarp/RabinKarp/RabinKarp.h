#pragma once
#include<string>
#include<vector>

using std::string;
using std::vector;

class RabinKarp
{
public:
	RabinKarp(string pat);
	bool check(string txt,int i);
	long hash(string key, int M);
	vector<int> search(string txt);
	~RabinKarp();

	vector<int> Occurence;
private:
	long patHash;
	int M;
	long Q;
	const int R = 256;
	long RM;
	string pat;
};

