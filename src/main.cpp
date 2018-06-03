#include <iostream>
#include <iomanip>
#include <fstream>
#include "include/colonia.h"
#include "constantes.h"

using namespace std;

int main () {
  srand(time(NULL));
  colonia hormigas;
  ofstream archi ("datos.txt");

  for(int i = 0; i < iterations; i++) {
    hormigas.movimiento();
    if (i % 10 == 0) {
      hormigas.escribir_datos(archi);
    }
  }

  for(int i = 0; i < x_dim_max; i++) {
    for(int j = 0; j < y_dim_max; j++) {
      cout << setw(2) << COMIDA.mapa_comida[i][j] << ' ';
    }
    cout << endl;
  }

  cout << "total de comida: " << COMIDA.total() << endl;
  hormigas.escribir_datos(archi);
  archi.close();
  return 0;
}
