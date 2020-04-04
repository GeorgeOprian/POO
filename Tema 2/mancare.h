#ifndef MANCARE_H
#define MANCARE_H
#include "produs.h"

using namespace std;

class Supa: public Produs
{
    protected:
        
    public:
        Supa() = default;
        Supa(string, int, int, string);
        Supa(const Supa&);
        ~Supa(){};
        Supa& operator=(const Supa&);
        void afisare(ostream&);
};
class Ciorba: public Produs
{
    protected:
        bool ardei;
        bool smantana;
    public:
        Ciorba() = default;
        Ciorba(string, int, int, string, bool, bool);
        Ciorba(const Ciorba&);
        ~Ciorba(){};
        Ciorba& operator=(const Ciorba&);
        void citire(ifstream&);
        void afisare(ostream&);

        void setArdei(bool);
        void setSmantana(bool);
        
        //void afisareProduse();
};

// class Ciorbe
// {
//     protected:
//         vector<Ciorba> ciorbe;
//         int nrCiorbe;
//         vector<Supa> supe;
//         int nrSupe;
//     public:
//         Ciorbe(){};
//         Ciorbe(vector<Ciorba>, int, vector<Supa>, int);
//         Ciorbe(const Ciorbe&);
//         ~Ciorbe(){};
//         Ciorbe& operator=(const Ciorbe&);
        
//         void citire(ifstream&);
//         void afisare(ostream&);

//         friend ifstream& operator>>(ifstream& in, Ciorbe&);
//         friend ostream& operator<<(ostream& out, Ciorbe&);
// };

class Pui: public Produs
{
    protected:
    public:
        Pui() = default;
        Pui(string, int, int, string);
        Pui(const Pui&);
        ~Pui(){};
        void afisare(ostream&);
};

class Vita: public Produs
{
    protected:
        string gradPregatire;
    public:
        Vita() = default;
        Vita(string, int, int, string, string);
        Vita(const Vita&);
        ~Vita(){};
        Vita& operator=(const Vita&);
        //void citire(ifstream&);
        void afisare(ostream&);

        void setGradPregatire(string);
        string getGradPregatire();
};

// class FeluriPrincipale
// {
//     protected:
//         vector<Pui> feluriPui;
//         int nrFeluriPui;
//         vector<Vita> feluriVita;
//         int nrFeluriVita;
//         vector<Produs> garnituri;
//         int nrGarnituri;
//     public:
//         FeluriPrincipale(vector<Pui>, int, vector<Vita>, int, vector<Produs>, int);
//         FeluriPrincipale(const FeluriPrincipale&);
//         ~FeluriPrincipale(){};
//         FeluriPrincipale& operator=(const FeluriPrincipale&);
        
//         void citire(ifstream&);
//         void afisare(ostream&);

//         friend ifstream& operator>>(ifstream& in, FeluriPrincipale&);
//         friend ostream& operator<<(ostream& out, FeluriPrincipale&);
// };

#endif
