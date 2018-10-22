#include <iostream>
#include "Person.h"

int main() {
    Person * p;
    Teacher teacher("deki,liu",10,'h',10,"master");
    teacher.show();
    teacher.set("deki,liu",11,'h',10,"master");
    teacher.show();
    Undergraduate undergraduate("deki,liu",10,'h',10,"inter");
    undergraduate.show();
    cout << "现在统计的学生和老师总数是： " << p->get_counter() << endl;
    return 0;
}