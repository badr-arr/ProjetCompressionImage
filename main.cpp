#include <iostream>
#include "SAVEJPEG.H"
#include "matrice.h"
#include "Huffman.h"

using namespace std;


void compresser(Matrice& M,int lig,int col){
    cv<<"Valeur\t\tCode Binaire"<<endl;
    tab= new occur[9216];
    t=new int[9216];
	int i=0,j=0;
	int a= lig/8;
	int b=col/8; int compteur=0;
	while (i<a){
        while (j<b){
            Matrice DCT;
            DCT=Transformation(M,i,j);
            Quantifie(DCT);
            Zig(DCT,compteur);
            j++;
            compteur++;
        }
        i++;
        j=0;
	}
	RLE(t,9216);
	huffmang() ;
    codage(racine, '0');
}


int main(int argc, char** argv) {
	Matrice A(96,96) ;
	for (int i=0;i<96;i++)
        for (int j=0;j<96;j++)
            A.M[i][j]=i*46+j*200+145;
	compresser (A,96,96);
	SaveJpgFile();
	system("pause");
	return 0;
}
