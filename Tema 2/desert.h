#ifndef DESERT_H
#define DESERT_H
#include "produs.h"
using namespace std;

class Desert:public Produs
{
    protected:
        int nrMinUM;
        int nrMAxUM;
    public:
        Desert() = default;
        Desert(string, int, int, string, int, int);
        Desert(const Desert&);
        ~Desert() = default;
        Desert& operator=(const Desert&);
        void citire(ifstream&);
        void afisare(ostream&);

        friend ifstream& operator>>(ifstream&, Desert&);
        friend ostream& operator<<(ostream&, Desert&);
        
        void setNrMinUM(int);
        void setNrMaxUM(int);
        int getNrMinUM();
        int getNrMaxUM();
};
#endif