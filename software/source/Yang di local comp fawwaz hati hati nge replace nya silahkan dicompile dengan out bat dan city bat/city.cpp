/* ************************************************************************** */
/*                                  POKERANCH                                 */
/* ************************************************************************** */

/*
 * Nama / NIM           : Lubis Sucipto / 13511025
 *                        Muhammad Rizky W / 13511037
 *                        Andreas Dwi Nugroho / 13511051
 *                        Setyo Legowo / 13511071
 *                        Fawwaz Muhammad / 13511083
 *                        Asep Saepudin / 13511093
 * Nama File            : city.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 // Created by Fawwaz

#include <iostream>
#include <stdio.h>
#include "city.h"

using namespace std; 

City::City():MaxNameLength(50),NBuilding(8)
{

}

City::~City()
{
	// adfa
}

City::City(const City& C):MaxNameLength(50),NBuilding(8)
{
	// NamaCity
}
City& City::operator= (City&){}

void City::FixUnstapableArea(){

	// Configurable  here
	unsigned char Wstadium,HStadium,HHome,WHome,WCombinatorium,HCombinatorium,WStore,HStore;
	unsigned char WJembatan1,HJembatan1,WJembatan2,HJembatan2;
	unsigned char WTeleArea,HTeleArea;
	unsigned char OffsetXStadium,OffsetYStadium,OffsetXHome,OffsetYHome;
	unsigned char OffsetXCombinatorium,OffsetYCombinatorium,OffsetXStore;
	unsigned char OffsetYStore,OffsetXJembatan,OffsetXTele,OffsetYTele;
	unsigned char offxdoorstadium,offydoorstadium,wdoorstadium,hdoorstadium;
	unsigned char offxdoorhome,offydoorhome,wdoorhome,hdoorhome;
	unsigned char offxdoorcombinatorium,offydoorcombinatorium,wdoorcombinatorium,hdoorcombinatorium;
	unsigned char offxdoorstore,offydoorstore,wdoorstore,hdoorstore;
	// 
	//------------configure start-----
	Wstadium=7;
	HStadium=4;
	OffsetXStadium=0;
	OffsetYStadium=0;
	offxdoorstadium=7;
	offydoorstadium=1;
	wdoorstadium=1;
	hdoorstadium=2;

	WHome=5;
	HHome=6;
	OffsetXHome=0;
	OffsetYHome=3;
	offxdoorhome=5;
	offydoorhome=6;
	wdoorhome=1;
	hdoorhome=2;

	WCombinatorium=9;
	HCombinatorium=4;
	OffsetXCombinatorium=13;
	OffsetYCombinatorium=5;
	offxdoorcombinatorium=17;
	offydoorcombinatorium=4;
	wdoorcombinatorium=3;
	hdoorcombinatorium=1;

	WStore=5;
	HStore=6;
	OffsetXStore=21;
	OffsetYStore=3;
	offxdoorstore=26;
	offydoorstore=4;
	wdoorstore=1;
	hdoorstore=2;


	WTeleArea=3;
	HTeleArea=3;
	OffsetXTele=35;
	OffsetYTele=3;
	//------------end configuration---

	
	
	
	//----------------------------------

	unsigned char j,i; // pointer current


	PrintBuilding(OffsetXStadium,OffsetYStadium,Wstadium,HStadium,1,false);
	PrintBuilding(offxdoorstadium,offydoorstadium,wdoorstadium,hdoorstadium,6,false);

	PrintBuilding(OffsetXCombinatorium,OffsetYCombinatorium,WCombinatorium,HCombinatorium,1,false);
	PrintBuilding(offxdoorcombinatorium,offydoorcombinatorium,wdoorcombinatorium,hdoorcombinatorium,5,false);

	PrintBuilding(OffsetXHome,OffsetYHome,WHome,HHome,1,false);
	PrintBuilding(offxdoorhome,offydoorhome,wdoorhome,hdoorhome,4,false);

	PrintBuilding(OffsetXStore,OffsetYStore,WStore,HStore,1,false);
	PrintBuilding(offxdoorstore,offydoorstore,wdoorstore,hdoorstore,7,false);

	PrintBuilding(OffsetXTele,OffsetYTele,WTeleArea,HTeleArea,4,true);




}

void City::PrintBuilding(unsigned char OffsetX,unsigned char OffsetY,unsigned char Width,unsigned char Height,unsigned char Type,bool fill)
{
	int i,j;
	// Start building the block
	if(!fill){
		i=OffsetX;
		for (j = OffsetY; j < (OffsetY+Height); ++j)
		{
			area[(i+GetWidth()*j)]=Type;
		}

		i=i+Width-1;//indeks array dimulai dari 0
		for (j = OffsetY; j < (OffsetY+Height); ++j)
		{
			area[(i+GetWidth()*j)]=Type;
		}

		//==================Garis horizontal ====================

		j=OffsetY*GetWidth();
		for (i = OffsetX; i < (OffsetX+Width); ++i)
		{
			area[(j+i)]=Type;
		}

		j=(OffsetY+Height-1)*GetWidth();
		for (i = OffsetX; i < (OffsetX+Width); ++i)
		{
			area[(j+i)]=Type;
		}


		// Filling the rest with empty space
		int tempy;
		i=OffsetX;
		for (j = OffsetY+1; j < (OffsetY+Height-1); ++j)
		{
			tempy=j*GetWidth();
			for (i = OffsetX+1; i < (OffsetX+Width-1); ++i)
			{
				area[(tempy+i)]=255;
			}
		}
	}else{
		int tempy;
		i=OffsetX;
		for (j = OffsetY; j < (OffsetY+Height); ++j)
		{
			tempy=j*GetWidth();
			for (i = OffsetX; i < (OffsetX+Width); ++i)
			{
				area[(tempy+i)]=Type;
			}
		}
	}


}




unsigned char City::ValidTeleport(){
	// indeks 4 dalam array area berarti teleport position
	int tempidx=ConvertPointToIdxArea(PlayerPosition);
	printf(" marnisa manis\n");
	printf("Ini 2LastStepped %d\n", LastStepped);
	printf("ini 2Stepped %d \n", stepped);
	// printf("area ini isinya %d\n",area[tempidx]);
	return area[tempidx];
}

// virtual void PrintMap(){}