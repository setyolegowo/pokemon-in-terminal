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

using std::list;

class ListOfMonster
{
    private:
		const unsigned int MaxMonsterList;
        list<Monster> tabelMonster;
		int nMonster;
		const unsigned int MaxLevelMonster;
		const unsigned int MinLevelMonster;
    public:
        ListOfMonster();
        ~ListOfMonster();
        ListOfMonster(const ListOfMonster&);
        ListOfMonster operator=(const ListOfMonster&);
		int getNMonster();
        Monster& getMonster(int);		
		//void LookUpTableMonster();
		//void printMonsterNoX(int);
};

#endif // __LISTOFMONSTER_H
