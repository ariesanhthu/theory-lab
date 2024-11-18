#pragma once
#include <iostream>

using namespace std;

class ProgramFrame
{
public:
	virtual void startMessage(ostream&);
	virtual bool Check() = 0;
	virtual void Process() =0;
	virtual void Input(istream&) = 0;
	virtual void Output(ostream&) = 0;
	
	void errorMessage(ostream&);
	bool askContinue(istream&, ostream&);
	void run(istream&, ostream&);
};

