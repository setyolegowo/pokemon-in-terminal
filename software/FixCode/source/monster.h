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
 * Nama File            : monster.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __MONSTER_H
#define __MONSTER_H

#include "elementype.h"
#include "skill.h"
#include <stdio.h>

class Monster
{
    private:
        const unsigned int MaxSpesiesLength;
        const unsigned int MaxMove;
        unsigned int Age;        
        unsigned int MonsterNumber;
        char *Spesies;
		ElemenType Elemen0;
		ElemenType Elemen1;
        unsigned int HP;
        unsigned int Attack;
        unsigned int Defense;
        unsigned int Speed;
        unsigned int DefaultLevel;
        unsigned int *DefaultSkills;
        unsigned int IsCombined;
        unsigned int NextEvolutionLevel;
        unsigned int NextEvoNo;
		char NameOfElemen1[10];
		char NameOfElemen2[10];
    public:
        Monster();
		Monster(unsigned int, char *, ElemenType, ElemenType, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int *, unsigned int, unsigned int, unsigned int);
        ~Monster();
        Monster(const Monster&);
        Monster operator= (const Monster&);
		
		unsigned int getMonsterNumber();
		char* getSpesies();
		ElemenType getElemen0();
		ElemenType getElemen1();        
		unsigned int getHP();
		unsigned int getAttack();
		unsigned int getDefense();
		unsigned int getSpeed();
		unsigned int getDefaultLevel();
		unsigned int getDefaultSkills(int);
		unsigned int getDefaultSkills1();
		unsigned int getDefaultSkills2();
		unsigned int getDefaultSkills3();
		unsigned int getDefaultSkills4();
		unsigned int getIsCombined();
		unsigned int getNextEvolutionLevel();
		unsigned int getNextEvoNo();
		char* getNameElemen1();
		char* getNameElemen2();
		
		void tulisMonster();
};

#endif // __MONSTER_H