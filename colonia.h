#ifndef COLONIA_H
#define COLONIA_H
#include <iostream>
#include "sembrador.h"
#include "constantes.h"
#include "uc.h"
#include "comida.h"
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

class colonia{

public:
colonia ();
void movimiento();
uc reproduccion();
void escribir_datos(ofstream& archi);
void edades (int edad, uc& UC);

private:
int tiempo;
vector <sembrador> SEMBRADOR;
vector <uc> UC;
int muertos;
float promedio_int;
map <int, cromosoma> edad_ucs;
} COLONIA;

//el costructor de colonia cumple la funcion de inicializar todos los ucs y sembradores tamb
colonia::colonia () {

UC.resize(cant_ucs);
for(int i=0;i<cant_ucs;i++) {
uc auxiliar;
UC[i]=auxiliar;}

SEMBRADOR.resize(cant_sembradores);
for(int i=0;i<cant_sembradores;i++) {
sembrador auxiliar;
SEMBRADOR[i]=auxiliar;
}

tiempo=0;
}

void colonia::movimiento() {
muertos=0;
promedio_int=0;
tiempo++;

for(int i=0;i<cant_sembradores;i++) {
  SEMBRADOR[i].moverse();
  SEMBRADOR[i].sembrar();
}
for(int i=0;i<cant_ucs;i++)
  UC[i].moverse();

for(int i=0;i<cant_ucs;i++) {
  if (UC[i].verenergia()==0) {
    UC[i] = reproduccion();
    muertos++;
    edades(UC[i].veredad(), UC[i]);
  }
}

int cont=0;
for (int i=0;i<cant_ucs;i++) {
  if (UC[i].verenergia() > 0) {
    promedio_int += UC[i].calcular_iq() * 1.0;
    cont++;
  }
}
promedio_int /= cont;

if ((tiempo%invierno)==0)
 COMIDA.estacion();
}


uc colonia::reproduccion() {

vector <uc> reproduccion_A;
vector <uc> reproduccion_B;
uc hijo, madre, padre;
int mayorA=0,mayorB=0;

for(int i=0;i<cant_ucs;i++)
  if(UC[i].verenergia()!=0) {
    if(UC[i].calcular_iqA()>mayorA)
      mayorA=UC[i].calcular_iqA();
    else if(UC[i].calcular_iqB()>mayorB)
      mayorB=UC[i].calcular_iqB();
}


for(int i=0;i<cant_ucs;i++)
if (UC[i].verenergia()!=0) {
  if(UC[i].calcular_iqA()>=(mayorA-1))
    reproduccion_A.push_back(UC[i]);
  else if(UC[i].calcular_iqB()>=(mayorB-1))
    reproduccion_B.push_back(UC[i]);}


int a=rand()%reproduccion_A.size();
madre=reproduccion_A[a];
int b=rand()%reproduccion_B.size();
padre=reproduccion_B[b];

hijo=padre.cruzar(madre);

return hijo;
}

void colonia::escribir_datos(ofstream& archi) {
  archi << "Tiempo: " << tiempo << ", " <<
    "Cantidad de comida en el mapa: " << COMIDA.total() << ", " <<
    "UC que murieron: " << muertos << ", " <<
    "Promedio de inteligencia: " << promedio_int << endl;
  // map <int>
}

void colonia::edades (int edad, uc& UC) {
 edad_ucs[edad] = UC.vercromosoma();
}

#endif
