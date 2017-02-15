#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<math.h>
#include<malloc.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <fstream>
using namespace std ;
ofstream cv("fichcdg.txt" );
         /* //   ***************************PARTIE DECLARATION***************************   // */
typedef struct elt {
                    int info;//contient le nombre d'occurence
                    int occur;//contient la valeur
                    char codoccur[30];
                    struct elt*succ_gauche;
                    struct elt*succ_droit;
                    }arbre;
arbre**niveauzero;arbre**niveaun;arbre**niveaudeaux;arbre**niveautroix;arbre**niveauquatre; arbre**niveaucinq; arbre**niveausix;
arbre*racine;arbre*pere;
typedef struct {
                int occurence;
                int nboccurence;
                char codage[30];
                }occur;
occur* tab;occur permut;
int n1,x,i,n,w,NIV,j,k=0,resultat[8][8],z;
int* t;
char ch[10];char sh[30];char mh[10];
bool b;
    /* //   ***************************premitive arbre vide***************************   // */
int vide(arbre*a)
{if(a==NULL) return (1); else return (0);}
   /* //   ***************************premitive arbre FILS GAUCHE***************************   // */
arbre*filsgauche(arbre*a)
{return(a->succ_gauche);}
/* //   ***************************premitive arbre FILS DROIT***************************   // */
arbre*filsdroit(arbre*a)
{return(a->succ_droit);}
/* //   **************premitive de verification si un elemement d'arbre est une feuille**************   // */
int feuille(arbre*a)
{if (       (   (a->succ_gauche)==NULL)&&(     (a->succ_droit)==NULL   )        ) return (1);
 else return (0);
}


/* //   **************PARCOURS PREFIXE ET CODAGE DES FEUILLLES**************   // */
void Zig(Matrice &Mat,int cc)
{

    int i=0,j=0,kk=0;
	t[kk+(64*cc)]=Mat.M[0][0];
	while ((i<Mat.L-1)  || (j<Mat.C-1))
	{
		if (j<Mat.C-1)
            j++;
		else
            i++;
		kk++;
		t[kk+(64*cc)]=Mat.M[i][j];
		while ( (j>0)&&(i<Mat.L-1))
		{
			i++; j--; kk++;
			t[kk+(64*cc)]=Mat.M[i][j];
		}
		if (i<Mat.C-1)
            i++;
		else
            j++;
		kk++;
		t[kk+(64*cc)]=Mat.M[i][j];
		while((i>0) && (j<Mat.L-1))
		{
			i--;j++;kk++;
			t[kk+(64*cc)]=Mat.M[i][j];
        }

	}
}

void RLE(int* t,int longueur)
{
    k=0;
    tab[0].occurence=t[0];
    tab[0].nboccurence=1;
    k++;
    b=0;
    for (i=1;i<longueur;i++){
        b=0;
        for (j=0;((j<k)&&(b==0));j++){
            if (t[i]==tab[j].occurence) {
                tab[j].nboccurence++;
                b=1;
            }
        }
        if (b==0){
            tab[k].occurence=t[i];
        tab[k].nboccurence=1;
        k++;
        }
    }
    /* //   ***********************trie du tableau**********************   // */
    b=true;
    while (b==true){
        b=false;
        for (i=0;i<k-1;i++){
                if (tab[i].nboccurence>tab[i+1].nboccurence){
                    permut.nboccurence=tab[i+1].nboccurence;
                    permut.occurence=tab[i+1].occurence;
                    tab[i+1].nboccurence=tab[i].nboccurence;
                    tab[i+1].occurence=tab[i].occurence;
                    tab[i].nboccurence=permut.nboccurence;
                    tab[i].occurence=permut.occurence;
                    b=true;
                }
        }
    }
}


