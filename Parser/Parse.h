#pragma once
#include "stdafx.h"
#include "Tokenizer.h"

class Parser
{
	int i;
	vector<Token*> tokens;
public:
	Parser(vector<Token*> t);

	Exp* ParseAtom();
	Exp* ParseParantheses();
	Exp* ParseFactors();
	Exp* ParseSumands();
	Exp* Evaluate();
};