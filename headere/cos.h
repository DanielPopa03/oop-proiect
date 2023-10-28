#ifndef _COS_H
#define _COS_H
#include <iostream>
#include <string>
#include <vector>
#include "pizza.h"

class Cos{
private:

    std::vector <Pizza> produseComandate;
    int nrProduse;
    double total;

public:
    
    Cos(){this->nrProduse = 0; this->total = 0;}
    Cos(const Cos& obj);
    void adaugaInCos(int id_pizza, int marime, int numar);
    void pushBack( Pizza& obj );
    void stergeProdus( Cos& cos, int index );
    friend std::ostream& operator<<(std::ostream& out, const Cos& obj);
};

#endif