#include "CMessage.h"

//wstring dummyMessage = L"1234567890\n7\n10/03/2014\n18:20:22\n";
using namespace std;

void CMessage::foutput(wostream& out) {
    const wchar_t bom = 0xFEFF;
    out.write(reinterpret_cast<const wchar_t*>(&bom), 1);

    out << mNumber << " ";
    out << mVote << " ";
    out << mDate.getD() << L"/" << mDate.getM() << L"/" << mDate.getY() << " ";
    out << mTime.getH() << L":" << mTime.getM() << L":" << mTime.getS() << " ";
}

void CMessage::finput(std::wistream& in) {
    wchar_t bom;
    in.read(reinterpret_cast<wchar_t*>(&bom), 1);
    if (bom != 0xFEFF) {
        std::wcerr << L"Invalid or missing BOM in UTF-16 file" << "\n";
        return;
    } 

    wstring number;
    //getline(in, number, L'\n');
    number = utils::customGetline(in);
    this->mNumber = number;
    wcout << number << " ";

    UINT16 vote;
    in >> vote;
    this->mVote = vote;
    wcout << vote << " ";

    wstring line;
    wchar_t tmp;

    //getline(in, line);
    line = utils::customGetline(in);
    UINT16 day, month, year;
    in >> day >> tmp >> month >> tmp >> year;
    this->mDate.setD(day);
    this->mDate.setM(month);
    this->mDate.setY(year);
    wcout << day << L"/" << month << L"/" << year << " ";

    //std::getline(in, line);
    line = utils::customGetline(in);
    UINT16 hour, minute, second;
    in >> hour >> tmp >> minute >> tmp >> second;
    this->mTime.setH(hour);
    this->mTime.setM(minute);
    this->mTime.setS(second);
    wcout << hour << L":" << minute << L":" << second << " ";
}