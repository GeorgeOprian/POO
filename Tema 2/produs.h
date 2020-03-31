#ifndef PRODUS_H
#define PRODUS_H
#include <bits/stdc++.h>

using namespace std;

class Produs
{
    protected:
    string numeProdus;
    int pret;
    int cantitate;
    string unitateMasura;
        
    public:
        Produs(string, int, int, string);
        Produs(const Produs&);
        virtual ~Produs(){};

        virtual Produs& operator=(const Produs&);
        friend istream& operator>>(istream&, Produs&);
        friend ostream& operator>>(ostream&, Produs&);

        virtual void citireNume(istream&);
        virtual void citirePret(istream&);
        virtual void citireUnitateMasura(istream&);
        virtual void citireCantitate(istream&);
        virtual void citire(istream&);
        virtual void afisare(ostream&);

        void setNumeProdus(string);
        void setPret(int);
        void setCantitate(int);
        void setUnitateMasura(string);

        string getNumeProdus();
        int getPret();
        int getCantitate();
        string getUnitateMasura();

};
#endif