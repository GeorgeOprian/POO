#ifndef BAUTURI_H
#define BAUTURI_H

#include "produs.h"
 
 //cantitatea o setezi din citirea cu clientul
 class Vin: public Produs
 {
    protected:
        string culoare;
    public:
        Vin(string, int, int, string, string);
        Vin(const Vin&);
        ~Vin(){};
        Vin& operator=(const Vin&);

        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Vin&);
        friend ostream& operator<<(ostream&, Vin&);
 };
 
 class VinSticla: public Vin
 {
    protected:
        string brand;
        int an;
    public:
        VinSticla(string, int, int, string, string, string, int);
        VinSticla(const VinSticla&);
        ~VinSticla(){};

        VinSticla& operator=(const VinSticla&);

        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Vin&);
        friend ostream& operator<<(ostream&, Vin&);
 };
 
class Bere:Produs
{
    protected:
        string brand;
    public:
        Bere(string, int, int, string, string);
        Bere(const Bere&);
        ~Bere(){};

        Bere& operator=(const Bere&);

        void citire(istream& in);
        void afisare(ostream& out);

        friend istream& operator>>(istream&, Bere&);
        friend ostream& operator<<(ostream&, Bere&);
};


class Apa:Produs
{
    protected:
        string brand;
        string aciditate;
    public:
        Apa(string, int, int, string, string, string);
        Apa(const Apa&);
        ~Apa(){};

        Apa& operator=(const Apa&);

        void citire(istream& in);
        void afisare(ostream& out);

        friend istream& operator>>(istream&, Apa&);
        friend ostream& operator<<(ostream&, Apa&);
};

 class Bauturi
 {
    protected:
        vector<Vin> vinPahar;
        int nrVinPahar;
        vector<VinSticla> vinSticla;
        int nrVinSticla;
        vector<Bere> bere;
        int nrBeri;
        vector<Apa> apa;
        int nrApe;
    public:
        Bauturi(vector<Vin>, int, vector<VinSticla>, int, vector<Bere>, int, vector<Apa>, int);
        Bauturi(const Bauturi&);
        ~Bauturi(){};
        Bauturi& operator=(const Bauturi&);

        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Bauturi&);
        friend ostream& operator<<(ostream&, Bauturi&);

 };
 
#endif