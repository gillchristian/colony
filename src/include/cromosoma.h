#ifndef CROMOSOMA_H
#define CROMOSOMA_H
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "uc.h"
#include "../constantes.h"

using namespace std;

class cromosoma {
  private:
    vector<int> codigo_genetico;

  public:
    cromosoma ();
    cromosoma reproducir (cromosoma madre);
    int posicion (int gen) {
      return codigo_genetico[gen];
    };
    int calcularIQ_A();
    int calcularIQ_B();
    int calcularIQ();
};

/**
 * Constructor
 */
cromosoma::cromosoma() {
  codigo_genetico.resize(8);
  for (int i = 0 ; i < 8; i++) {
    codigo_genetico[i] = rand() % 8;
  }
}

/**
 * Reproduces a chromosome with the provided one
 */
cromosoma cromosoma::reproducir(cromosoma madre) {
  cromosoma hijo;
  int mutar = rand() % 100;
  int gen = rand() % 8;
  int nuevo_valor = rand() % 8;

  for (int i = 0; i < 4; i++) {
    hijo.codigo_genetico[i] = madre.codigo_genetico[i];
    hijo.codigo_genetico[i+4] = codigo_genetico[i+4];
  }

  if (mutar < chance_mutar) {
    hijo.codigo_genetico[gen] = nuevo_valor;
  }

  return hijo;
}

/**
 * Calculates the IQ of the chromosome
 *
 * Checkes if the genetic codes is right about the directions to eat
 */
int cromosoma::calcularIQ() {
  int iq = 0;
  for (int i = 0; i < 8; i++) {
    if (codigo_genetico[i] == i) {
      iq++;
    }
  }
  return iq;
}

/**
 * Optional way to calculate the IQ
 */
int cromosoma::calcularIQ_A() {
  int iq=0;
  for (int i = 0; i < 4; i++) {
    if (codigo_genetico[i] == i) {
      iq++;
    }
  }
  return iq;
}

/**
 * Optional way to calculate the IQ
 */
int cromosoma::calcularIQ_B() {
  int iq = 0;
  for (int i = 4; i < 8; i++) {
    if (codigo_genetico[i] == i) {
      iq++;
    }
  }
  return iq;
}

#endif
