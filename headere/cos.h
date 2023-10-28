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
    void adaugaInCos( int, int, int);
    void pushBack( Pizza& );
    void stergeProdus( Cos& , int  );
    friend std::ostream& operator<<(std::ostream& , const Cos&);
};

#endif