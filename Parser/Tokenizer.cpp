#include "stdafx.h"
#include "Tokenizer.h"

//////////////////////////////////// TOKEN
Token::Token(double val, char op = 'N') : val(val), op(op)
{
	// cout << "nowy token o wartosci " << val << ". operator: " << op << endl;
}

//////////////////////////////////// TOKENIZER
Tokenizer::Tokenizer(string in) : input(in), tmp("")
{
}

////////////////////////////////////
void Tokenizer::tokenize(vector<Token*>& tokens)
{
	for (int i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]) || input[i] == '.')
		{
			while (isdigit(input[i]) || input[i] == '.')
			{
				tmp += input[i++];
			}
			tokens.push_back(new Token(strtod(tmp.c_str(), NULL), 'N'));
			tmp.clear();
		}

		if (input[i] == '+' ||
			input[i] == '-' ||
			input[i] == '*' ||
			input[i] == '/' ||
			input[i] == '(' ||
			input[i] == ')')
		{
			tmp = input[i];
			tokens.push_back(new Token(0, tmp[0]));
			tmp.clear();
		}
	}
}