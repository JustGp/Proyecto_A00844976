#include <iostream>
#include <vector>
#include <random>
using namespace std;

#include "Personaje.hpp"
#include "Caballero.hpp"
#include "Mago.hpp"
#include "Arquero.hpp"


int main() 
{
  int quantity;
  bool winneryet;
  vector <Unidad*> buenos;
  vector <Unidad*> malos;

  vector <Unidad*> ejemplo;
  ejemplo.push_back(new Caballero);
  ejemplo.push_back(new Mago);
  ejemplo.push_back(new Arquero);

  cout << "-----------------------"<< endl;
  cout << "SIMULADOR DE PELEAS " << endl;
  cout << "ELIGE LA CANTIDAD DE LOS EJERCITOS" << endl;
  cin >> quantity;

  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1,3);

  for(int i; i< quantity ; i++){
    int value = distrib(gen);
    if (value == 1){
      buenos.push_back(new Caballero());
    }
    if ( value == 2){
      buenos.push_back(new Arquero());
    }
    if ( value == 3){
      buenos.push_back(new Mago());
    }


  }

  for(int i; i<= quantity ; i++){
    int value = distrib(gen);
    if (value == 1){
      malos.push_back(new Caballero());
    }
    if ( value == 2){
      malos.push_back(new Arquero());
    }
    if ( value == 3){
      malos.push_back(new Mago());
    }


  }
  cout << " ------------------------" << endl;
  cout << "Soldados de tu ejercito!!"<< endl;
  for (Unidad* uni : buenos){
    cout << "Tipo : " << typeid(*uni).name() << endl;
  }

  cout << " ------------------------" << endl;
  cout << "Los malos >:C" << endl;
  for (Unidad* uni :  malos){
    cout << "Tipo : " << typeid(*uni).name() << endl;
  }

  cout << " Estadistica base de cada unidad!!" << endl;

  for ( Unidad* uni : ejemplo){
    uni->imprimir();
  }


  do{
    winneryet = false;


  }
  while(winneryet == true);


}
