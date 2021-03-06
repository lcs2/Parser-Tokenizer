// Parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Expression.h"
#include "Tokenizer.h"
#include "Parse.h"

using namespace std;

int main()
{
	vector<Token*> tokens;

	string input;
	cin >> input;
	Tokenizer tk(input);
	tk.tokenize(tokens);
	tokens.push_back(new Token(0, '$'));
	Parser p(tokens);

	Exp* pp = p.Evaluate();
		cout << endl << "Wynik operacji: " << pp->eval() << endl;
	/*Exp* e = new Atom(5.123);
	Exp* e2 = new BiOp('+', new Atom(2), new Atom(2));
	cout << e->eval() << endl;
	cout << e2->eval() << endl;*/
		_getch();
    return 0;
}


