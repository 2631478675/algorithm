#include <iostream>
#include "Person.h"

int main() {
    Person * p;
    Teacher teacher("liu",10,'h',10,"liu");
    teacher.show();
    teacher.set("liu",11,'h',10,"liu");
    teacher.show();
    Undergraduate undergraduate("liu",10,'h',10,"liu");
    undergraduate.show();
    cout << p->get_counter() << endl;
    return 0;
}