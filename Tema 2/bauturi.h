#ifndef BAUTURI_H
#define BAUTURI_H

#include "produs.h"
 
 //cantitatea o setezi din citirea cu clientul
 class Vin: public Produs
 {
    protected:
        string culoare;
    public:
        Vin() = default;
        Vin(string, int, int, string, string);
        Vin(const Vin&);
        virtual ~Vin(){};
        Vin& operator=(const Vin&);

        virtual void citire(ifstream&);
        virtual void afisare(ostream&);

        friend ifstream& operator>>(ifstream&, Vin&);
        friend ostream& operator<<(ostream&, Vin&);

        string getCuloare();
        void setCuloare(string);
 };
 
 class VinSticla: public Vin
 {
    protected:
        string brand;
        int an;
    public:
        VinSticla() = default;
        VinSticla(string, int, int, string, string, string, int);
        VinSticla(const VinSticla&);
        ~VinSticla(){};

        VinSticla& operator=(const VinSticla&);

        void citire(ifstream&);
        void afisare(ostream&);

        friend ifstream& operator>>(ifstream&, Vin&);
        friend ostream& operator<<(ostream&, Vin&);
        void setBrand(string);
        string getBrand();
 };
 
class Bere:public Produs
{
    protected:
        string brand;
    public:
        Bere() = default;
        Bere(string, int, int, string, string);
        Bere(const Bere&);
        ~Bere(){};

        Bere& operator=(const Bere&);

        void citire(ifstream& in);
        void afisare(ostream& out);

        friend ifstream& operator>>(ifstream&, Bere&);
        friend ostream& operator<<(ostream&, Bere&);
        void setBrand(string);
        string getBrand();
};


class Apa:public Produs
{
    protected:
        string brand;
        string aciditate;
    public:
        Apa() = default;
        Apa(string, int, int, string, string, string);
        Apa(const Apa&);
        ~Apa(){};

        Apa& operator=(const Apa&);

        void citire(ifstream& in);
        void afisare(ostream& out);

        friend ifstream& operator>>(ifstream&, Apa&);
        friend ostream& operator<<(ostream&, Apa&);
        void setBrand(string);
        void setAciditate(string);
        string getBrand();
        string getAciditate();
};
 
#endif