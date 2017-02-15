#include <iostream>
#include "matrice.h"

using namespace std;



     
//****************************************Remplir la matrice
void Matrice::remplir()
{
         cout<<"*******************************Remplir la matrice*******************"<<endl;
         for(int i=0;i<L;i++)
         {
                 for(int j=0;j<C;j++)
                 {
                         cout<<"donner la valeur de la case ["<<i<<"]["<<j<<"]";
        	             cin>>M[i][j]; 
                 }
                 cout<<endl;
         }             
       
}
       	                    
 // Le constructeur ---------//
                      
Matrice::Matrice(int a,int b){    int i,j;
                           L=a; C=b;
                         	M= new int* [L];
	                      for(int i=0;i<L;i++){
				                  M[i]=new int[C];
                      }
}
//-------------------------

Matrice::Matrice(){    int i,j;
                           L=8; C=8;
                         	M= new int* [L];
	                      for(int i=0;i<L;i++){
				                  M[i]=new int[C];
                      }
}
//-----------------------------
Matrice::Matrice(const Matrice &B) { int i , j;                           //const par copie const !! 
                                   M=new int*[L] ;
                                   for(i=0;i<L;i++){ M[i]=new int[C] ;} 
                                   for(i=0;i<L;i++){ 
                                                     for(j=0;j<C;j++) { 
                                                              M[i][j] = B.M[i][j] ;   
                                                              }}}                 
// *****************  Destructeur ********//	                 
 Matrice::~Matrice(){
	for(int i=0;i<C;i++){
	   delete [] M[i];}
	   delete [] M;
}

//********* affichage *******************//

 void Matrice::affiche(){
                       int i ,j ;
                      
                       for(i=0;i<L;i++)
                       {
                                       for(j=0;j<C;j++)
                                                       cout<<M[i][j]<<"\t" ; 
                                       cout<<endl ; 
                       }
 }






// ************     Operateur =         ************//
Matrice & Matrice::operator=(Matrice const M2){
	 this->L=M2.L ;
     this->C=M2.C;	
				this->M = new int*[L];
				for(int i=0;i<L;i++)
				 {this->M[i]=new int[C];}
				 
					for(int i=0;i<L;i++){
							    for(int j=0;j<C;j++){
						               	this->M[i][j]=M2.M[i][j] ;}}
				
		return *this;
} 
// ************     Operateur !=         ************//
bool operator!=(Matrice  &M1,Matrice  &M2){
	for(int i=0;i<M1.L;i++){
			for(int j=0;j<M1.C;j++){
							if(M2.M[i][j]!=M1.M[i][j]) return true ;
			}
	}
}





