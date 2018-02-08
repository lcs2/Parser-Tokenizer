#pragma once
#include "stdafx.h"
using namespace std;



struct Token
{
	double val;
	char op;
	Token(double val, char op);
};

class Tokenizer
{
	string input;
	string tmp;
public:
	Tokenizer(string in);
	void tokenize(vector<Token*>& tokens);
};