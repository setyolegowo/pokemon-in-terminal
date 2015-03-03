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
 * Nama File            : arealuar.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 //Created by Fawwaz

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "outerarea.h"

using namespace std;

OuterArea::OuterArea():MaxMonsterAppear(10),MonsterLevelMin(3),FloorLevelMaks(10)
{
	CurrentFL=0;
	srand(time(NULL));
	CrMonsterPoint = new Point[MaxMonsterAppear];
	CrMonsterAppear = 10;
	//Lokasi teleport yang diinginkan
	TeleportPositionBefore.SetX(0);
	TeleportPositionBefore.SetY(8);
	TeleportPositionAfter.SetX(38);
	TeleportPositionAfter.SetY(8);
}
OuterArea::~OuterArea(){}
// OuterArea(const OuterArea&){}
// OuterArea &operator= (OuterArea&){}
// void Battle(){}

void OuterArea::SetCrMonsterPoint(unsigned char _Idx,unsigned char _x, unsigned char _y)
{
	CrMonsterPoint[_Idx].SetX(_x);
	CrMonsterPoint[_Idx].SetY(_y);
}

void OuterArea::RandomUnstapable() // Mengacak-acak array area yang merepresentasikan stepable or not
{
	int temp;
	int size=int(GetHeight()-1)*int(GetWidth()-1); // minus satu karena C++ memulai indeks dari angka 0
	for (int i = 0; i < GetMaxUnstapablePoint(); ++i)
	{
		temp = rand() % size;
		area[temp]=1;
	}
		
}
void OuterArea::RandomMonster()
{
	int temp;
	srand(time(NULL));
	int size=int(GetHeight()-1)*int(GetWidth()-1); // minus satu karena C++ memulai indeks dari angka 0
	for (int i = 0; i < MaxMonsterAppear; ++i)
	{	
		temp = rand() % size;
		area[temp]=2; 
		int temporary;
		Point P2(ConvertIdxAreaToPoint(temp));
		SetCrMonsterPoint(i,P2.GetX(),P2.GetY());
	
	}

}

void OuterArea::DrawTeleport()
{
	int tempidx=ConvertPointToIdxArea(TeleportPositionBefore);	
	area[tempidx]=9;
	tempidx=ConvertPointToIdxArea(TeleportPositionAfter);	
	area[tempidx]=10; // array started with 0
}


bool OuterArea::IsBattleWithMonster(){
	// indeks 4 dalam array area berarti monster 
	int tempidx=ConvertPointToIdxArea(PlayerPosition);
	printf("Ini indeksnya %d\n", tempidx);
	printf("area ini isinya %d\n",area[tempidx]);
	return area[tempidx]==2;
}

unsigned char OuterArea::ValidTeleport(){
	int tempidx=ConvertPointToIdxArea(PlayerPosition);	
	return area[tempidx];
}

int OuterArea::GetFloorLevel(){return CurrentFL;}
void OuterArea::ChangeFloorLevel(int i){ CurrentFL=i;}