void codage(arbre*a,char indice)
{
   if (!vide(a))
    {if(!feuille(a))
      { if (indice=='0') {strcat(ch,"0");strcpy(a->codoccur,ch);}
        else {strcat(ch,"1");strcpy(a->codoccur,ch);}
        codage(filsgauche(a),'0');
        strcpy(ch,a->codoccur);
        codage(filsdroit(a),'1');
       }
    else
     { if (indice=='0') strcat(ch,"0");
        else strcat(ch,"1");
      memmove(ch, ch + 1, strlen(ch));// pour eliminer le premier 0 qu'est en plus
      strcpy(a->codoccur,ch);

      cv<<a->occur<<"\t\t"<<a->codoccur<<endl;

     }
   }
}

          /* //   *****************************FONCTION TRIE DU TABLEAU****************************   // */

void trie(arbre**tab,int n)
{
bool b=true;
int i;arbre*k;
while (b==true)
 {
  b=false;
  for(i=0;i<n-1;i++)
   {if (tab[i]->info > tab[i+1]->info)
     {k=tab[i+1];
      tab[i+1]=tab[i];
      tab[i]=k;
      b=true;
     }
   }
 }
}
      /* //   *****************************FONCTION  HUFFMAN****************************   // */
void huffman(arbre**tinf,arbre**tsup, int n, int*k)
{int l;
  i=2;
  *k=0;
  pere=new arbre;// cration du premier element+ chainage et remplissage
  pere->info=tinf[0]->info+tinf[1]->info;
  pere->succ_gauche=tinf[0];
  pere->succ_droit=tinf[1];
  tsup[*k]=pere;
  i=2;
  while((i<n-1)&&(tinf[i]->info <= pere->info)&&(tinf[i+1]->info <= pere->info))
    { pere=new arbre;
      pere->info=tinf[i]->info+tinf[i+1]->info;
      pere->succ_gauche=tinf[i];
      pere->succ_droit=tinf[i+1];
      *k=*k+1;
      tsup[*k]=pere;
      i=i+2;
    }
  if(i<(n-1))
  { if((tinf[i]->info>=tsup[*k]->info) && (tinf[i+1]->info > tsup[*k]->info))
    { *k=*k+1;
      for(l=i; l<n; l++)
       { tsup[*k]=tinf[l];
         *k=*k+1;
       }
     return;
   }
   if((tinf[i]->info<tsup[*k]->info) && (tinf[i+1]->info>tsup[*k]->info))
    { *k=*k+1;
       for(l=i; l<n; l++)
         { tsup[*k]=tinf[l];
           *k=*k+1;
         }

      trie(tsup,*k);
      return;
   }
 }
 if(i==(n-1))
  { if(tinf[n-1]->info >= tsup[*k]->info)
      { *k=*k+1;
        tsup[*k]=tinf[n-1];
        *k=*k+1;
        return;
      }
    if(tinf[n-1]->info < tsup[*k]->info)
    {*k=*k+1;
     tsup[*k]=tinf[n-1];
     *k=*k+1;
      trie(tsup,*k);
      return;
   }
 }
if(i==n)
 {*k=*k+1;
  return;
 }
}
  void huffmang()
{
niveauzero=new arbre*[k];//Allocation d'espace pour le vecteur qui va contenir les adresses des feuilles
for (i=0;i<k;i++)
    niveauzero[i]= new arbre[k];
for(i=0;i<k;i++)
   {racine=new arbre;
    racine->info=tab[i].nboccurence;
    racine->occur=tab[i].occurence;
    racine->succ_gauche=racine->succ_droit=NULL;
    niveauzero[i]=racine;
   }

       /* //   ********************APPEL DE LA FONCTION HUFFMAN****************************   // */

NIV=0;n=k;
while(n!=1)
{
    niveaun=new arbre*[k];
    for (i=0;i<k;i++)
        niveaun[i]= new arbre[k];
    huffman(niveauzero,niveaun, n, &w);
    n=w;
    NIV=1;
    if(n!=1)
    {
        delete(niveauzero);
        niveauzero=new arbre*[k];
        for (i=0;i<k;i++)
            niveauzero[i]= new arbre[k];
        huffman(niveaun,niveauzero, n, &w);
        n=w;
        NIV=0;
        delete(niveaun);
 }
 else break;
}
if (NIV==0) racine=niveauzero[0];
if (NIV==1) racine=niveaun[0];
}


