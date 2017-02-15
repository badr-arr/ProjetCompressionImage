#ifndef SAVEJPEG_H
#define SAVEJPEG_H

#include <iostream>
#include <string.h>
#include <string>
#define longueur_img  0x64
#define largeur_img  0x64

#define writebyte(b) fputc((b),IMG_stream)
#define writeword(w) writebyte((w)/256);writebyte((w)%256);


static struct StartOfImage {
	unsigned short int marker;
}StartOfimageValues={0xFFD8};

static struct APPO{
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int JFIF_Signature1;//J
	unsigned short int JFIF_Signature2;//F
	unsigned short int JFIF_Signature3;//I
	unsigned short int JFIF_Signature4;//F
	unsigned short int VersionMI;// version mineur
	unsigned short int VersionMA;// vesrion majeur
	unsigned short int Densite;//generalement pas d'unité de densité
	unsigned short int ScalingX;//scalling of 100% in the X ( no scalling) (proche de degradation d'image qu'on a pas utilisé)
	unsigned short int ScalingY;//scalling of 100% in the Y (no scalling)
	unsigned short int ThumbnailW;// width of thumbnail (no thumbnail)
	unsigned short int ThumbnailH;//height of thumbnail ( no thumbnail)
}APPOValues={0xFFE0,0x18,0x4A,0x46,0x49,0x46,0x01,0x02,0x00,0x01,0x01,0x00,0x00};

static struct Quantification_Cb {
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int table_ID; //00par defaut pour chrominance et 00 pour luminance ( pas de table de luminance
	unsigned short int Quantif_table[64];//pour une coef de 2
} QuantificationCbValues={0xFFDB,0x0084,0x01,0x03,0x05,0x05,0x07,0x07,0x07,0x09,0x09,0x09,0x09,0x0B,0x0B,0x0B,0x0B,0x0B,0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x15,0x15,0x15,0x15,0x15,0x15,0x17,0x17,0x17,0x17,0x17,0x19,0x19,0x19,0x19,0x1B,0x1B,0x1B,0x1D,0x1D,0x1F};
// sans zigzag 0x030507090B0D0F110507090B0D0F111307090B0D0F111315090B0D0F111315170B0D0F11131517190D0F11131517191B0F11131517191B1D11131517191B1D1F

static struct Quantification_Cr {
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int table_ID; //00par defaut ( pas de table de luminance
	unsigned short int Quantif_table[64];//pour une coef de 2
}QuantificationCrValues={0xFFDB,0x0084,0x02,0x03,0x05,0x05,0x07,0x07,0x07,0x09,0x09,0x09,0x09,0x0B,0x0B,0x0B,0x0B,0x0B,0x0D,0x0D,0x0D,0x0D,0x0D,0x0D,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x0F,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x11,0x13,0x13,0x13,0x13,0x13,0x13,0x13,0x15,0x15,0x15,0x15,0x15,0x15,0x17,0x17,0x17,0x17,0x17,0x19,0x19,0x19,0x19,0x1B,0x1B,0x1B,0x1D,0x1D,0x1F};


static struct SOF{//start of frame
	unsigned short int marker;
	unsigned short int longueur_SOF;
	unsigned short int precision;// 8bit par defaut
	unsigned short int lon_img;
	unsigned short int lar_img;
	unsigned short int nb_couleur;//3
	//unsigned short int Id_Lum;//composant num 1 =1
	//unsigned short int HVY;// subsimpling (facultatif on l' pas fait )
	//unsigned short int QTY;// ID quanti (00 puisque pas de table de limunance)
	unsigned short int ID_Cb;//comp nm 2
	unsigned short int HV_Cb;// meme valeur pas de sub* dans tous les 3 matrice
	unsigned short int QT_Cb;
	unsigned short int ID_Cr;
	unsigned short int HV_Cr;
	unsigned short int QT_Cr;
}SOFValues={0xFFC0,0x1C,0x08,longueur_img,largeur_img,0x03,/*0x01,0x11,0x00,*/0x02,0x11,0x01,0x03,0x11,0x02};

static struct Huffman_Table_Cb {
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int insignificant_bit;// 1 pour RLE et 0 pour DC
	unsigned short int nb_code_de_16_bits[16];//e the number of  codes of length n bits for n = 1, 2, ..., 16.
}Huffman_Table_CbValues={0xFFC4/*,longueur*/,0x0101,/*difficile à extraire du tableau*/};

// normalement ici la table Huffman pour cb

static struct Huffman_Table_Cr {
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int insignificant_bit;// 1 pour RLE et 0 pour DC
	unsigned short int nb_code_de_16_bits[16];//e the number of  codes of length n bits for n = 1, 2, ..., 16.
}Huffman_Table_CrValues={0xFFC4/*,longueur*/,0x0201,/*difficile à extraire du tableau*/};



// normalement ici la table huffman pour Cr



static struct SOS{// start of scan
	unsigned short int marker;
	unsigned short int longueur;
	unsigned short int nb_couleur;
	//unsigned short int Id_Lum;
	//unsigned short int IDHuff_Lum;
	unsigned short int ID_Cb;
	unsigned short int IDHuff_Cb;
	unsigned short int ID_Cr;
	unsigned short int IDHuff_Cr;
	unsigned short int start_Entropy1;
	unsigned short int start_Entropy2;
	unsigned short int start_Entropy3;
}SOSValues={0xFFDA,0x16/*+longueur de l'entropy*/,0x03,0x02,0x01,0x03,0x02,0x00,0x3F,0x00};


//entrpy encoded ou JPEG scan datas ( les valeurs des matrices en changeant les valeurs suivant la table de Huffman )

static struct EndOfImage {
	unsigned short int marker;
}EndOfImageValues={0xFFD9};

//void SaveJpgFile(char *szBmpFileNameIn, char* szJpgFileNameOut)
void SaveJpgFile();

#endif
