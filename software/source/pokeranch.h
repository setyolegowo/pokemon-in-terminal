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
 * Nama File            : pokeranch.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#ifndef __POKERANCH_H
#define __POKERANCH_H

#include "listofskill.h"
#include "listofitem.h"
#include "listofmonster.h"
#include "listofplayer.h"
#include "area.h"
#include "player.h"
#include "outerarea.h"
#include "city.h"

class PokeRanch
{
    private:
        ListOfSkill listSkill;
        ListOfItem listItem;
        ListOfMonster listMonster;
        ListOfPlayer listPlayer;
        Player Trainer;
        OuterArea outerArea;
        City city;
    public:
        PokeRanch();
        ~PokeRanch();
        PokeRanch(const PokeRanch&);
        PokeRanch &operator= (PokeRanch&);
        void Start();
        void LookTable();
        void BattleWild(unsigned char*);
        void BattleStadium(unsigned char*, unsigned int);
};

#endif // __POKERANCH_H