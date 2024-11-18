/*
Nguyen Anh Thu - 23127266
Tran Hai Duc - 23127173
Bui Quang Hung - 23127193
*/
#include <iostream>
#include "MyString.h"

using namespace std;

char* compareResult(bool flag)
{
    if (flag) return (char*)"true";
    else
        return (char*)"false";
}
int main()
{
    MyString str1, str2, str3;
    
    // Nhập xuất str1, str2
    cout << "Nhap chuoi thu nhat: ";
    cin >> str1;

    cout << "Nhap chuoi thu hai: ";
    cin >> str2;
    
    cout << "-------------------------------------------------\n";
    cout << "Chuoi thu nhat: " << str1 << "\n";
    cout << "Chuoi thu hai: " << str2 << "\n";
    cout << "-------------------------------------------------\n";

    // so sanh str3 va str2
    // gán str3 = str1
    str3 = str1;
    cout << "-------------------------------------------------\n";
    cout << "So sanh str3 va str2: \n";
    cout << "Ta co: str3 = str1: \n";
    cout << "str3 > str2: " << compareResult(str3 > str2) << "\n";
    cout << "str3 < str2: " << compareResult(str3 < str2) << "\n";
    cout << "str3 == str2: " << compareResult(str3 == str2) << "\n";
    cout << "str3 != str2: " << compareResult(str3 != str2) << "\n";
    cout << "str3 >= str2: " << compareResult(str3 >= str2) << "\n";
    cout << "str3 <= str2: " << compareResult(str3 <= str2) << "\n";
    cout << "-------------------------------------------------\n\n";

    cout << "Nhap do dai can set cho chuoi thu ba (len): ";
    // Nhap gia tri n
    int n;
    cin >> n;

    // set lai do dai chuoi str3
    str3.set(n);
    
    cout << "-------------------------------------------------\n";
    cout << "Do dai chuoi sau khi set size: ";
    cout << str3.length() << "\n";

    cout << "Chuoi sau khi set size: " << str3 << "\n";
    cout << "-------------------------------------------------\n\n";

    // Nhap chuoi bat ky
    cout << "Nhap chuoi tmp de set vao chuoi str3: ";
    char tmp[1000];
    cin >> tmp;

    // Thay doi chuoi str3 bang chuoi tmp
    str3.set(tmp);
    cout << "-------------------------------------------------\n";
    cout << "Chuoi sau khi thay doi theo chuoi tmp vua nhap: " << str3 << "\n";
    cout << "-------------------------------------------------\n\n";

   
    //
    MyString kq = str1 + str2 + " " + str3;

    cout << "Ket qua cua str1 + str2 + \" \" + str3: " << kq << "\n";

    // str1[index]
    cout << "-------------------------------------------------\n\n";
    
    cout << "Nhap vi tri ky tu can in cua chuoi thu nhat: "; 
    
    int index;
    cin >> index;

    cout << "Ky tu tai chi so " << index << ": " << str1[index] << "\n";
    cout << "-------------------------------------------------\n\n";

    // subString

    cout << "str3: " << str3 << "\n";
    
    int pos;
    cout << "Nhap vi tri can lay chuoi con (substring): ";
    cin >> pos;
    
    cout << "Nhap so luong ky tu can lay chuoi con: ";
    int num;
    cin >> num;

    cout << "Chuoi con: " << str3.subString(pos, num) << "\n";
    cout << "-------------------------------------------------\n\n";

    // inseart

    cout << "Nhap vi tri can chen chuoi str2 vao chuoi str1: ";
    cin >> pos;

    str1.insert(pos, str2.getStr());
    
    cout << "Chuoi str1 sau khi chen: " << str1 << "\n";
    cout << "-------------------------------------------------\n\n";

    // erase
    cout << "-------------------------------------------------\n";
    cout << "Nhap vi tri bat dau xoa chuoi str1: ";
    cin >> pos;

    cout << "Nhap so luong ky tu can xoa: ";
    cin >> num;
    
    str1.erase(pos, num);
    
    cout << "Chuoi str1 sau khi xoa: " << str1 << "\n";
    cout << "-------------------------------------------------\n\n";
    
    // replace
    cout << "-------------------------------------------------\n";
    cout << "Thay the chuoi tmp vao chuoi str1:\n";

    cout << "Nhap vi tri bat dau thay the vao chuoi str1: ";
    cin >> pos;

    cout << "Nhap so luong ky tu muon thay the trong chuoi str: ";
    cin >> num;

    str1.replace(0, 2, tmp);

    cout << "Chuoi str1 sau khi duoc thay the buoi chuoi tmp: " << str1 << "\n";
    cout << "-------------------------------------------------\n\n";

    // find
    cout << "-------------------------------------------------\n";
    cout << "Nhap vi tri bat dau tim kiem tu chuoi str1: ";
    cin >> pos;

    cout << "Nhap chuoi ky tu can tim kim: ";
    cin >> tmp;

    cout << "So lan xuat hien cua chuoi " << tmp << ": " << str1.find(pos, tmp) << "\n";
    cout << "-------------------------------------------------\n";

    return 0;
}