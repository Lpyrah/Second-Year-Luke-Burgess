#include "RabinKarp.h"
#include<iostream>

using namespace std;

//Algorithm adapted by myself from the java version of Rabin Karp reference: Algorithms Fourth Edition - Robert Sedgewick | Kevin Wayne

RabinKarp::RabinKarp(string pat)
{
	this->pat = pat;
	this->M = pat.length();
	Q = 1009;
	RM = 1;
	for (int i = 1; i <= M - 1; i++) {
		RM = (R * RM) % Q;
	}

	patHash = hash(pat, M);
}

bool RabinKarp::check(string txt, int i) {
	/*return true;*/

	for (int j = 0; j < M; j++) {
		if (pat.at(j) != txt.at(i + j)) {
			return false;
		}
	}

	return true;
}

long RabinKarp::hash(string key, int M) {
	long h = 0;
	for (int j = 0; j < M; j++) {
		h = (R * h + key.at(j)) % Q;
	}

	return h;
}

vector<int> RabinKarp::search(string txt) {
	int N = txt.length();
	long txtHash = hash(txt, M);
	if (patHash == txtHash && check(txt,0)) {
		Occurence.push_back(1);
	}

	for (int i = M; i < N; i++) {
		txtHash = (txtHash + Q - RM * txt.at(i - M) % Q) % Q;
		txtHash = (txtHash * R + txt.at(i)) % Q;
	
		int offset = i - M + 1;
		if ((patHash == txtHash) && check(txt, offset)) {
			Occurence.push_back(offset);
		}
	}

	return Occurence;
}

RabinKarp::~RabinKarp()
{
}
