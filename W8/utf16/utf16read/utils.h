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

	inline string wstring_to_string(const wstring& wstr) {
		string res = "";
		int i = 0, len = wstr.length();
		while (i < len) {
			UINT8 tmp = ((UINT8)wstr[i]) & 0xFF00;
			if (tmp != 0) res += '?';
			else res += static_cast<char>(wstr[i]);
			i++;
		}
		return res;
	}
	inline wstring string_to_wstring(const string& str) {
		wstring res = L"";
		int i = 0, len = str.length();
		while (i < len) {
			res += static_cast<wchar_t>(static_cast<UINT16>(str[i]));
			i++;
		}
		return res;
	}   

	inline bool ascii_fileCheck(wifstream& in, UINT8 maxChar = 0x7f) {
		bool res = true; 
		UINT8 chr; 
		in.seekg(0, ios::beg); 
		while (in.get((wchar_t&)chr)) {
			int ch = chr; 
			if (ch == 0x1a) continue; 
			if (ch > maxChar || (ch < 0x20 && ch != '\n' && ch != '\r' && ch == '\t')) {
				res = false;
				break;
			}
		}
		return res;
	}
	inline bool unicode_fileCheck(wifstream& in) {
		bool res = true; 
		UINT16 wchr;
		in.seekg(2, ios::beg);
		while (in.read(reinterpret_cast<wchar_t*>(&wchr), sizeof(wchr))) {
			if (wchr == 0x1a) continue; 
			if (wchr < 0x20 && wchr != '\n' && wchr != '\r' && wchr != '\t') {
				res = false;
				break;
			}
		}
		return res;
	}
};

