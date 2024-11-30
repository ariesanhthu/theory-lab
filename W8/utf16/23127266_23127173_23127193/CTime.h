#pragma once

#include "utils.h"

class CTime {
private:
	UINT16 h, m, s;
public:
	CTime() = default;
	CTime(UINT16 h, UINT16 m, UINT16 s) {
		this->h = h;
		this->m = m;
		this->s = s;
	}
	UINT16 getH() const { return h; }
	UINT16 getM() const { return m; }
	UINT16 getS() const { return s; }
	void setH(UINT16 h) { this->h = h; }
	void setM(UINT16 m) { this->m = m; }
	void setS(UINT16 s) { this->s = s; }
};

