#include "../headere/cos.h"


Cos::Cos(const Cos& obj){
        this->produseComandate = obj.produseComandate;
        this->nrProduse = obj.nrProduse;
        this->total = obj.total;
         }

void Cos::pushBack(Pizza & obj){
    (this->produseComandate).emplace_back(obj);
    this->nrProduse += 1;
    this->total += obj.getPret();
}

void Cos::stergeProdus( Cos& cos, int index ){
    this->nrProduse -= 1;
    this->total -= (this->produseComandate[index]).getPret();
    (this->produseComandate).erase((this->produseComandate).begin()+index);
}
