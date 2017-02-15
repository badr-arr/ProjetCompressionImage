#include <iostream>
#include "matrice.h"
using namespace std;
double coef(int i, int j)
{
       double racine;
       racine=(1/sqrt(2));
       if ((i==0)&&(j==0)) return (racine*racine);
       if ((i==0)&&(j>0)) return (racine);
       if ((i>0)&&(j==0)) return (racine);
       if ((i>0)&&(j>0)) return (1);
}

Matrice  Transformation( Matrice &pixel, int bl, int bc){
    int x=0,y=0,u=0,v=0,somme=0;

    Matrice DCT(8,8);
    /*pixel.affiche();*/
	while(u < 8){
		while(v < 8){
			while( x < 8){
				while(y < 8){
					somme=(int)(somme+(pixel.M[x+(bl*8)][y+(bc*8)]-128)*cos((p/4)*u*(x+0.5))*cos((p/4)*v*(y+0.5)));
					y++;
                }
				 x++;
			     y=0;
                }
           	DCT.M[u][v]=(int)(somme*((float)2/4)*coef(u,v));
			 v++;
			somme=0;
			x=0;
      }
		v=0;
		u++;
    }
    return DCT;
}
