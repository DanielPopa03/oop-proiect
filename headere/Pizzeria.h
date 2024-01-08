#ifndef _Pizzeria_H
#define _Pizzeria_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <iostream>
#include <string>
#include "interface.h"
#include "Product.h"
#include "basket.h"
#include "client.h"
#include "order.h"
#include "exception.h"
#include <unistd.h>

class Pizzeria{
    public:
        int run();
};


#endif
