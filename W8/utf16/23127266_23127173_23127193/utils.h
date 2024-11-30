#pragma once
#include <fstream>
#include <iostream>

using namespace std;
typedef unsigned short UINT16;
typedef unsigned char UINT8;

namespace utils {
	static const UINT8 UTF8_FLAG[] = { 0xef, 0xbb, 0xbf };
	static const UINT8 UNICODE_FLAG[]{ 0xff, 0xfe };
	static const UINT16 UTF8_CodePg = 65001;
	enum {
		ANSI_TXT, 
		UNICODE_TXT, 
		UTF8_TXT, 
		OTHER_FILE
	};
	static string filetype[] = {
		"ANSI text file",
		"UNICODE text file",
		"UTF 8 text file",
		"other file"
	};

	inline bool isExistFile(const char* filename) {
		wifstream f(filename);
		return f.good();
	}

	inline wstring customGetline(wistream& in) {
		wstring line;
		wchar_t ch;

		while (in.get(ch)) {
			if (ch == L'\n') break;
			if (ch == L'\r') {
				if (in.peek() == L'\n') in.get();
				break;
			}
			line += ch;
		}

		return line;
	}
};

