#include "stdafx.h"
#include "Expression.h"


Atom::Atom(double v) : val(v) { }

double Atom::eval()
{
	return val;
}

BiOp::BiOp(char o, Exp* l, Exp* r) : op(o), left(l), right(r)
{
}

double BiOp::eval()
{
	switch (op)
	{
	case '+':
		return left->eval() + right->eval();
		break;
	case '-':
		return left->eval() - right->eval();
		break;
	case '*':
		return left->eval() * right->eval();
		break;
	case '/':
		return left->eval() / right->eval();
		break;
	}
}

