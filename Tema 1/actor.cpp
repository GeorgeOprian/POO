#include "actor.h"
#include <iostream>
#include <cstring>

using namespace std;

Actor :: Actor(){
    nume_actor = nullptr;
    varsta = 0;
}
Actor :: Actor(const char* nume_actor, int varsta){
    this -> nume_actor= new char [strlen(nume_actor) + 1];
    strcpy(this -> nume_actor, nume_actor);
    this -> varsta = varsta;
}
Actor::Actor(Actor& act){
    this -> nume_actor= new char [strlen(act.nume_actor) + 1];
    strcpy(this -> nume_actor, act.nume_actor);
    this -> varsta = act.varsta;
}
Actor :: ~Actor(){
    delete nume_actor;
    varsta = 0;
}

void Actor::setNume_actor(char* nume_actor){
    delete[]this -> nume_actor;
    this -> nume_actor= new char [strlen(nume_actor)];
    strcpy(this -> nume_actor, nume_actor);
}

void Actor::setVarsta(int varsta){
    while (varsta <= 0)
    {
        cout <<"Varsta trebuie sa fie un numar pozitiv nenul.\n";
        cin >>varsta;
    }
    
    this -> varsta = varsta;
}

char* Actor::getNume_actor(){
    return nume_actor;
}

Actor& Actor::operator=(const Actor &a){
    if (this != &a){
        nume_actor = new char[strlen(a.nume_actor) + 1];
        nume_actor[0] = '\0';
        strcpy(nume_actor, a.nume_actor);
        varsta = a.varsta;
    }
    return *this;
}

void Actor::citireActor(istream &in){
    cout <<"Nume actor: ";
    char nume[256];
    in.get(nume, 256);
    nume_actor = new char[strlen(nume) + 1];
    strcpy(nume_actor, nume);
    cout <<"Varsta = ";
    in >> varsta;
}

istream& operator>>(istream &in, Actor &a){
    a.citireActor(in);
    return in;
}

void Actor::afisareActor(ostream &out){
    out<<nume_actor<<" "<<varsta<<endl;
}
ostream& operator<<(ostream &out, Actor &a){
    a.afisareActor(out);
    return out;
}

int Actor::getVarsta(){
    return varsta;
}