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
 
#ifndef __AREALUAR_H
#define __AREALUAR_H

// #include "point.h"
#include "area.h"

class OuterArea:public Area
{
    private:
        const unsigned char FloorLevelMaks;
        const unsigned char MonsterLevelMin;
        const unsigned char MaxMonsterAppear;
        
        unsigned int CurrentFL;
        Point *CrMonsterPoint;
        unsigned char CrMonsterAppear; // Range MonsterAppear [0..MaxMonsterAppear]
        Point TeleportPositionBefore;
        Point TeleportPositionAfter;
    public:
        OuterArea();
        ~OuterArea();
        OuterArea(const OuterArea&);
        OuterArea &operator= (OuterArea&);


        void Battle();
        void RandomUnstapable();
        void RandomMonster();
        void SetCrMonsterPoint(unsigned char,unsigned char,unsigned char);
        bool IsBattleWithMonster();
        void DrawTeleport();

        int GetFloorLevel();
        void ChangeFloorLevel(int);
        unsigned char ValidTeleport();

        
};

#endif // __AREALUAR_H