#include"SAVEJPEG.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>


static FILE *IMG_stream;




void write_StartOfimageValues()
{
writeword(StartOfimageValues.marker);
}


void write_APP0Values()
{
 writeword(APPOValues.marker);
 writeword(APPOValues.longueur);
 writeword(APPOValues.JFIF_Signature1);
 writeword(APPOValues.JFIF_Signature2);
 writeword(APPOValues.JFIF_Signature3);
 writeword(APPOValues.JFIF_Signature4);
 writeword(APPOValues.VersionMI);
 writeword(APPOValues.VersionMA);
 writeword(APPOValues.Densite);
 writeword(APPOValues.ScalingX);
 writeword(APPOValues.ScalingY);
 writeword(APPOValues.ThumbnailW);
 writeword(APPOValues.ThumbnailH);
}

void write_QuantificationCbValues(){
writeword(QuantificationCbValues.marker);
writeword(QuantificationCbValues.longueur);
writeword(QuantificationCbValues.table_ID);
	for(int i=0 ;i<64;i++){
		writeword(QuantificationCbValues.Quantif_table[i]);
	}
}

void write_QuantificationCrValues(){
writeword(QuantificationCbValues.marker);
writeword(QuantificationCbValues.longueur);
writeword(QuantificationCbValues.table_ID);
	for(int i=0 ;i<64;i++){
		writeword(QuantificationCrValues.Quantif_table[i]);
	}
}

void write_SOFValues()
{
 writeword(SOFValues.marker);
 writeword(SOFValues.longueur_SOF);
 writeword(SOFValues.precision);
 writeword(SOFValues.lon_img);
 writeword(SOFValues.lar_img);
 writeword(SOFValues.nb_couleur);
 writeword(SOFValues.ID_Cb);
 writeword(SOFValues.HV_Cb);
 writeword(SOFValues.QT_Cb);
 writeword(SOFValues.ID_Cr);
 writeword(SOFValues.HV_Cr);
 writeword(SOFValues.QT_Cr);
}

void write_EndOfImageValues()
{
writeword(EndOfImageValues.marker);
}
void SaveJpgFile(){
	IMG_stream=fopen("fichier","wb");
	write_StartOfimageValues();
	write_APP0Values();
	write_QuantificationCbValues();
	write_QuantificationCrValues();
	write_SOFValues();
	write_EndOfImageValues();
	fclose(IMG_stream);
}
