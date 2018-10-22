//
// Created by 刘元林 on 2018/10/16.
//

#ifndef TEST5_3_EMPLOYEE_H
#define TEST5_3_EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;
static int allSalary = 0;

class employee {
private:
    string name;
    int age;
    int salary;
    char sex;
public:
    employee();

    employee(string, int, int, char);

    ~ employee();

    static void getAllSalary(int salary) {
        allSalary += salary;
        cout << "the allSalary is : " << allSalary << endl;
    }
};

employee::employee() {

}

employee::employee(string na, int ag, int sa, char s) :
        name(na), age(ag), salary(sa), sex(s) {
    cout << "add employee { name : " << name << ", age : " << age << ", salary : " << salary  << ", sex : "  << sex << endl;
    getAllSalary(salary);
}

employee::~employee() {

}




#endif //TEST5_3_EMPLOYEE_H
