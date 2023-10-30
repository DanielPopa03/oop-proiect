#include "../headere/cos.h"


Cos::Cos(const Cos& obj){
        this->produseComandate = obj.produseComandate;
        this->nrProduse = obj.nrProduse;
        this->total = obj.total;
         }

void Cos::adaugaInCos(int id_pizza, int marime, int numar){
    Pizza *dummy = nullptr;
    switch (id_pizza)
    {
    case 0:
        switch (marime)
        {
        case 0:
            dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 1:
            dummy = new Pizza("Medie","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 2:
            dummy = new Pizza("Mare","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    case 1:
        switch (marime)
        {
        case 0:
            dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 1:
            dummy = new Pizza("Medie","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 2:
            dummy = new Pizza("Mare","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        default:
            std::cout<<"Eroare";
            break;
        }

        break;
    case 2:
        switch (marime)
        {
        case 0:
            dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 1:
            dummy = new Pizza("Medie","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        case 2:
            dummy = new Pizza("Mare","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    case 3:
        switch (marime)
        {
        case 0:
            dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        case 1:
            dummy = new Pizza("Medie","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        case 2:
            dummy = new Pizza("Mare","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    case 4:
        switch (marime)
        {
        case 0:
            dummy = new Pizza("Mica","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        case 1:
            dummy = new Pizza("Medie","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        case 2:
            dummy = new Pizza("Mare","Aluat special, sos tomate, mozzarella", 24.9);
            for(int i=0; i < numar; i++)
            (this->produseComandate).emplace_back(*dummy);
            this->total += dummy->getPret() * numar;
            this->nrProduse += numar;
        break;
        default:
            std::cout<<"Eroare";
            break;
        }
        break;
    default:
        std::cout<<"Eroare";
        break;
    }
    if(dummy != nullptr )delete dummy;
};


/*void Cos::pushBack(Pizza & obj){
    (this->produseComandate).emplace_back(obj);
    this->nrProduse += 1;
    this->total += obj.getPret();
}

void Cos::stergeProdus( Cos& cos, int index ){
    this->nrProduse -= 1;
    this->total -= (this->produseComandate[index]).getPret();
    (this->produseComandate).erase((this->produseComandate).begin()+index);
}*/

std::ostream& operator<<(std::ostream& out, const Cos& obj){
    out << "[ " << std::endl;
    for(unsigned int i = 0;i < obj.produseComandate.size();i++){
        out<< obj.produseComandate[i];
        out<<", " << std::endl;
    }
   /* for(auto i : obj.produseComandate ){
        out << i;
        out << ", ";
    }*/
    out<<" ]" << std::endl;
    out << obj.nrProduse << " " << obj.total << std::endl;
    return out;
}
