#include "BoyerMoore.h"

//Algorithm adapted by myself from the java version of Boyer Moore reference: Algorithms Fourth Edition - Robert Sedgewick | Kevin Wayne

BoyerMoore::BoyerMoore(string pat)
{
	this->pat = pat;
	int M = pat.length();
	int R = 256;

	for (int c = 0; c < R; c++)
	{
		right.push_back(c);
	}

	for (int j = 0; j < M; j++)
	{
		right[(int)pat.at(j)] = j;
	}
}


BoyerMoore::~BoyerMoore()
{
}

vector<int> BoyerMoore::search(string txt)
{
	int N = txt.length();		//length of the text
	int M = pat.length();		//length of the pattern/searched string
	int skip;

	for (int i = 0; i <= N-M; i += skip)
	{
		skip = 0;
		for (int j = M - 1; j >= 0; j--)
		{
			if (pat.at(j) != txt.at(i + j))
			{
				skip = j - right[(int)txt.at(i + j)];
				if (skip < 1)
				{
					skip = 1;
					break;
				}
			}
		}
		if (skip == 0)
		{
			skip++;
			Occurences.push_back(i);
		}
	}

	return Occurences;
}