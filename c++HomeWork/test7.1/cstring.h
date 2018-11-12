//
// Created by 刘元林 on 2018/11/12.
//

#ifndef TEST7_1_CSTRING_H
#define TEST7_1_CSTRING_H

#include <istream>
#include <iostream>
#include <cstring>

using namespace std;

class cstring {
private:
    char *SingelString;
public:
    cstring();

    cstring(char *);

    cstring(const cstring &);

    cstring(cstring &&);

    cstring operator+(const cstring &obj);

    cstring operator+=(const cstring &obj);

    ~cstring();

    friend class print;
};

cstring::cstring() {

}

cstring::cstring(char *data) {
    cout << "使用有参构造函数 : ";
    SingelString = data;
}

cstring::cstring(cstring &&data) {
    cout << "使用转移复制构造函数 : ";
    this->SingelString = data.SingelString;
}

cstring::cstring(const cstring &data) {
    cout << "使用复制构造函数 : ";
    SingelString = data.SingelString;
}

cstring::~cstring() {

}

cstring cstring::operator+(const cstring &obj) {
    cstring mstr;
    mstr.SingelString = new char[strlen(this->SingelString) + strlen(obj.SingelString) + 1];
    sprintf(mstr.SingelString, "%s%s", this->SingelString, obj.SingelString);
    return mstr;
}

cstring cstring::operator+=(const cstring &obj) {
    cstring mstr;
    mstr.SingelString = new char[strlen(this->SingelString) + 1];
    strcpy(mstr.SingelString, this->SingelString);
    this->SingelString = new char[strlen(mstr.SingelString) + strlen(obj.SingelString) + 1];
    sprintf(this->SingelString, "%s%s", mstr.SingelString, obj.SingelString);
    return *this;
}

class print {
public:
    void println(cstring data) {
        cout << data.SingelString << endl;
    }
};

#endif //TEST7_1_CSTRING_H
