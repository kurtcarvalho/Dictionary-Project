#ifndef PREPOSITION_H
#define PREPOSITION_H

#include "MiscWord.h"
class Preposition :
	public MiscWord
{
public:
	Preposition(string wordIn = "", string definition = "", string type = "") : Word(wordIn, definition, type)
	{}
	
};
#endif
