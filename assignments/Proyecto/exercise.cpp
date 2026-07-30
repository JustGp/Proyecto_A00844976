#include <iostream>
#include <vector>
#include <random>
using namespace std;

#include "Personaje.hpp"
#include "Caballero.hpp"
#include "Mago.hpp"
#include "Arquero.hpp"


Unidad* duelo(Unidad* bueno, Unidad* malo){
  cout << endl;
  cout << endl;
  cout << endl;
  cout << "La batalla empieza!!" << endl;
  cout << " TU SOLDADO" << endl;
  bueno->imprimir();
  cout << endl;
  cout << endl;
  cout << " EL ENEMIGO " << endl;
  malo->imprimir();
  cout << "Que empiece !!" << endl;

  while(bueno->getHpoints() > 0 && malo->getHpoints() > 0){
    *bueno + *malo;
    if (malo->getHpoints() <= 0){
      break;
    }
    *malo + *bueno;
    malo->turnPass();
    bueno->turnPass();
  }
  cout << endl;
  cout << endl;

  if(bueno->getHpoints() <= 0){

    cout << " Tu soldado perdio :( " << endl;
    cout << " Stats del enemigo" << endl;
    malo->killReset();
    malo->imprimir();
    return bueno;
  }
  else{
    cout << " Ganaste la pelea :) "<< endl;
    bueno->killReset();
    bueno->imprimir();
    return malo;
  }
};



int main() 
{
  int quantity;
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

  for(int i = 0; i< quantity ; i++){
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

  for(int i= 0; i< quantity ; i++){
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

  while (true){
    try{
      if ( buenos.empty() || malos.empty()){
        throw myex;
        break;

      }
      random_device rd;
      mt19937 gen(rd());
      uniform_int_distribution<> distribBuenos(0,buenos.size()-1);
      uniform_int_distribution<> distribMalos(0,malos.size()-1);
      int buenoide = distribBuenos(gen);
      int maloide = distribMalos(gen);

      Unidad* perdedor = duelo(buenos[buenoide], malos[maloide]);

      if (perdedor == buenos[buenoide]){
        delete buenos[buenoide];
        buenos.erase(buenos.begin() + buenoide);
      }
      else{
        delete malos[maloide];
        malos.erase(malos.begin() + maloide);
      }
      
    }
    catch( exception& e){
      cout << e.what() << "\n";
      break;
    }
  }
  cout << " El resultado fue!!" << endl;

  if (buenos.size() == 0){
    cout << " Perdiste :(" << endl;
    cout << " Stats de los enemigos restantes" << endl;
    for (Unidad* uni :  malos){
      cout << "Tipo : " << typeid(*uni).name() << endl;
    }


  }
  else{
    cout << endl;
    cout << endl;
    cout << " GANASTE!! :)" << endl;
    cout << " Stats de tu ejercito restantes" << endl;
    for (Unidad* uni :  buenos){
      cout << "Tipo : " << typeid(*uni).name() << endl;
      uni->imprimir();
    }
  }

  cout << "-----------------------" << endl;
  cout << " Gracias por usar :)" << endl;





}
