#ifndef _COMANDA_H
#define _COMANDA_H
#include "cos.h"
#include "client.h"
class Comanda{
private:

    Cos Cos_;
    Client Nr;
    std::string metodaDeLivrare;
    std::string Pret;

public:
    Comanda()=default;
};
#endif