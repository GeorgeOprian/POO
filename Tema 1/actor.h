
#ifndef ACTORDB_ACTOR_H
#define ACTORDB_ACTOR_H

#include <iostream>


using namespace std;

class Actor{
    private:
        char * nume_actor;
        int varsta;
        friend class Teatru;
        friend class Meniu;

    public:
        Actor ();
        Actor(const char *, int); //constructori initializare
        Actor(Actor&);
        ~Actor(); //descrtuctor
        //set
        void setNume_actor(char * nume_actor);
        void setVarsta(int varsta);
        //get
        char * getNume_actor();
        int getVarsta();

        void citireActor(istream &in);
        void afisareActor(ostream &out);

        friend istream& operator>>(istream &in, Actor &a);
        friend ostream& operator<<(ostream &in, Actor &a);
        Actor& operator=(const Actor &a);
};

#endif