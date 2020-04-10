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
        ~Supa()= default;
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
        ~Ciorba()= default;
        Ciorba& operator=(const Ciorba&);
        void citire(ifstream&);
        void afisare(ostream&);

        void setArdei(bool);
        void setSmantana(bool);
};

class Pui: public Produs
{
    protected:
    public:
        Pui() = default;
        Pui(string, int, int, string);
        Pui(const Pui&);
        ~Pui()= default;
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
        ~Vita() = default;
        Vita& operator=(const Vita&);
        //void citire(ifstream&);
        void afisare(ostream&);

        void setGradPregatire(string);
        string getGradPregatire();
};

#endif
