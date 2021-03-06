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

class Monster
{
    private:
        const unsigned char MaxSpesiesLength;
        const unsigned char MaxMove;
        unsigned int Age;        
        unsigned int MonsterNumber;
        char *Spesies;
        ElemenType Elemen0;
        ElemenType Elemen1;
        unsigned int HP;
        unsigned int Attack;
        unsigned int Defense;
        unsigned int Speed;
        unsigned char DefaultLevel;
        unsigned char * DefaultSkills;
        unsigned char IsCombined;
        unsigned char NextEvolutionLevel;
        unsigned int NextEvoNo;
    public:
        Monster();
        ~Monster();
        Monster(const Monster&);
        Monster operator= (const Monster&);
};

#endif // __MONSTER_H