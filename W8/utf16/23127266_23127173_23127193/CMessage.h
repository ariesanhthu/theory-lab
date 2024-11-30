#pragma once

#include "CDate.h"
#include "CTime.h"
#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

using namespace std;
using namespace utils;


class CMessage {
private: 
	wstring mNumber;
	UINT16 mVote; 
	CDate mDate;
	CTime mTime;
public: 
	CMessage() = default;
	CMessage(wstring mNumber, UINT16 mVote, CDate mDate, CTime mTime) {
		this->mNumber = mNumber;
		this->mVote = mVote;
		this->mDate = mDate;
		this->mTime = mTime;
	}

	void finput(wistream &in);
	void foutput(wostream &out);
};

