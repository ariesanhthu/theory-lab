#include "CMessage.h"

//wstring dummyMessage = L"1234567890\n7\n10/03/2014\n18:20:22\n";

void CMessage::foutput(std::wostream& out) {
    const wchar_t bom = 0xff;
    out.write(reinterpret_cast<const wchar_t*>(&bom), 1);

    out << mNumber << endl;
    out << mVote << endl;
    out << mDate.getD() << L"/" << mDate.getM() << L"/" << mDate.getY() << endl;
    out << mTime.getH() << L":" << mTime.getM() << L":" << mTime.getS() << endl;
}

void CMessage::finput(std::wistream& in) {
    wchar_t bom;
    in.read(reinterpret_cast<wchar_t*>(&bom), 1);
    if (bom != 0xff) {
        std::wcerr << L"Invalid or missing BOM in UTF-16 file" << std::endl;
        return;
    }

    std::wstring mNumber;
    std::getline(in, mNumber);
    this->mNumber = mNumber;

    UINT16 vote;
    in >> vote;
    this->mVote = vote;
    in.ignore(); 

    UINT16 day, month, year;
    in >> day >> month >> year;
    this->mDate.setD(day);
    this->mDate.setM(month);
    this->mDate.setY(year);
    in.ignore(); 

    UINT16 hour, minute, second;
    in >> hour >> minute >> second;
    this->mTime.setH(hour);
    this->mTime.setM(minute);
    this->mTime.setS(second);
}