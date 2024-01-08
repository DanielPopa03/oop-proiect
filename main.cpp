
#include "headere/Pizzeria.h"

#ifdef __linux__
#include <X11/Xlib.h>
#endif
int main() {
    #ifdef __linux__
        XInitThreads();
    #endif
    Pizzeria pizzeriaDorel;
    pizzeriaDorel.run();
}
