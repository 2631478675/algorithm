//
// Created by I500042 on 11/7/2018.
//
/**
 * 设计基类Employee，包含各类员工共有的基本信息，以及静态数据成员totalNo，用于自动计算员工编号（员工编号从1开始）；
 * 基类定义构造函数和析构函数，另外还需要定义计算员工月薪和显示员工信息的成员函数，以规范各派生类的行为。
 */
#ifndef EXPERIMENT4_6_EMPLOYEE_H
#define EXPERIMENT4_6_EMPLOYEE_H

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Employee {
protected:
    int No;
    string name;
    float salary;
    static int totalNo;
public:
    Employee();     //自动计算员工编号，姓名从键盘输入，工资初值为0
    ~Employee();

    virtual void pay()=0;        //计算月薪
    virtual void display() = 0;      //显示人员信息
};

int Employee::totalNo = 0;

Employee::Employee() {  // init No and totalNo and name
    if (totalNo == 0) {
        No = 1;
        totalNo = 1;
    } else {
        No = ++(totalNo);
    }
}

Employee::~Employee() {
    No = 1;
    salary = 0;
    totalNo = 1;
}

/**
 * 经理：固定月薪8000元；
 * 技术人员：50元/小时；
 * 销售人员：当月销售额的3%
 */
class Manager : public Employee {
private:
    string inputName;
public :
    Manager();

    ~Manager();

    virtual void pay();

    virtual void display();
};

Manager::Manager() {
    cout << "input manager' name : ";
    cin >> inputName;
    name = inputName;
}

void Manager::pay() {
    salary = 8000;
}

void Manager::display() {
    cout << "the manager's information : " << endl;
    cout << "No : " << No << endl;
    cout << "name : " << name << endl;
    cout << "salary : " << salary << endl;
}

class Salesperson : public Employee {
private:
    double salary;
    float sales; //销售额
    string inputName;
public :
    Salesperson(float);

    ~Salesperson();

    virtual void pay();

    virtual void display();
};

Salesperson::Salesperson(float s) {
    cout << "input Salesperson' name : ";
    sales = s;
    cin >> inputName;
    name = inputName;
}

Salesperson::~Salesperson() {

}

void Salesperson::pay() {
    salary = sales * 0.3 * 0.1;
}

void Salesperson::display() {
    cout << "the Salesperson's information : " << endl;
    cout << "No : " << No << endl;
    cout << "name : " << name << endl;
    cout << "salary : " << salary << endl;
}

class TechnicalStaff : public Employee {
private:
    string inputName;
    float time; //工作时长(小时)
public :
    TechnicalStaff(float);

    ~TechnicalStaff();

    virtual void pay();

    virtual void display();
};

TechnicalStaff::TechnicalStaff(float t) {
    cout << "input technicalStaff' name : ";
    time = t;
    cin >> inputName;
    name = inputName;
}

TechnicalStaff::~TechnicalStaff() {

}

void TechnicalStaff::pay() {
    salary = time * 50;
}

void TechnicalStaff::display() {
    cout << "the technicalStaff's information : " << endl;
    cout << "No : " << No << endl;
    cout << "name : " << name << endl;
    cout << "salary : " << salary << endl;
}

#endif //EXPERIMENT4_6_EMPLOYEE_H
