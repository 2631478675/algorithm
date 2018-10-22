//
// Created by 刘元林 on 2018/10/16.
//

#ifndef TEST5_1_2_CSTRING_H
#define TEST5_1_2_CSTRING_H

#include <istream>
#include <iostream>
#include "string"
using namespace std;

class cstring {
private:
    string SingelString;
public:
    cstring();

    cstring(char *);

    cstring(const cstring &);

    cstring(cstring &&);

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

cstring::cstring(const cstring & data) {
    cout << "使用复制构造函数 : ";
    SingelString = data.SingelString;
}
cstring::~cstring() {

}
class print {
public:
    void println(const cstring & data) {
        cout << data.SingelString << endl;
    }
};

#endif //TEST5_1_2_CSTRING_H
