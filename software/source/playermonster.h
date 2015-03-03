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
        Skill* Skills;
        int* PPOfSkills;
        EffectType StatusEffect;
    public:
        PlayerMonster();
		PlayerMonster(unsigned int, char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Skill*, int*, EffectType);
		PlayerMonster(unsigned int, char*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, Skill, Skill, Skill, Skill, int*, EffectType);
        ~PlayerMonster();		
        PlayerMonster(const PlayerMonster&);
        PlayerMonster operator=(const PlayerMonster&);
        void ChangeName(char*);
        void AddExp(unsigned int);
        void IncLevel();
        void RestoreHP();
        void IncState(char,char);
        void RestorePP(char);
		
		unsigned int getMonsterNumber();
		char* getName();
		unsigned int getCurAge();
		unsigned int getcurLevel();
		unsigned int getCurExp();
		unsigned int getExpMax();
		unsigned int getTotalExp();
		unsigned int getIncHP();
		unsigned int getHP();
		unsigned int getIncAttack();
		unsigned int getIncDefense();
		unsigned int getIncSpeed();
		Skill* getSkills();
		int* getPPOfSkills();
		EffectType getStatusEffect();
};

#endif // __PLAYERMONSTER_H
