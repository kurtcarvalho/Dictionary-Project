#include "stdafx.h"
#include "Word.h"

	


//Word::Word(string wordIn, string definition, string type) {}

void Word::setWord(string wordIn) {
	word = wordIn;
}
void Word::setDefinition(string definition) {
	definition = definition;
}

void Word::setType(string definition) {
	type = type;
}

string Word::getWord() {
	return word;
}

string Word::getDefinition()
{
	return definition;
}

string Word::getType()
{
	return type;
}

bool Word::isNoun()
{
	return false;
}

bool Word::isVerb()
{
	return false;
}

bool Word::isPalindrome()
{
	string bword = getWord();
	string fword = getWord();
	int n = fword.length();

	// Swap character starting from two
	// corners
	for (int i = 0; i < n / 2; i++) {
		swap(fword[i], fword[n - i - 1]);
	}

	if (n > 1) {
		if (bword == fword)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}

}






