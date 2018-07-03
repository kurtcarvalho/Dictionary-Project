#ifndef DICTIONARY_H
#define DICTIONARY_H



#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Word.h"
#include "Noun.h"
#include "Verb.h"
#include "NounandVerb.h"
#include "Adverb.h"
#include "Adjective.h"
#include "MiscWord.h"
#include "Preposition.h"
#include "ProperNoun.h"
#include <algorithm>
#include <cctype>
#include <ctime>
#include <string>

using namespace std;


class Dictionary
{
protected:
	vector <Word*> thedictionary;
	string filename = "dictionary.txt";
	int TotalNumberOfWords = 0;
public:
	void loadDictionary();
	int getTotalNumberOfWords();
	void getOption();
	void findWord();
	void search();
	void QUsearch();
	void findPalindrome();
	void isNounandVerb();
	void guessingGame();
	void findAnagrams();
	~Dictionary();
	
};
#endif
