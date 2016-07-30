#ifndef SEMBRADOR_H
#define SEMBRADOR_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "comida.h"

using namespace std;

class sembrador {
  private:
    int posx;
    int posy;
    int dirx;
    int diry;

  public:
    sembrador ();
    void moverse();
    void sembrar ();
    void posicion(int& x,int& y);
};

/**
 * Constructor:
 *
 * Initializes the sembrador at a random position ---
 * on the map and with a random direction -----------
 */
sembrador::sembrador() {
  posx = rand() % x_dim_max;
  posy = rand() % y_dim_max;
  dirx = rand() % x_dim_max;
  diry = rand() % y_dim_max;
}

/**
 * Moves in a random direction on the map
 */
void sembrador::moverse () {
  int moverx;
  int movery;

  moverx = dirx - posx;
  movery = diry - posy;

  if(moverx > 0) {
    posx++;
  } else {
    if (moverx != 0) {
      posx--;
    }
  }

  if(movery > 0) {
    posy++;
  } else {
    if (movery != 0) {
      posy--;
    }
  }
  if(posx == dirx && posy == diry) {
    dirx = rand() % x_dim_max;
    diry = rand() % y_dim_max;
  }
}

/**
 *
 */
void sembrador::sembrar() {
  COMIDA.aumentar_comida(posx,posy);
}

/**
 * Setter: x and y positions
 */
void sembrador::posicion(int& x, int& y) {
  x = posx;
  y = posy;
};

#endif
