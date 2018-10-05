//
// Created by 刘元林 on 2018/10/5.
//

#ifndef EXPERIMENT3_5_PERSON_H
#define EXPERIMENT3_5_PERSON_H


#include <iostream>
#include <cmath>
#include <string>

using namespace std;

static int counter = 0;    // 统计总人数
class Person {
protected:
    string name;
    int age;
    char gender;

public:
    Person();

    Person(string, int, char);  //通过参数初始化成员
    ~Person();

    void set(string, int, char);   //设置人员基本信息
    void show();             //显示人员基本信息
    int get_counter();
};

Person::Person() {}

Person::Person(string PersonName, int PersonAge, char PersonGender) : name(PersonName), age(PersonAge),
                                                                      gender(PersonGender) {
}

int Person::get_counter() {
    return counter;
}

Person::~Person() {
}

class Teacher : public Person {
private:
    int jobNumber;
    string jobTitle;
public:
    Teacher();

    Teacher(string, int, char, int, string);

    ~Teacher();

    void set(string, int, char, int, string);   //设置人员基本信息

    int get_counter();

    void show();
};

Teacher::Teacher() { counter++; }

Teacher::Teacher(string teacherName, int teacherAge, char teacherGender, int teacherJobNumber, string teacherJobTitle)
        : Person(teacherName, teacherAge, teacherGender), jobNumber(teacherJobNumber), jobTitle(teacherJobTitle) {
    counter++;
}

void
Teacher::set(string teacherName, int teacherAge, char teacherGender, int teacherJobNumber, string teacherJobTitle) {
    name = teacherName;
    age = teacherAge;
    gender = teacherGender;
    jobNumber = teacherJobNumber;
    jobTitle = teacherJobTitle;
}

void Teacher::show() {
    cout << "老师" << name << "的个人信息：" << endl;
    cout << "年龄: " << age << ",性别：" << gender << ",工号：" << jobNumber << ",职称：" << jobTitle << endl;
}

int Teacher::get_counter() {
    return counter;
}

Teacher::~Teacher() {
    counter--;
}


class Undergraduate : protected Person {
private:
    int StudentID;
    string Department;
public:
    Undergraduate();

    Undergraduate(string, int, char, int, string);

    ~ Undergraduate();

    void set(string, int, char, int, string);   //设置人员基本信息

    int get_counter();

    void show();
};

Undergraduate::Undergraduate() { counter++; }

Undergraduate::Undergraduate(string UndergraduateName, int UndergraduateAge, char UndergraduateGender,
                             int UndergraduateStudentID, string UndergraduateDepartment)
        : Person(UndergraduateName, UndergraduateAge, UndergraduateGender), StudentID(UndergraduateStudentID),
          Department(UndergraduateDepartment) {
    counter++;
}

void Undergraduate::show() {
    cout << "本科生" << name << "的个人信息：" << endl;
    cout << "年龄: " << age << ",性别：" << gender << ",学号：" << StudentID << ",系别：" << Department << endl;
}

Undergraduate::~Undergraduate() {
    counter--;
}

class Postgraduate : private Person {
private:
    int StudentID;
    string Department;
    string TeacherName;
public:
    Postgraduate();

    Postgraduate(string, int, char, int, string, string);

    ~Postgraduate();

    void set(string, int, char, int, string, string);   //设置人员基本信息

    int get_counter();

    void show();
};

Postgraduate::Postgraduate() { counter++; }

Postgraduate::Postgraduate(string PostgraduateName, int PostgraduateAge, char PostgraduateGender,
                           int PostgraduateStudentID, string PostgraduateDepartment, string PostgraduateTeacherName)
        : Person(PostgraduateName, PostgraduateAge, PostgraduateGender), StudentID(PostgraduateStudentID),
          Department(PostgraduateDepartment), TeacherName(PostgraduateTeacherName) {
    counter++;
}

void Postgraduate::show() {
    cout << "研究生" << name << "的个人信息：" << endl;
    cout << "年龄: " << age << ",性别：" << gender << ",学号：" << StudentID << ",系别：" << Department << ",导师：" << TeacherName
         << endl;
}

Postgraduate::~Postgraduate() {
    counter--;
}

#endif //EXPERIMENT3_5_PERSON_H
