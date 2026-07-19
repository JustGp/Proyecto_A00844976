#include "Arquero.hpp"
#include <iostream>
using namespace std;
#include <random>
Arquero::Arquero(){
    accuracy = 0;
    agility = 0;
}


Arquero::Arquero(int valVida, int valHpoints, int valAtaque, int valNivel, int armory, int valAccuracy, int valAgility ):Unidad(valVida, valHpoints, valAtaque, valNivel, armory){
    accuracy = valAccuracy;
    agility = valAgility;
}

int Arquero::getAccuracy() const{
    return accuracy;
}

void Arquero::setAccuracy(int valor){
    accuracy = valor;
}


int Arquero::getAgility() const{
    return agility;
}
void Arquero::setAgility(int valor){
    agility = valor;
}

//Methods

void Arquero::Setup(){
    setAccuracy(0);
    setAgility(25);

}
int Arquero::AccuracyAttack(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,100);
    int value = distrib(gen);
    if (value <= accuracy){
        return 2 * (getNivel()/2);
    }
    else{
        return 0;
    }
}


int Arquero::calcularBono(int puntos){
    return puntos * AccuracyAttack();
}

int Arquero::calcularDebuffs(int puntos){
    int debuff = getAgility()* getNivel();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,100);
    if (debuff >= puntos){

        if (5 - getNivel() <= 0){
            return 1;

        }
        else{}
        return puntos / (5 - getNivel());
    }
    
    else{
        return 0;
    }


}

void Arquero::turnPass(){
    setAgility(getAgility() + 25);
    setAccuracy(getAccuracy() + 25);

}

void Arquero::killReset(){
    setAgility(25);
    setAccuracy(0);
}

void Arquero::imprimir(){
    cout << "-----Caracteristicas del Arquero-----"<< endl;
    cout << endl;
    imprimirBarra();
    cout << "Hitpoints --" << getHpoints() << endl;
    cout << "Nivel -- " << getNivel()  << endl;
    cout << "Ataque -- " << getAtaque() << endl;
    cout << "Agility -- " << getAgility() << endl;
    cout << "Accuracy -- " << getAccuracy() << endl;

}

void Arquero::revivir(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0,50);
    int randint = distrib(gen);

    if (getAgility() >= randint ){
        cout << " El arquero esquiva el ataque letal" << endl;
        setHpoints(10);
    }
}









