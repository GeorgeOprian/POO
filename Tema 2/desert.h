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
        Desert(string, int, int, string, int, int);
        Desert(const Desert&);
        ~Desert(){};
        Desert& operator=(const Desert&);
        void citire(istream&);
        void afisare(ostream&);

        friend istream& operator>>(istream&, Desert&);
        friend ostream& operator<<(ostream&, Desert&);
};


class Deserturi
{
    protected:
        vector<Desert> deserturi;
        int nrDeserturi;
    public:
        Deserturi(vector<Desert>, int);
        Deserturi(const Deserturi&);
        ~Deserturi(){};
        Deserturi& operator=(const Deserturi&);
        
        void citire(istream&);
        void afisare(ostream&);
        friend istream& operator>>(istream&, Deserturi&);
        friend ostream& operator<<(ostream&, Deserturi&);
};
#endif