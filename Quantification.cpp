#include <iostream>
#include "matrice.h"

using namespace std;
Matrice Quantification(8,8);
void Quantifie(Matrice &M){
	int i,j;
	//Matrice M1();
	//Matrice M_Quant ;
    for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
				Quantification.M[i][j]=1+((1+i+j)*2);
		}
	}
	for(i=0;i<8;i++){
		for(j=0;j<8;j++){
	                       M.M[i][j]=(M.M[i][j]/Quantification.M[i][j]);
                          }
  }
}
