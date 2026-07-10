// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
// A00844976 Gael Villatoro Perez

#pragma once

class Unidad
{
    public:
    Unidad();
    Unidad(int, int, int, int,int);

    //getters
    int getVida() const;
    int getHpoints() const;
    int getAtaque() const;
    int getNivel() const;
    int getArmor() const;

    //Setters
    void setVida(int);
    void setHpoints(int);
    void setAtaque(int);
    void setNivel(int);
    void setArmor(int);


    //Methods
    int porcentajeSalud();
    void imprimirBarra();
    int calculaAtaque(Unidad&);
    void recibeAtaque(int);
    void atacar(Unidad&);
    void imprimir();

    //Methods anadidos

    void Setup();
    int calcularBono();
    int calcularDebuffs();




    private:
    int vida, hpoints, ataque, nivel, armor;




};