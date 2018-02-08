#pragma once
#include "stdafx.h"

class Exp
{
public:
	virtual double eval() = 0;
};

class Atom : public Exp
{
	double val;
public:
	Atom(double v);
	double eval();
};

class BiOp : public Exp
{
	Exp* left, *right;
	char op;
public:
	BiOp(char o, Exp* l, Exp* r);
	virtual double eval();
};