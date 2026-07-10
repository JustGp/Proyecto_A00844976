//A00844976 Gael Villatoro

#pragma once
#include "Personaje.hpp"
class Caballero : public Unidad{
    public:
    Caballero();
    Caballero(int , int, int, int ,int ,int);
    int hitstrike();
    int getInercial() const ;
    void setInercial(int);
// rescritos
    void imprimir();
    void Setup();
    int calcularBono();
    int calcularDebuffs();



    private:
    int inercial;

};