
#ifndef VERB_H
#define VERB_H


#include "Word.h"
#include <string>

using namespace std;

class Verb : virtual public Word {
private:
public:
	Verb(string wordIn = "", string definition = "", string type = "") : Word(wordIn , definition , type )
	{}
	bool isVerb();
	
	
};


#endif