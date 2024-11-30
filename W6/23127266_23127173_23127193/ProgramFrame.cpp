#include "ProgramFrame.h"
//
#include <iostream>

void ProgramFrame::startMessage(ostream& os) {
	os << "Bat dau nhap du lieu: ";
}

void ProgramFrame::errorMessage(ostream& os)
{
	os << "Nhap du lieu loi!" << endl;
}
bool ProgramFrame::askContinue(istream& is, ostream& os)
{
	os << "Nhan y de tiep tuc, hoac nhap bat ky ky tu nao de thoat: ";

	char ch; 
	is >> ch;

	return (ch == 'Y' || ch == 'y');
}

void ProgramFrame::run(istream& is, ostream& os) {
	bool b;
	do {
		startMessage(os);
		Input(is);
		if (!Check())
		{
			errorMessage(os);
			continue;
		}
		Process();
		Output(os);
		b = askContinue(is, os);
	} while (b);
}