#ifndef PROPERNOUN_H
#define PROPERNOUN_H

#include "Noun.h"
#include <string>
#include <algorithm>

using namespace std;



class ProperNoun :
	virtual public Noun
{
public:
	ProperNoun(string wordIn = "", string definition = "", string type = "");
	string getWord();
	

};

#endif

