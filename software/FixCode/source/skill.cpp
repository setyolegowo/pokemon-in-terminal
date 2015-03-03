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
 * Nama File            : skill.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Kamis, 14 Maret 2013
 * Deskripsi            : 
 * - 
 */
 

#include "elementype.h"
#include "powereffect.h"
#include "efektype.h"
#include "skill.h"
using namespace std;



Skill::Skill(): MaxNameLength(20)
{
    Name = new char[MaxNameLength];
	Name[0] = 'U';
	Name[1] = 'n';
	Name[2] = 'k';
	Name[3] = 'n';
	Name[4] = 'o';
	Name[5] = 'w';
	Name[6] = 'n';
	Name[7] = ' ';
	Name[8] = 'S';
	Name[9] = 'k';
	Name[10] = 'i';
	Name[11] = 'l';
	Name[12] = 'l';
	Name[13] = '\0';
    StrWeak = new int[2];
}
Skill::Skill(unsigned int _SkillNumber,char* _Name,int _Target,int _Element,int * _StrWeak,short _Power,int _PowerEffect, int _AccuracySkill, int _Effect, float _ProsenEfek, int _PPMax):MaxNameLength(20)
{
	SkillNumber=_SkillNumber;
	Name = new char[MaxNameLength];
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=_Name[i];
	}
	if(_Target == 0)
        Target = Self;
    else
        Target = Foo;
	switch(_Element)
    {
        case 1: Element = Psychic; break;
        case 2: Element = Fight; break;
        case 3: Element = Normal; break;
        case 4: Element = Water; break;
        case 5: Element = Grass; break;
        case 6: Element = Ground; break;
        case 7: Element = Flying; break;
        case 8: Element = Ice; break;
        case 9: Element = Electric; break;
        case 10: Element = Dragon; break;
    }
	StrWeak = new int[2];
	StrWeak[0]=_StrWeak[0];
	StrWeak[1]=_StrWeak[1];
	Power=_Power;
	switch(_PowerEffect)
    {
        case 0: PowerEffect = HP; break;
        case 1: PowerEffect = Attack; break;
        case 2: PowerEffect = Defense; break;
        case 3: PowerEffect = Speed; break;
        case 4: PowerEffect = Accuracy; break;
    }
	AccuracySkill=_AccuracySkill;
	switch(_Effect)
    {
        case 0: Effect = NoEffect; break;
        case 1: Effect = Paralyz; break;
        case 2: Effect = Poison; break;
        case 3: Effect = BadPoison; break;
        case 4: Effect = Burn; break;
        case 5: Effect = Freeze; break;
        case 6: Effect = Sleep; break;
    }
	ProsenEfek=_ProsenEfek;
	PPMax=_PPMax;
}
Skill::~Skill()
{
	delete [] Name;
	delete [] StrWeak;
}

Skill::Skill(const Skill& S):MaxNameLength(S.MaxNameLength)
{
	SkillNumber=S.SkillNumber;
	Name = new char[MaxNameLength];
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=S.Name[i];
	}
	Target=S.Target;
	Element=S.Element;
	StrWeak = new int[2];
	for (int i=0;i<=1;i++)
	{	
		StrWeak[i]=S.StrWeak[i];
	}
	Power=S.Power;
	PowerEffect=S.PowerEffect;
	AccuracySkill=S.AccuracySkill;
	Effect=S.Effect;
	ProsenEfek=S.ProsenEfek;
	PPMax=S.PPMax;
}

Skill& Skill::operator= (Skill& S)
{
	delete [] Name;
    SkillNumber=S.SkillNumber;
	Name = new char[MaxNameLength];
	for (int i=0;i<=MaxNameLength;i++)
	{	
		Name[i]=S.Name[i];
	}
	Target=S.Target;
	Element=S.Element;
	StrWeak = new int[2];
	for (int i=0;i<=1;i++)
	{	
		StrWeak[i]=S.StrWeak[i];
	}
	Power=S.Power;
	PowerEffect=S.PowerEffect;
	AccuracySkill=S.AccuracySkill;
	Effect=S.Effect;
	ProsenEfek=S.ProsenEfek;
	PPMax=S.PPMax;
	return *this;
}

int Skill::GetSkillNumber()
{
	return SkillNumber;
}
char* Skill::GetName()
{
	return Name;
}

int Skill::GetTarget()
{
	return Target;
}

ElemenType Skill::GetElement()
{
	return Element;
}

ElemenType Skill::GetStrWeak(int i)
{
	if(i == 1)
	{
		switch(StrWeak[0])
		{
		case 0: return _NULL; break;
		case 1: return Psychic; break;
        case 2: return Fight; break;
        case 3: return Normal; break;
        case 4: return Water; break;
        case 5: return Grass; break;
        case 6: return Ground; break;
        case 7: return Flying; break;
        case 8: return Ice; break;
        case 9: return Electric; break;
        case 10: return Dragon; break;
		}
	}
    else if(i == 2)
        switch(StrWeak[1])
		{
		case 0: return _NULL; break;
		case 1: return Psychic; break;
        case 2: return Fight; break;
        case 3: return Normal; break;
        case 4: return Water; break;
        case 5: return Grass; break;
        case 6: return Ground; break;
        case 7: return Flying; break;
        case 8: return Ice; break;
        case 9: return Electric; break;
        case 10: return Dragon; break;
		}
    //else
    //    throw(4);
}

short Skill::GetPower()
{
	return Power;
}

PE Skill::GetPowerEffect()
{
	return PowerEffect;
}

unsigned int Skill::GetAccuracy()
{
	return AccuracySkill;
}

EffectType Skill::GetEffect()
{
	return Effect;
}

float Skill::GetProsenEfek()
{
	return ProsenEfek;
}

unsigned int Skill::GetPPMax()
{
	return PPMax;
}