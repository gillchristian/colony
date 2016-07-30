#ifndef SEMBRADOR_H
#define SEMBRADOR_H
#include <iostream>
#include "comida.h"
#include <stdlib.h>
#include <vector>
using namespace std;
class sembrador {

private:
int posx,posy;
int dirx,diry;


public:
sembrador ();
void moverse();
void sembrar ();
void posicion(int& x,int& y);
};

sembrador::sembrador() {
posx=rand()%x_dim_max;
posy=rand()%y_dim_max;
dirx=rand()%x_dim_max;
diry=rand()%y_dim_max;
}


void sembrador::moverse () {

int moverx,movery;

moverx=dirx-posx;
movery=diry-posy;

if(moverx>0)
posx++;
else
if (moverx!=0)
posx--;

if(movery>0)
posy++;
else 
if(movery!=0)
posy--;

if(posx==dirx && posy==diry) {
dirx=rand()%x_dim_max;
diry=rand()%y_dim_max;
}
}


void sembrador::sembrar() {
COMIDA.aumentar_comida(posx,posy);
}

void sembrador::posicion(int& x, int& y) {
x=posx;
y=posy;

};


#endif
