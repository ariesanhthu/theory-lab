#include "CMessage.h"

//wstring dummyMessage = L"1234567890\n7\n10/03/2014\n18:20:22\n";

void CMessage::foutput(std::wostream& out) {
    const wchar_t bom = 0xFEFF;
    out.write(reinterpret_cast<const wchar_t*>(&bom), 1);

    out << mNumber << endl;
    out << mVote << endl;
    out << mDate.getD() << L"/" << mDate.getM() << L"/" << mDate.getY() << endl;
    out << mTime.getH() << L":" << mTime.getM() << L":" << mTime.getS() << endl;
}

void CMessage::finput(std::wistream& in) {
    wchar_t bom;
    in.read(reinterpret_cast<wchar_t*>(&bom), 1);
    if (bom != 0xFEFF) {
        std::wcerr << L"Invalid or missing BOM in UTF-16 file" << std::endl;
        return;
    } 

    std::wstring number;
    //getline(in, number, L'\n');
    number = utils::customGetline(in);
    this->mNumber = number;
    wcout << L"mNumber: " << number << "\n";

    UINT16 vote;
    in >> vote;
    this->mVote = vote;
    wcout << L"mVote: " << vote << "\n";

    std::wstring line;
    wchar_t tmp;

    //std::getline(in, line);
    line = utils::customGetline(in);
    UINT16 day, month, year;
    in >> day >> tmp >> month >> tmp >> year;
    this->mDate.setD(day);
    this->mDate.setM(month);
    this->mDate.setY(year);
    std::wcout << L"Date: " << day << L"/" << month << L"/" << year << std::endl;

    //std::getline(in, line);
    line = utils::customGetline(in);
    UINT16 hour, minute, second;
    in >> hour >> tmp >> minute >> tmp >> second;
    this->mTime.setH(hour);
    this->mTime.setM(minute);
    this->mTime.setS(second);
    std::wcout << L"Time: " << hour << L":" << minute << L":" << second << std::endl;
}