#include <iostream>
#include "Employee.h"

int main() {
    Employee *p;
    p = new Manager();
    p->pay();
    p->display();
    p = new Salesperson(2000);
    p->pay();
    p->display();
    p = new TechnicalStaff(5);
    p->pay();
    p->display();
    return 0;
}