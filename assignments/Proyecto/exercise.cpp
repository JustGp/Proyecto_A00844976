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

  for (Unidad* uni: unidades){
    
  }




}
