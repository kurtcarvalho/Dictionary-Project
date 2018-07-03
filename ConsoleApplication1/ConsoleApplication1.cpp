// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Verb.h"
#include "Word.h"
#include "Noun.h"
#include "Dictionary.h"


int main()
{
	Dictionary mydictionary;
	mydictionary.loadDictionary();
	mydictionary.getOption();
    return 0;
}

