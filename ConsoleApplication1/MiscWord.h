#ifndef MISCWORD_H
#define MISCWORD_H

#include "Word.h"

class MiscWord : 
	virtual public Word{
private:
public:
	MiscWord(string wordIn = "", string definition = "", string type = "") : Word(wordIn, definition, type)
	{}
	
};

#endif
