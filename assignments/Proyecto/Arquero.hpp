#pragma once
#include "Personaje.hpp"
#include <iostream>

class Arquero : public Unidad{
    public:
    Arquero();
    Arquero(int, int, int, int, int, int,int);
    int getAccuracy() const;
    void setAccuracy(int);
    int AccuracyAttack();
    int getAgility() const;
    void setAgility(int);
// reescritos
    void imprimir() override;
    void Setup() override;
    int calcularBono(int) override ;
    int calcularDebuffs(int) override;
    void killReset() override;
    void turnPass() override;




    private:
    int accuracy, agility;
};