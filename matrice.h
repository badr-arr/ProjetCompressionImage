#ifndef MATRICE_H
#define MATRICE_H
#include<stdlib.h>
#include<math.h>

#define p 3.14


class Matrice{ public:
               int **M ;
               int L,C ;
               public :
                       Matrice(int,int) ;
                       Matrice();
                       Matrice(const Matrice &);
                       ~Matrice();
                       Matrice & operator=(Matrice const );
                       friend double coef(int,int);
                       friend Matrice Transformation(Matrice &,int,int);
                       void affiche() ;
                       void remplir();
		friend void Quantifie(Matrice &);
		friend bool operator!= (Matrice  &,Matrice  &);

            };



#endif

