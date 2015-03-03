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
 
#include "playerofmonster.h"
 
//Default constructor belum dibuat
PlayerMonster::PlayerMonster() : MaxNameLength(10);

//Destructor
PlayerMonster::~PlayerMonster() {
	delete [] Name;
	delete [] Skills;
	delete [] PPOfSkills;
}

//Copy Constructor
PlayerMonster::PlayerMonster(const PlayerMonster& P) {
	this->MonsterNumber = P.MonsterNumber;	
	this->CurAge = P.CurAge;
	this->CurLevel = P.CurLevel;
	this->CurExp = P.CurExp;
	this->TotalExp = P.TotalExp;
	this->IncHP = P.IncHP;
	this->HP = P.HP;
	this->IncAttack = P.IncAttack;
	this->IncDefense = P.IncDefense;
	this->IncSpeed = P.IncSpeed;
	this->StatusEffect = P.StatusEffect;
	
	this->MaxNameLength = P.MaxNameLength;
	Name = new char[MaxNameLength];
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = P.Name[i];
	}
	
	this->MaxMove = P.MaxMove;
	Skills = new Skill[MaxMove];
	for (int i=0;i<=MaxMove;i++) {
		this->Skills[i] = P.Skills[i];
	}
	
	PPOfSkills = new char[MaxMove];
	for (int i=0;i<=MaxMove;i++) {
		this->PPOfSkills[i] = P.PPOfSkills[i];
	}
	
return *this;
}


PlayerMonster PlayerMonster::operator=(const PlayerMonster&) {
	this->MaxNameLength = P.MaxNameLength;
	this->MaxMove = P.MaxMove;
	this->MonsterNumber = P.MonsterNumber;	
	this->CurAge = P.CurAge;
	this->CurLevel = P.CurLevel;
	this->CurExp = P.CurExp;
	this->TotalExp = P.TotalExp;
	this->IncHP = P.IncHP;
	this->HP = P.HP;
	this->IncAttack = P.IncAttack;
	this->IncDefense = P.IncDefense;
	this->IncSpeed = P.IncSpeed;
	this->StatusEffect = P.StatusEffect;
	
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = P.Name[i];
	}
	
	Skills = new Skill[MaxMove];
	for (int i=0;i<=MaxMove;i++) {
		this->Skills[i] = P.Skills[i];
	}
	
	PPOfSkills = new char[MaxMove];
	for (int i=0;i<=MaxMove;i++) {
		this->PPOfSkills[i] = P.PPOfSkills[i];
	}
	
return *this;
}

void PlayerMonster::ChangeName(char* N) {
	for (int i=0;i<=MaxNameLength;i++) {
		this->Name[i] = N[i];
	}
    // Isi karakter kosong untuk sisa arraynya.
}

void PlayerMonster::AddExp(unsigned int N) {
	this->CurExp += N;
	this->TotalExp += N;
}

void PlayerMonster::IncLevel() {
	this->CurLevel++;
}

void PlayerMonster::RestoreHP() {
		this->HP = HPMax;
}

void PlayerMonster::IncState(char P,char N) {
	if (P == '1')
		HP += N;
	else if (P == '2')
		Attack += N;
	else if (P == '3')
		Defense += N;
	else if (P == '4')
		Speed += N;	
}

void PlayerMonster::RestorePP(char C) {
	this->PP = PPMax;
}

unsigned int PlayerMonster::getMonsterNumber();
{
	return MonsterNumber;
}

char* PlayerMonster::getName();
{
	return Name;
}

unsigned int PlayerMonster::getCurAge();
{
	return CurAge;
}

unsigned int PlayerMonster::getCurLevel();
{
	return CurLevel;
}

unsigned int PlayerMonster::getCurExp();
{
	return CurExp;
}

unsigned int PlayerMonster::getTotalExp();
{
	return TotalExp
}

unsigned short PlayerMonster::getIncHP
{
	return IncHP;
}
unsigned short PlayerMonster::getHP();
{
	return HP;
}

unsigned short PlayerMonster::getIncAttack();
{
	return IncAttack;
}

unsigned short PlayerMonster::getIncDefense();
{
	return IncDefense;
}

unsigned short PlayerMonster::getIncSpeed();
{
	return IncSpeed;
}

Skill* PlayerMonster::getSkills();
{
	return Skills;\
}

int* PlayerMonster::getPPOfSkills();
{
	return PPOfSkills;
}

EffectType PlayerMonster::getStatusEffect();
{
	return StatusEffect;
}
