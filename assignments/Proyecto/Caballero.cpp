#pragma once
#include "Caballero.hpp"
using namespace std;
#include <iostream>
#include <random>

//Constructor

Caballero::Caballero(){
    inercial = 0;
}

Caballero::Caballero(int valVida, int valHpoints, int valAtaque, int valNivel, int armory, int valInertial ):Unidad(valVida, valHpoints, valAtaque, valNivel, armory){
    inercial = valInertial;
}

//Getters

int Caballero::getInercial() const{
    return inercial;
}

//Setter

void Caballero::setInercial(int valor) {
    inercial = valor;
}

//Methods
void Caballero::Setup(){
    Unidad::setVida(150);
    Unidad::setAtaque(20);
    Unidad::setHpoints(150);
    Unidad::setArmor(10);
    Unidad::setNivel(1);
    setInercial(1);

}

int Caballero::calcularBono(){
    int bono = (getNivel()*inercial);
    return bono;
}