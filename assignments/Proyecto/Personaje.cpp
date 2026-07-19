//GEnera la implementación de la clase base Personaje
#pragma once
#include "Personaje.hpp"
#include <iostream>
#include <random>
using namespace std;

// Gael Emiliano VIllatoro Perez A00844976


//Constructor 
Unidad::Unidad(): vida{100}, hpoints{100}, ataque{20}, nivel{1}, armor{10}{}
Unidad::Unidad(int valVida, int valHpoints, int valAtaque, int valNivel, int armory): vida{valVida}, hpoints{valHpoints}, ataque{valAtaque}, nivel{valNivel}, armor{armory}{}

// Getters

int Unidad::getVida()const {
    return vida;
}

int Unidad::getHpoints()const {
    return hpoints;
}

int Unidad::getAtaque()const {
    return ataque;
}

int Unidad::getNivel()const {
    return nivel;
}

int Unidad::getArmor()const{
    return armor;
}
//Setters

void Unidad::setVida(int valor) {
    vida = valor;
}

void Unidad::setHpoints(int valor) {
    hpoints = valor;
}

void Unidad::setAtaque(int valor) {
    ataque = valor;
}

void Unidad::setNivel(int valor) {
    nivel = valor;
}

void Unidad::setArmor(int valor){
    armor = valor;
}


// Porcentaje salud ( might be wrong )
int Unidad::porcentajeSalud(){
    int porcentaje = (hpoints*100)/vida;
    return porcentaje;
}

//Imprimir barra
void Unidad::imprimirBarra(){
    int porcentaje = porcentajeSalud();
    // Estoy pensando como dar un numero de 1 al 20
    int barrapoints = (porcentaje*20)/100;
    int restante = 20 - barrapoints;
    for (int i =0; i < barrapoints; i++){
        cout << "#" ;

    }
    for (int i = 0; i < restante; i++){
    cout << "-";
    }
}
int Unidad::calculaAtaque(Unidad& objetivo){
    random_device rd;
    mt19937 gen(rd());
    if (objetivo.getNivel() <= nivel){
        uniform_int_distribution<> distrib((ataque/2),ataque);
        int value = distrib(gen);
        return value;

    }
    else{ // objetivo nivel > nivel
        uniform_int_distribution<> distrib((1),(ataque/2));
        int value = distrib(gen);
        return value;

    }

}


void Unidad::recibeAtaque(int ptosAtaque){
    hpoints = hpoints - ptosAtaque ;
    if ( hpoints < 0){
        hpoints = 0;
        cout << "La unidad murio " << endl;
        revivir();
    }
}


void Unidad::atacar( Unidad& objetivo){
    int puntos = calculaAtaque(objetivo);
    int damage = puntos+ calcularBono(puntos) - calcularDebuffs(puntos);
    if (damage <= 0){
        cout << "Perfect block, no damage" << endl;
    }
    else{
        objetivo.recibeAtaque(damage);

    }
}

void Unidad::imprimir(){
    cout << "-----Caracteristicas de unidad-----"<< endl;
    cout << endl;
    imprimirBarra();
    cout << "Hitpoints --" << getHpoints() << endl;
    cout << "Nivel -- " << getNivel()  << endl;
    cout << "Ataque -- " << getAtaque() << endl;
}


//Personalizado

void Unidad::Setup(){
    hpoints = vida;
}

int Unidad::calcularBono(int puntos){
    return 0;
}

int Unidad::calcularDebuffs(int puntos ){
    return 0;
}

void Unidad::turnPass(){
    // No hace nada
}

void Unidad::killReset(){
    //Para la unidad arquero
}

void Unidad::revivir(){
    cout << " No pos no se levanta" << endl;
}