#include "produs.h"
//#include <bits/stdc++.h>

using namespace std;

Produs::Produs(string numeProdus = "", int pret = 0, int cantitate = 0, string unitateMasura = "")
{
    this->numeProdus = numeProdus;
    this->pret = pret;
    this->cantitate = cantitate;
    this->unitateMasura = unitateMasura;
}
Produs::Produs(const Produs& p){
    this->numeProdus = p.numeProdus;
    this->pret = p.pret;
    this->cantitate = p.cantitate;
    this->unitateMasura = p.unitateMasura;
}

Produs& Produs::operator=(const Produs& p){
    if (this != &p){
        this->numeProdus = p.numeProdus;
        this->pret = p.pret;
        this->cantitate = p.cantitate;
        this->unitateMasura = p.unitateMasura;
    }
    return *this;
}
void Produs::citireNume(istream& in){
    try {
        cout <<"Nume: ";
        getline(in, numeProdus);
        for (unsigned int i = 0; i<numeProdus.size(); i++)
            if (numeProdus[i] != ' '){
                if (numeProdus[i] < 'A' || numeProdus[i] > 'Z'){
                    if(numeProdus[i] < 'a' || numeProdus[i] > 'z'){
                        throw 1;
                    }
                }   
            }
    }catch (int x){
        cout <<"Numele produsului trebuie sa contina doar litere";
        exit(EXIT_FAILURE);
    }
}
void Produs::citirePret(istream& in){
    try{
        cout <<"Pret: ";
        in>>pret;
        if (pret < 0 )
            throw -1;
    }catch(int x){
        cout <<"Pretul trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
}
void Produs::citireCantitate(istream& in){
    try{
        cout << "Cantitate: ";
        in >> cantitate;
        if (cantitate < 0 )
            throw -1;
    }catch(int x){
        cout <<"Cantitatea trebuie sa fie un numar pozitiv\n";
        exit(EXIT_FAILURE);
    }
}
void Produs::citireUnitateMasura(istream& in){
    try{
        cout << "Unitate de masura: ";
        in >>unitateMasura;
        if (unitateMasura.size() > 5) throw 1;
        for (unsigned int i = 0; i < unitateMasura.size(); i++)
            if (unitateMasura[i] < 'a' || unitateMasura[i] > 'z'){
                throw 1;
            }
    }catch(int x){
        cout << "Unitatea de masura trebuie sa contina doar litere mici\n";
        exit(EXIT_FAILURE);
    }
}
void Produs::citire(istream& in){
    citireNume(in);
    citirePret(in);
    citireCantitate(in);
    citireUnitateMasura(in);
}
istream& operator>>(istream& in, Produs& c){
    c.citire(in);
    return in;
}
void Produs::afisare(ostream& out){
    //out << endl;
    out<< numeProdus << endl;
    out << "Pret: " << pret << " lei pe " << cantitate <<" "<< unitateMasura;
}
ostream& operator<<(ostream& out, Produs& c){
    c.afisare(out);
    return out;
}

void Produs::setNumeProdus(string numeProdus){
    this->numeProdus = numeProdus;
}

void Produs::setPret(int pret){
    this->pret = pret;
}

void Produs::setCantitate(int cantitate){
    this->cantitate= cantitate;
}
void Produs::setUnitateMasura(string unitateMasura){
    this->unitateMasura = unitateMasura;
}
int Produs::getPret(){
    return pret;
}
string Produs::getNumeProdus(){
    return numeProdus;
}
int Produs::getCantitate(){
    return cantitate;
}
string Produs::getUnitateMasura(){
    return unitateMasura;
}