#ifndef COMIDA_H
#define COMIDA_H
#include <iostream>
#include <stdlib.h>
#include "../constantes.h"
#include <vector>


using namespace std;

class comida {

private:
//vector <vector<int> > mapa_comida;

public:
comida ();
void aumentar_comida(const int& x, const int& y);
void disminuir_comida(const int x, const int y, const int energia);
int cant_comida (const int x,const int y);
bool dentrolimites(int nuevox, int nuevoy);
vector <vector<int> > mapa_comida;//solo para poder graficar desde un main
int total();
void estacion();
} COMIDA;


comida::comida() { //costructor
  vector<vector<int> > aux(x_dim_max, vector<int>(y_dim_max,0));
mapa_comida=aux;
}


void comida::aumentar_comida(const int& x, const int& y) {

mapa_comida[x][y]+=comida_sembrada;
if (mapa_comida[x][y]>max_comida)
mapa_comida[x][y]=max_comida;

}


void comida::disminuir_comida(const int x, const int y, const int comido) {
mapa_comida[x][y]-=comido;
}

int comida::cant_comida (const int x,const int y) {
return mapa_comida[x][y];
}

bool comida::dentrolimites(int nuevox, int nuevoy) {
  if((nuevox>-1)&&(nuevox<x_dim_max))
    if((nuevoy>-1)&&(nuevoy<y_dim_max))
      return true;
return false;
}

int comida::total() {
int sumatoria=0;
for(int i=0;i<x_dim_max;i++)
  for(int j=0;j<y_dim_max;j++)
    sumatoria+=mapa_comida[i][j];
return sumatoria;}

void comida::estacion() {
for (int i=0;i<x_dim_max;i++)
  for(int j=0;j<y_dim_max;j++) {
    mapa_comida[i][j]-=degradar_invierno;
    if (mapa_comida[i][j]<0)
      mapa_comida[i][j]=0;}
}

#endif
