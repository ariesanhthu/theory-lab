#pragma once

typedef unsigned short UINT16;


class CDate {
private: 
	UINT16 m, d, y;
public:
	CDate() = default;
	CDate(UINT16 m, UINT16 d, UINT16 y) {
		this->m = m; 
		this->d = d;
		this->y = y;
	}
	UINT16 getD() const { return d; }
	UINT16 getM() const { return m; }
	UINT16 getY() const { return y; }

	void setD(UINT16 d) { this->d = d; }
	void setM(UINT16 m) { this->m = m; }
	void setY(UINT16 y) { this->y = y; }
};

