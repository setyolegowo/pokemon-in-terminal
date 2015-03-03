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
 * Nama File            : skill.h
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */
 
#ifndef __SKILL_H
#define __SKILL_H
 
#include "elementype.h"
#include "efektype.h"
#include "powereffect.h"

class Skill
{
    private:
        const unsigned char MaxNameLength;
        unsigned int PPMax;
        int SkillNumber;
        char *Name;
        enum TargetType {Self, Foo} Target;
        ElemenType Element;
        int *StrWeak;
        short Power;
        PE PowerEffect;
        unsigned int AccuracySkill;
        EffectType Effect;
        float ProsenEfek;
    public:
        Skill();
		Skill(unsigned int, char*, int, int, int*,short, int, int, int, float,int);
		~Skill();
        Skill(const Skill&);
        Skill &operator= (Skill&);
		int GetSkillNumber();
		char* GetName();
		int GetTarget();
		ElemenType GetElement();
		ElemenType GetStrWeak(int);
		short GetPower();
		PE GetPowerEffect();
		unsigned int GetAccuracy();
		EffectType GetEffect();
		float GetProsenEfek();
		unsigned int GetPPMax();
};

#endif // __SKILL_H