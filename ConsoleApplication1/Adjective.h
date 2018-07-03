#ifndef ADJECTIVE_H
#define ADJECTIVE_H

#include "Word.h"

class Adjective : 
	virtual public Word{
private:
public:
	Adjective(string wordIn = "", string definition = "", string type = "") : Word(wordIn, definition, type)
	{}
};
	

#endif
