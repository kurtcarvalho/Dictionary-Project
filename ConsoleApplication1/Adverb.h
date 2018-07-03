#ifndef ADVERB_H
#define ADVERB_H

#include "Word.h"



class Adverb :
	virtual public Word{
private:
public:
	Adverb(string wordIn = "", string definition ="" , string type = "") : Word(wordIn , definition, type )
	{}
	

};

#endif
