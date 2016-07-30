#ifndef COMIDA_H
#define COMIDA_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../constantes.h"

using namespace std;

class comida {
  public:
    comida ();
    int total();
    int cant_comida (const int x,const int y);
    void aumentar_comida(const int& x, const int& y);
    void disminuir_comida(const int x, const int y, const int energia);
    bool dentrolimites(int nuevox, int nuevoy);
    void estacion();
    // kept as public to be able to graphic from outside the class
    vector <vector<int> > mapa_comida;
} COMIDA;

/**
 * Constructor
 */
comida::comida() {
  vector<vector<int> > aux(x_dim_max, vector<int>(y_dim_max,0));
 mapa_comida = aux;
}

/**
 * Setter: adds food to a point in the map
 */
void comida::aumentar_comida(const int& x, const int& y) {
  mapa_comida[x][y] += comida_sembrada;
  if (mapa_comida[x][y] > max_comida) {
    mapa_comida[x][y] = max_comida;
  }
}

/**
 * Setter: substracts food from a point in the map
 */
void comida::disminuir_comida(const int x, const int y, const int comido) {
  mapa_comida[x][y] -= comido;
}

/**
 * Getter: amount of food at a point
 */
int comida::cant_comida (const int x,const int y) {
  return mapa_comida[x][y];
}

/**
 * Checks if a given point is in the map
 */
bool comida::dentrolimites(int nuevox, int nuevoy) {
  bool is_in_y_range = (nuevox > -1) && (nuevox < x_dim_max);
  bool is_in_x_range = (nuevoy > -1) && (nuevoy < y_dim_max);
  return is_in_y_range && is_in_x_range;
}

/**
 * Getter: total amount of food in the map
 */
int comida::total() {
  int sumatoria = 0;
  for(int i = 0; i < x_dim_max; i++) {
    for(int j= 0;j < y_dim_max; j++) {
      sumatoria += mapa_comida[i][j];
    }
  }
  return sumatoria;
}

/**
 *
 */
void comida::estacion() {
  for (int i = 0; i < x_dim_max; i++) {
    for(int j = 0; j < y_dim_max; j++) {
      mapa_comida[i][j] -= degradar_invierno;
      if (mapa_comida[i][j] < 0) {
        mapa_comida[i][j] = 0;
      }
    }
  }
}

#endif
