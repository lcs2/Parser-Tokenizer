#include "stdafx.h"
#include "Expression.h"
#include "Parse.h"

Parser::Parser(vector<Token*> t) : tokens(t), i(0)
{
}

Exp* Parser::ParseAtom()
{
	cout << "ParseAtom()" << endl;
	return new Atom(tokens[i++]->val);
}

Exp* Parser::ParseParantheses()
{
	cout << "ParseParentheses()" << endl;
	char op = tokens[i]->op;
	if (op != '(')
		return ParseAtom();
	i++;
	Exp* inside = ParseSumands();
	i++;
	return inside;
}

Exp* Parser::ParseFactors()
{
	cout << "ParseFactors()" << endl;
	Exp* num1 = ParseParantheses();
	while (1)
	{
		char op = tokens[i]->op;
		if (op != '*' && op != '/')
			return num1;
		i++;
		num1 = new BiOp(op, num1, ParseParantheses());
	}
}

Exp* Parser::ParseSumands()
{
	cout << "ParseSumands()" << endl;
	Exp* num1 = ParseFactors();
	while (1)
	{
		char op = tokens[i]->op;
		if (op != '+' && op != '-')
			return num1;
		i++;
		num1 = new BiOp(op, num1, ParseFactors());
	}
}

Exp* Parser::Evaluate()
{
	cout << "Evaluate()" << endl;
	Exp* e = ParseSumands();
	return e;
}