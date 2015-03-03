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
 * Nama File            : playermonster.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __PLAYERMONSTER_H
#define __PLAYERMONSTER_H
#include "efektype.h"
#include "skill.h"
#include "monster.h"
#include <stdio.h>
#include <stdlib.h>
#include "listofskill.h"
#include <list>

class PlayerMonster: public Monster
{
    private:
        const unsigned int MaxNameLength;
		const unsigned int MaxMove;
        unsigned int MonsterNumber;
        char* Name;
        unsigned int CurAge;
        unsigned int CurLevel;
        unsigned int CurExp;
		unsigned int ExpMax;
        unsigned int TotalExp;
        unsigned int IncHP;
        unsigned int HP;
        unsigned int IncAttack;
		unsigned int Attack;
        unsigned int IncDefense;
		unsigned int Defense; 
        unsigned int IncSpeed;
		unsigned int Speed; 
        int* Skills; 
        int* PPOfSkills;
        int StatusEffect;
		char NameOfStatusEffect[11];
    public:
        PlayerMonster();
		PlayerMonster(unsigned int, char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int*, int*, int);
		PlayerMonster(unsigned int, char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, int, int, int, int, int, int, int, int, int);
        ~PlayerMonster();		
        PlayerMonster(const PlayerMonster&);
        PlayerMonster operator=(const PlayerMonster&);
        void ChangeNumberMonster(int);
        void ChangeName(char*);
        void IncAge(int);
        void AddExp(unsigned int);
        void IncLevel();
        void RestoreHP();
        void ChangeHP(int); 
        void IncState(int,int);
        void RestorePP(int, ListOfSkill*);
        void RestoreAllPP(ListOfSkill *);
		void DecreasePP(int);
        void ChangeEffect(int);
		
		unsigned int getMonsterNumber();
		char* getName();
		unsigned int getCurAge();
		unsigned int getCurLevel();
		unsigned int getCurExp();
		unsigned int getExpMax();
		unsigned int getTotalExp();
		unsigned int getIncHP();
		unsigned int getHP();
		unsigned int getIncAttack();
        unsigned int getAttack();
		unsigned int getIncDefense();
        unsigned int getDefense();
		unsigned int getIncSpeed();
        unsigned int getSpeed();
		int* getSkills();	
		int getSkill(int);
		int* getPPOfSkills();
		int getPPOfSkill(int);
		int getStatusEffect();
        char* getStatusEffectName(); 
		void tulisPM();
};

#endif // __PLAYERMONSTER_H
