#include <iostream>
#include "colonia.h"
#include <iomanip>
#include <fstream>

using namespace std;


int main () {
srand(time(NULL));
colonia hormigas;
ofstream archi ("datos.txt");

for(int i=0;i<1000;i++) {
	hormigas.movimiento();
}


for(int i=0;i<x_dim_max;i++) {
	for(int j=0;j<y_dim_max;j++)
		cout<<setw(3)<<COMIDA.mapa_comida[i][j]<<' ';
		cout<<endl;}
cout<<"total de comida: "<<COMIDA.total()<<endl;
hormigas.escribir_datos(archi);
archi.close();
return 0;}
