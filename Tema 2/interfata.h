#ifndef INTERFATA_H
#define INTERFATA_H
#include "restaurant.h"
class Interfata
{
    private:
        Restaurant restaurant;
        bool restaurantCitit;
        int optiune;
    public:
        Interfata(); 
        Interfata(const Interfata&);
        ~Interfata() = default;

        Interfata& operator=(const Interfata&);

        void citireRestaurant(istream&);
        void afisareRestaurant(ostream&);

        friend istream& operator>>(istream&, Interfata&);
        friend ostream& operator<<(ostream&, Interfata&);
        
        int get_optiune();

        void afiseaza_optiuni();
        void citeste_optiunea();
        void afisareMeniu();
        void interactiune();
        void sosescClienti();
        void afiseazaNumarClientiRestaurant();
};  



#endif