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
        Produs() = default;
        Produs(string, int, int, string);
        Produs(const Produs&);
        virtual ~Produs(){};

        virtual Produs& operator=(const Produs&);
        friend ifstream& operator>>(ifstream&, Produs&);
        friend ostream& operator<<(ostream&, Produs&);

        virtual void citireNume(ifstream&);
        virtual void citirePret(ifstream&);
        virtual void citireUnitateMasura(ifstream&);
        virtual void citireCantitate(ifstream&);
        virtual void citire(ifstream&);
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