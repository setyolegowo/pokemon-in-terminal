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
 * Nama File            : listofmonster.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
 
#ifndef __LISTOFMONSTER_H
#define __LISTOFMONSTER_H

#include <iostream>
#include <fstream>
#include <list>
#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

class ListOfMonster
{
    private:
		const unsigned int MaxMonsterList;
        Monster * tabelMonster;
		int nMonster;
    public:
        ListOfMonster();
        ~ListOfMonster();
        ListOfMonster(const ListOfMonster&);
        ListOfMonster operator=(const ListOfMonster&);
		//void readFromFile(Monster*, int);
		int getNMonster();
		void tulisMonster(int);
		void LookUpTableMonster();
};

#endif // __LISTOFMONSTER_H
