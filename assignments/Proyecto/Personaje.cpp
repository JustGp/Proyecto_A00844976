//GEnera la implementación de la clase base Personaje
#pragma once
#include "Personaje.hpp"
#include <iostream>
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

