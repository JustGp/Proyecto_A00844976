#pragma once
#include "Caballero.hpp"
using namespace std;
#include <iostream>

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
// El dano se aumenta cada turno por un 0.2 del dano total, por cada hit consecutivo
int Caballero::calcularBono(int puntos){
    int bono = (puntos*(inercial))/5;
    hitstrike();
    return bono;

}
// Cada vez que ataque recibe menos dano 
int Caballero::calcularDebuffs(int puntos){
    int debuff = getNivel() * getInercial();
    if (debuff >= puntos ){
        return 1;
    }
    else{
        return debuff;
    }
}

void Caballero::hitstrike(){
    setInercial(getInercial() + (1*getNivel()));
}

void Caballero::imprimir(){
    cout << "-----Caracteristicas del Caballero-----"<< endl;
    cout << endl;
    imprimirBarra();
    cout << "Hitpoints --" << getHpoints() << endl;
    cout << "Nivel -- " << getNivel()  << endl;
    cout << "Ataque -- " << getAtaque() << endl;
    cout << "HitStrike -- " << getInercial() << endl;

}