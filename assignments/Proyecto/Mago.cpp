#include "Mago.hpp"
#include <iostream>
using namespace std;

Mago::Mago(){
    toll = 0;
    mana = 100;
}
Mago::Mago(int valVida, int valHpoints, int valAtaque, int valNivel, int armory, int valMana, int valToll ):Unidad(valVida, valHpoints, valAtaque, valNivel, armory){
    mana = valMana;
    toll = valToll;
}

//Setters y getters

int Mago::getMana() const{
    return mana;
}

int Mago::getToll() const{
    return toll;
}

void Mago::setMana(int valor){
    mana = valor;
}

void Mago::setToll(int valor){
    toll = valor;
}

// methods
int Mago::manaAtack(){
    if (getMana() >= 15){
        setMana(getMana() - 15);
        setToll(getToll()+2);
        return 15;
    }
    else{
        cout << " Not Enough mana" << endl;
        return 0;
    }
}

int Mago::manaBlock(){
    if (getMana() >= 20){
        setMana(getMana() - 20);
        setToll(getToll()+4);
        return 20;
    }
    else{
        cout << " Not enough mana " << endl;
        return 0;
    }
}

void Mago::tollReset(){
    if(getMana() >= 50){
        setMana(getMana() - 50);
        setToll(0);
    }
    else{
        cout << "Not enough mana" << endl;
    }
}

void Mago::turnPass(){
    setMana(getMana() +10);
}

void Mago::Setup(){
    setMana(100);
    setToll(0);

}

int Mago::calcularBono(int dano){
    return manaAtack();
}

int Mago::calcularDebuffs(int ddano){
    return manaBlock() - tollDebuff();
}


int Mago::tollDebuff(){
    return getToll();
}

void Mago::imprimir(){
        cout << "-----Caracteristicas de Mago-----"<< endl;
    cout << endl;
    imprimirBarra();
    cout << "Hitpoints --" << getHpoints() << endl;
    cout << "Nivel -- " << getNivel()  << endl;
    cout << "Ataque -- " << getAtaque() << endl;
    cout << "Mana actual -- "<< getMana() << endl;
    cout << "Toll actual -- " << getToll() << endl;


}