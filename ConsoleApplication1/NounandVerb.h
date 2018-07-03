
#ifndef NOUNANDVERB_H
#define NOUNANDVERB_H

#include "Noun.h"
#include "Verb.h"


class NounandVerb : public Noun, public Verb
{
public:
	NounandVerb(string wordIn = "", string defintion = "", string type = "");
	bool isNoun();
	bool isVerb();
};

#endif