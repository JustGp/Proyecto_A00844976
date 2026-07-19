//A00844976 Gael Villatoro

#pragma once
#include "Personaje.hpp"
class Caballero : public Unidad{
    public:
    Caballero();
    Caballero(int , int, int, int ,int ,int);
    void hitstrike();
    int getInercial() const ;
    void setInercial(int);
// rescritos
    void imprimir() override;
    void Setup() override;
    int calcularBono(int) override ;
    int calcularDebuffs(int) override;

    void revivir() override;


    private:
    int inercial;

};