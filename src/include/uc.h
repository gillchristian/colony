#ifndef UC_H
#define UC_H
#include <vector>
#include <stdlib.h>
#include <iostream>
#include "../constantes.h"
#include "cromosoma.h"
#include "comida.h"

using namespace std;

class uc {
  private:
    int posx,posy;
    int energia;
    int edad;
    cromosoma mi_cromosoma;
  public:
    uc();
    uc(cromosoma nuevo);
    cromosoma vercromosoma();
    uc cruzar(uc);
    void moverse();
    int buscarcomida();
    int comer();
    bool dentrolimites(int nuevox, int nuevoy);

    int veredad() {
      return edad;
    };
    int verenergia() {
      return energia;
    };
    int verposicionx() {
      return posx;
    };
    int verposiciony() {
      return posy;
    };
    int calcular_iq() {
      return mi_cromosoma.calcularIQ();
    };
    int calcular_iqA() {
      return mi_cromosoma.calcularIQ_A();
    };
    int calcular_iqB() {
      return mi_cromosoma.calcularIQ_B();
    };
};

/**
 * Constructor
 *
 * When the UC is initialized from scratch
 */
uc::uc() {
  energia = energia_inicial;
  edad = 0;
  posx = rand() % x_dim_max;
  posy = rand() % y_dim_max;
}

/**
 * Constructor
 *
 * When the UC is generated with a given chromosome
 */
uc::uc(cromosoma nuevo) {
  energia = energia_inicial;
  edad = 0;
  posx = rand() % x_dim_max;
  posy = rand() % y_dim_max;
  mi_cromosoma = nuevo;
}

/**
 * Do movement
 *
 * TODO: this method needs a serious rework
 */
void uc::moverse() {
  int direccion;
  int lugarcomida = buscarcomida();
  int nuevox;
  int nuevoy;
  // TODO: add an isDead property
  if (energia == 0) {
    exit(0);
  }
  do {
    direccion = rand() % 8;
    if(lugarcomida < 8) {
      direccion = mi_cromosoma.posicion(lugarcomida);
      lugarcomida = 10;
    }
    switch(direccion) {
      case 0:
        nuevox = posx - 1;
        nuevoy = posy;
        break;
      case 1:
        nuevox = posx - 1;
        nuevoy = posy + 1;
        break;
      case 2:
        nuevox = posx;
        nuevoy = posy + 1;
        break;
      case 3:
        nuevox = posx + 1;
        nuevoy = posy + 1;
        break;
      case 4:
        nuevox = posx + 1;
        nuevoy = posy;
        break;
      case 5:
        nuevox = posx + 1;
        nuevoy = posy - 1;
        break;
      case 6:
        nuevox = posx;
        nuevoy = posy - 1;
        break;
      case 7:
        nuevox = posx - 1;
        nuevoy = posy - 1;
        break;
    }
  } while(!dentrolimites(nuevox, nuevoy));

  posx = nuevox;
  posy = nuevoy;
  energia--;
  edad++;
  COMIDA.disminuir_comida(posx, posy, comer());
}

/**
 * Checks if a give point is inside the map
 *
 * TODO: this should not be a task for this class
 */
bool uc::dentrolimites(int nuevox, int nuevoy) {
  bool is_in_y_range = (nuevox > -1) && (nuevox < x_dim_max);
  bool is_in_x_range = (nuevoy > -1) && (nuevoy < y_dim_max);
  return is_in_y_range && is_in_x_range;
}

/**
 *
 */
uc uc::cruzar(uc madre) {
  cromosoma mother_chromosome = madre.vercromosoma();
  cromosoma child_chromosome = mi_cromosoma.reproducir(mother_chromosome);
  uc hijo(child_chromosome);
  return hijo;
}

/**
 * Getter: chromosome
 */
cromosoma uc::vercromosoma() {
  return mi_cromosoma;
}

/**
 * Search for food
 *
 * TODO: this method needs a serious rework
 */
int uc::buscarcomida() {
  if(dentrolimites(posx-1,posy) && COMIDA.cant_comida(posx-1,posy) > 0) {
    return 0;
  }
  if(dentrolimites(posx-1,posy+1) && COMIDA.cant_comida(posx-1,posy+1) > 0) {
    return 1;
  }
  if(dentrolimites(posx,posy+1) && COMIDA.cant_comida(posx,posy+1) > 0) {
    return 2;
  }
  if(dentrolimites(posx+1,posy+1) && COMIDA.cant_comida(posx+1,posy+1) > 0) {
    return 3;
  }
  if(dentrolimites(posx+1,posy) && COMIDA.cant_comida(posx+1,posy) > 0) {
    return 4;
  }
  if(dentrolimites(posx+1,posy-1) && COMIDA.cant_comida(posx+1,posy-1) > 0) {
    return 5;
  }
  if(dentrolimites(posx,posy-1) && COMIDA.cant_comida(posx,posy-1) > 0) {
    return 6;
  }
  if(dentrolimites(posx-1,posy-1) && COMIDA.cant_comida(posx-1,posy-1) > 0) {
    return 7;
  }

  // no food around
  return 10;
}

int uc::comer() {
  int acomer = energia_max - energia;
  int comido = 0;
  int comida_enlugar = COMIDA.cant_comida(posx,posy);
  if(acomer <= cant_comer) {
    if (comida_enlugar > acomer) {
      comido = acomer;
    }
    else {
      if (comida_enlugar > 0) {
        comido = comida_enlugar;
      }
    }
  } else {
    if (comida_enlugar > cant_comer) {
      comido = cant_comer;
    } else {
      if (comida_enlugar > 0) {
        comido = comida_enlugar;
      }
    }
  }
  energia += comido;
  return comido;
}

#endif
