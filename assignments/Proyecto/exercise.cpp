#include <iostream>
#include <vector>
using namespace std;

#include "Personaje.hpp"
#include "Caballero.hpp"
#include "Mago.hpp"
#include "Arquero.hpp"


int main() 
{
  std::vector<Unidad*> unidades;
  unidades.push_back(new Caballero);
  unidades.push_back(new Mago);
  unidades.push_back(new Arquero);

  for(Unidad* uni: unidades ){
    uni->imprimir();

  }

  for (size_t i = 0; i < unidades.size(); i++){
    if (i == unidades.size() - 1){
        *unidades[i] + *unidades[0];       // last one attacks the first
    }
    else{
        *unidades[i] + *unidades[i + 1];   // everyone else attacks the next one
    }
}

  for(Unidad* uni: unidades ){
    uni->imprimir();

  }

}
