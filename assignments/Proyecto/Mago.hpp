#pragma once
#include "Personaje.hpp"
#include <iostream>

class Mago : public Unidad{
    public:
    Mago();
    Mago(int , int, int, int ,int , int, int);
    int getMana() const;
    void setMana(int);

    int getToll() const;
    void setToll(int);

    int manaAtack();
    void tollReset();
    int manaBlock();
    int tollDebuff();

//reescritos
    void imprimir() override;
    void Setup() override;
    int calcularBono(int) override ;
    int calcularDebuffs(int) override;
    void turnPass() override;

    private:
    int mana;
    int toll;

};