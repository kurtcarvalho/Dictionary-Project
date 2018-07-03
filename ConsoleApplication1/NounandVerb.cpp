#include "stdafx.h"
#include "NounandVerb.h"





NounandVerb::NounandVerb(string wordIn, string defintion, string type)
{
	this->word = wordIn;
	this->definition = definition;
	this->type = type;
}

bool NounandVerb::isNoun()
{
	return true;
}

bool NounandVerb::isVerb()
{
	return true;
}
