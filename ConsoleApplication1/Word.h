//Word.h

#ifndef WORD_H
#define WORD_H

#include "stdafx.h"
#include <string>
#include <algorithm>

using namespace std;

class Word {
protected:
	string word;
	string definition;
	string type;
public:
	Word(string wordIn = "", string definition = "", string type = "") {
		this->word = wordIn;
		this->definition = definition;
		this->type = type;
	}
	void setWord(string wordIn);
	void setDefinition(string definition);
	void setType(string type);
	virtual string getWord();
	string getDefinition();
	string getType();
	virtual bool isNoun();
	virtual bool isVerb();
	bool isPalindrome();

};
#endif