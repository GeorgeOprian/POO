#include <bits/stdc++.h>

class Comanda{
    std::vector< Produs*> listaProd;

    Comanda(const Comanda& other){
        for(int i = 0; i < listaProd.size(); i++)
            delete listaProd[i]; // STERGI MEMORIA ALOCATA;
        for(int i = 0; i < other.listaProd.size(); i++)
            listaProd[i] = new Produs(*(other.listaProd[i])); // ALOCAM MEMORIE SI COPIEM CONTINUTUL DIN OTHER
    }

    Comanda& operator=(const Comanda& other){
        if(this != &other){
            for(int i = 0; i < listaProd.size(); i++)
                delete listaProd[i]; // STERGI MEMORIA ALOCATA;
            for(int i = 0; i < other.listaProd.size(); i++)
                listaProd[i] = new Produs(*(other.listaProd[i]));// Acelasi lucru ca mai sus
        }
    }
};