#include "stdafx.h"
#include "ProperNoun.h"


ProperNoun::ProperNoun(string wordIn, string definition, string type)
{
	this->word = wordIn;
	this->definition = definition;
	this->type = type;
}

string ProperNoun::getWord() {
	string s = word;
	s[0] = toupper(s[0]);
	return s;
}


