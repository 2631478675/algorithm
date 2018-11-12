#include "cstring.h"

int main() {
    char * data = "hello ,deki ";
    cstring dataString = cstring(data);
    print p;
    p.println(dataString);
    cstring daString = dataString;
    p.println(daString);
    cstring dataString1 = daString + dataString;
    p.println(dataString1);
    daString += daString;
    p.println(daString);
    return 0;
}