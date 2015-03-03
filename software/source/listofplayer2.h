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
 * Nama File            : listofplayer2.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __LISTOFPLAYER2_H
#define __LISTOFPLAYER2_H

#include <iostream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "player.h"

using namespace std;

class ListOfPlayer
{
	private:
		list<Player> tabelPlayer;
	public:
		ListOfPlayer();
		~ListOfPlayer();
		ListOfPlayer(const ListOfPlayer&);
		ListOfPlayer &operator=(ListOfPlayer&);
		void ReadFromFile();
		void PrintList();
		void DataList(int);	
};

#endif // __LISTOFPLAYER2_H