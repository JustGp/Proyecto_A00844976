//GEnera la implementación de la clase base Personaje
#pragma once
#include "Personaje.hpp"
#include <iostream>
#include <random>
using namespace std;

// Gael Emiliano VIllatoro Perez A00844976


//Constructor 
Unidad::Unidad(): vida{100}, hpoints{100}, ataque{10}, nivel{1}{}
Unidad::Unidad(int valVida, int valHpoints, int valAtaque, int valNivel): vida{valVida}, hpoints{valHpoints}, ataque{valAtaque}, nivel{valNivel}{}

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


// Porcentaje salud ( might be wrong )
int Unidad::porcentajeSalud(){
    int porcentaje = (hpoints/vida)*100;
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
/*
void Unidad::recibeAtaque(Unidad& objetivo){
    int  puntos = calculaAtaque(objetivo);
    objetivo.setHpoints(objetivo.getHpoints() - puntos);
    if (hpoints< 0){
        objetivo.setHpoints(0);
        cout << "La unidad murio" << endl;
    }
}

void Unidad::atacar(Unidad& objetivo){

}
*/

void Unidad::recibeAtaque(int ptosAtaque){
    hpoints = hpoints - ptosAtaque;
    if ( hpoints < 0){
        hpoints = 0;
        cout << "La unidad murio " << endl;
    }
}


void Unidad::atacar( Unidad& objetivo){
    int puntos = objetivo.calculaAtaque(objetivo);
    objetivo.recibeAtaque(puntos);
}

void Unidad::imprimir(){
    cout << "-----Caracteristicas de unidad-----"<< endl;
    cout << endl;
    imprimirBarra();
    cout << "Hitpoints --" << hpoints << endl;
    cout << "Nivel -- " << nivel << endl;
    cout << "Ataque -- " << ataque << endl;
}