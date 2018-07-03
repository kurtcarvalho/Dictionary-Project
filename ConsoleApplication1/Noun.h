
#ifndef NOUN_H
#define NOUN_H

#include "Word.h"

class Noun : virtual public Word {
private:
public:
	Noun(string wordIn = "", string definition = "", string type = "") : Word(wordIn, definition, type ){}
	bool isNoun();
	

};

#endif
