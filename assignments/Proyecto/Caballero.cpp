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
    Unidad::setVida(100);
    Unidad::setAtaque(20);
    Unidad::setHpoints(100);
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



void Caballero::revivir(){
    random_device rd;
    mt19937 gen(rd());
    int suma = getNivel() * getInercial();
    if (suma >= 60){
        //hacer nada, la unidad esta muy op para este punto
        suma = 60;
    }

    uniform_int_distribution<> distrib(0,100);
    int randint = distrib(gen);
     if (randint <= suma){
        cout << "El caballero se llena de determinacion y se levanta" << endl;
        setHpoints(50);
     }
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