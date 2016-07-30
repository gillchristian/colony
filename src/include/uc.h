#ifndef UC_H
#define UC_H
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "../constantes.h"
#include "cromosoma.h"
#include "comida.h"
using namespace std;

class uc{
private:
int posx,posy;
int energia;
int edad;
cromosoma mi_cromosoma;
public:
uc();//ucs que nacen al principio
uc(cromosoma nuevo);//uces hijos
int veredad() {return edad;};
int verenergia() {return energia;};
void moverse();
int verposicionx() {return posx;};
int verposiciony() {return posy;};
int calcular_iq() {return mi_cromosoma.calcularIQ();};
int calcular_iqA() {return mi_cromosoma.calcularIQ_A();};
int calcular_iqB() {return mi_cromosoma.calcularIQ_B();};
uc cruzar(uc);//reproduccion
bool dentrolimites(int nuevox, int nuevoy);
cromosoma vercromosoma();
int buscarcomida();
int comer();
};

uc::uc() {
energia=energia_inicial;
edad=0;
posx=rand()%x_dim_max;
posy=rand()%y_dim_max;

}

uc::uc(cromosoma nuevo) {
energia=energia_inicial;
edad=0;
posx=rand()%x_dim_max;
posy=+rand()%y_dim_max;
mi_cromosoma=nuevo;
}

void uc::moverse() {
int direccion;
int lugarcomida=buscarcomida();
int nuevox,nuevoy;
if (energia==0)
exit(0);
do {
direccion=rand()%8;
if(lugarcomida<8) {
  direccion=mi_cromosoma.posicion(lugarcomida);
  lugarcomida=10;}
switch(direccion) {
case 0:
nuevox=posx-1;nuevoy=posy;
break;
case 1:
nuevox=posx-1;nuevoy=posy+1;
break;
case 2:
nuevox=posx;nuevoy=posy+1;
break;
case 3:
nuevox=posx+1;nuevoy=posy+1;
break;
case 4:
nuevox=posx+1;nuevoy=posy;
break;
case 5:
nuevox=posx+1;nuevoy=posy-1;
break;
case 6:
nuevox=posx;nuevoy=posy-1;
break;
case 7:
nuevox=posx-1;nuevoy=posy-1;
break;
}
}while(!dentrolimites(nuevox,nuevoy));

posx=nuevox;posy=nuevoy;
energia--;
edad++;
COMIDA.disminuir_comida(posx,posy,comer());
}

bool uc::dentrolimites(int nuevox, int nuevoy) {
if((nuevox>-1)&&(nuevox<x_dim_max))
if((nuevoy>-1)&&(nuevoy<y_dim_max))
return true;
return false;
}

uc uc::cruzar(uc madre) {
uc hijo(mi_cromosoma.reproducir(madre.vercromosoma()));
return hijo;
}
cromosoma uc::vercromosoma() {
return mi_cromosoma;
}

int uc::buscarcomida() {
int dirigido=10;
  if(dentrolimites(posx-1,posy))
    if (COMIDA.cant_comida(posx-1,posy)>0)
      dirigido=0;

  if(dentrolimites(posx-1,posy+1))
    if (COMIDA.cant_comida(posx-1,posy+1)>0)
      dirigido=1;

  if(dentrolimites(posx,posy+1))
    if (COMIDA.cant_comida(posx,posy+1)>0)
      dirigido=2;

  if(dentrolimites(posx+1,posy+1))
    if (COMIDA.cant_comida(posx+1,posy+1)>0)
      dirigido=3;

  if(dentrolimites(posx+1,posy))
    if (COMIDA.cant_comida(posx+1,posy)>0)
      dirigido=4;

  if(dentrolimites(posx+1,posy-1))
    if (COMIDA.cant_comida(posx+1,posy-1)>0)
      dirigido=5;

  if(dentrolimites(posx,posy-1))
    if (COMIDA.cant_comida(posx,posy-1)>0)
      dirigido=6;

  if(dentrolimites(posx-1,posy-1))
    if (COMIDA.cant_comida(posx-1,posy-1)>0)
      dirigido=7;

return dirigido;//se devuelve 10 cuando no hay comida alrededor
}

int uc::comer() {
int acomer=energia_max-energia,comido=0;
int comida_enlugar=COMIDA.cant_comida(posx,posy);
if(acomer<=cant_comer) {
  if (comida_enlugar>acomer)
    comido=acomer;
  else 
    if (comida_enlugar>0)
      comido=comida_enlugar;
    }
else {
  if (comida_enlugar>cant_comer)
  comido=cant_comer;
  else 
    if (comida_enlugar>0)
      comido=comida_enlugar;
}
energia+=comido;
return comido;
}


#endif
