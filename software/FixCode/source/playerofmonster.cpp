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
 
//Default constructor
// MaxNameLength jangan gede-gede, 8 aja cukup
PlayerMonster::PlayerMonster(): MaxNameLength(15), MaxMove(4) {
	MonsterNumber = 0;
	Name = new char[MaxNameLength];
	Name[0] = 'U';
	Name[1] = 'n';
	Name[2] = 'k';
	Name[3] = 'n';
	Name[4] = 'o';
	Name[5] = 'w';
	Name[6] = 'n';
	Name[7] = '\0';
	CurAge = 0;
	CurLevel = 0;
	CurExp = 0;
	ExpMax = 0;
	TotalExp = 0;
	IncHP = 0;
	HP = 0;
	IncAttack = 0;
	Attack = 0;
	IncDefense = 0;
	Defense = 0;
	IncSpeed = 0;
	Speed = 0;	
	Skills = new int[MaxMove];
	Skills[0] = 0;
	Skills[1] = 0;
	Skills[2] = 0;
	Skills[3] = 0;
	PPOfSkills = new int[MaxMove];
	PPOfSkills[0] = 0;
	PPOfSkills[1] = 0;
	PPOfSkills[2] = 0;
	PPOfSkills[3] = 0;
	StatusEffect = 0;
}
//Constructor dengan parameter
PlayerMonster::PlayerMonster(unsigned int NoMons, char* NameMons, unsigned int AgeMon, unsigned int CurLevelMon, unsigned int CurExpMon, unsigned int ExpMaxMon, unsigned int TotalExpMon, unsigned int IncHPMon, unsigned int HPMon, unsigned int IncAttackMon, unsigned int AttackMon, unsigned int IncDefenseMon, unsigned int DefenseMon, unsigned int IncSpeedMon, unsigned int SpeedMon, int* SkillMon, int* PPOfSkillsMon, int EffectMon): MaxNameLength(60), MaxMove(4) {
	MonsterNumber = NoMons;
	CurAge = AgeMon;
	CurLevel = CurLevelMon;
	CurExp = CurExpMon;
	ExpMax = ExpMaxMon;
	TotalExp = TotalExpMon;
	IncHP = IncHPMon;
	HP = HPMon;
	IncAttack = IncAttackMon;
	Attack = AttackMon;
	IncDefense = IncDefenseMon;
	Defense = DefenseMon;
	IncSpeed = IncSpeedMon;	
	Speed = SpeedMon;
	StatusEffect = EffectMon;
	
	Name = new char[MaxNameLength];
	for (int i=0;i<MaxNameLength;i++)
		Name[i]=NameMons[i];
		
	Skills = new int[MaxMove];
	for (int i=0;i<MaxMove;i++)
		Skills[i] = SkillMon[i];
	
	PPOfSkills = new int[MaxMove];
	for (int i=0;i<MaxMove;i++)
		PPOfSkills[i] = PPOfSkillsMon[i];
}

PlayerMonster::PlayerMonster(unsigned int NoMons, char* NameMons, unsigned int AgeMon, unsigned int CurLevelMon, unsigned int CurExpMon, unsigned int ExpMaxMon, unsigned int TotalExpMon, unsigned int IncHPMon, unsigned int HPMon, unsigned int IncAttackMon, unsigned int AttackMon, unsigned int IncDefenseMon, unsigned int DefenseMon, unsigned int IncSpeedMon, unsigned int SpeedMon, int Skill1, int Skill2, int Skill3, int Skill4, int PPOfSkillsMon1, int PPOfSkillsMon2, int PPOfSkillsMon3, int PPOfSkillsMon4, int EffectMon): MaxNameLength(60), MaxMove(4) {
	MonsterNumber = NoMons;
	CurAge = AgeMon;
	CurLevel = CurLevelMon;
	CurExp = CurExpMon;
	ExpMax = ExpMaxMon;
	TotalExp = TotalExpMon;	
	IncHP = IncHPMon;
	HP = HPMon;
	IncAttack = IncAttackMon;
	Attack = AttackMon;
	IncDefense = IncDefenseMon;
	Defense = DefenseMon;
	IncSpeed = IncSpeedMon;	
	Speed = SpeedMon;
	StatusEffect = EffectMon;		

	Name = new char[MaxNameLength];
	for (int i=0;i<MaxNameLength;i++)
		Name[i]=NameMons[i];
		
	Skills = new int[MaxMove];
	Skills[0] = Skill1;
	Skills[1] = Skill2;
	Skills[2] = Skill3;
	Skills[3] = Skill4;
	
	PPOfSkills = new int[MaxMove];
	PPOfSkills[0] = PPOfSkillsMon1;
	PPOfSkills[1] = PPOfSkillsMon2;
	PPOfSkills[2] = PPOfSkillsMon3;
	PPOfSkills[3] = PPOfSkillsMon4;
}

//Destructor
PlayerMonster::~PlayerMonster() {
	delete [] Name;
	delete [] Skills;
	delete [] PPOfSkills;
}

//Copy Constructor
PlayerMonster::PlayerMonster(const PlayerMonster& P): MaxNameLength(P.MaxNameLength), MaxMove(P.MaxMove) {
	this->MonsterNumber = P.MonsterNumber;	
	this->CurAge = P.CurAge;
	this->CurLevel = P.CurLevel;
	this->CurExp = P.CurExp;
	this->ExpMax = P.ExpMax;
	this->TotalExp = P.TotalExp;
	this->IncHP = P.IncHP;
	this->HP = P.HP;
	this->IncAttack = P.IncAttack;
	this->Attack = P.Attack;
	this->IncDefense = P.IncDefense;
	this->Defense = P.Defense;
	this->IncSpeed = P.IncSpeed;
	this->Speed = P.Speed;
	this->StatusEffect = P.StatusEffect;
	
	Name = new char[MaxNameLength];
	for (int i=0;i<MaxNameLength;i++) {
		this->Name[i] = P.Name[i];
	}
	
	Skills = new int[MaxMove];
	for (int i=0;i<MaxMove;i++) {
		
		this->Skills[i] = P.Skills[i];
	}
	
	PPOfSkills = new int[MaxMove];
	for (int i=0;i<MaxMove;i++) {
		this->PPOfSkills[i] = P.PPOfSkills[i];
	}
}

PlayerMonster PlayerMonster::operator=(const PlayerMonster& P) {
	this->MonsterNumber = P.MonsterNumber;	
	this->CurAge = P.CurAge;
	this->CurLevel = P.CurLevel;
	this->CurExp = P.CurExp;
	this->ExpMax = P.ExpMax;
	this->TotalExp = P.TotalExp;
	this->IncHP = P.IncHP;
	this->HP = P.HP;
	this->IncAttack = P.IncAttack;
	this->Attack = P.Attack;
	this->IncDefense = P.IncDefense;
	this->Defense = P.Defense;
	this->IncSpeed = P.IncSpeed;
	this->Speed = P.Speed;
	this->StatusEffect = P.StatusEffect;
	
	delete [] Name;
	Name = new char[MaxNameLength];
	for (int i=0;i<MaxNameLength;i++) {
		this->Name[i] = P.Name[i];
	}
	
	delete [] Skills;
	Skills = new int[MaxMove];
	for (int i=0;i<P.MaxMove;i++) {
		this->Skills[i] = P.Skills[i];
	}
	
	delete [] PPOfSkills;
	PPOfSkills = new int[MaxMove];
	for (int i=0;i<P.MaxMove;i++) {
		this->PPOfSkills[i] = P.PPOfSkills[i];
	}
	
return *this;
}

void PlayerMonster::ChangeName(char* N) {
	int i = 0;
	while (N[i] != '\0') {
		this->Name[i] = N[i];
		i++;
	}
	for (i;i<MaxNameLength;i++)
		Name[i] = '\0';
	
    // Isi karakter kosong untuk sisa arraynya.
}

void PlayerMonster::AddExp(unsigned int N) {
	this->CurExp += N;
	if (CurExp >= ExpMax) {
		CurLevel++;
		CurExp -= ExpMax;
		ExpMax = CurLevel*CurLevel*CurLevel;
	}
	this->TotalExp += N;	
}

void PlayerMonster::IncLevel() {
	this->CurLevel++;
}

void PlayerMonster::RestoreHP() {
	this->HP = 100;
}

void PlayerMonster::IncState(int c1,int c2) {
	if (c1 == 1)
		HP += c2;
	else if (c1 == 2)
		Attack += c2;
	else if (c1 == 3)
		Defense += c2;
	else if (c1 == 4)
		Speed += c2;
}

void PlayerMonster::RestorePP(int PP, ListOfSkill * _ListOfSkill) {
	this->Skills[PP] = _ListOfSkill->GetPPMaxFromNumberSkill(PP);
}
void PlayerMonster::RestoreAllPP(ListOfSkill * _ListOfSkill) {
    for(int i = 0; i < 4; i++)
        this->PPOfSkills[i] = _ListOfSkill->GetPPMaxFromNumberSkill(this->Skills[i]);
}
unsigned int PlayerMonster::getMonsterNumber()
{
	return MonsterNumber;
}

char* PlayerMonster::getName()
{
	return Name;
}

unsigned int PlayerMonster::getCurAge()
{
	return CurAge;
}

unsigned int PlayerMonster::getCurLevel()
{
	return CurLevel;
}

unsigned int PlayerMonster::getCurExp()
{
	return CurExp;
}

unsigned int PlayerMonster::getExpMax()
{
	return ExpMax;
}

unsigned int PlayerMonster::getTotalExp()
{
	return TotalExp;
}

unsigned int PlayerMonster::getIncHP()
{
	return IncHP;
}
unsigned int PlayerMonster::getHP()
{
	return HP;
}

unsigned int PlayerMonster::getIncAttack()
{
	return IncAttack;
}
unsigned int PlayerMonster::getAttack()
{
	return Attack;
}

unsigned int PlayerMonster::getIncDefense()
{
	return IncDefense;
}

unsigned int PlayerMonster::getDefense()
{
	return Defense;
}

unsigned int PlayerMonster::getIncSpeed()
{
	return IncSpeed;
}

unsigned int PlayerMonster::getSpeed()
{
	return Speed;
}

int* PlayerMonster::getSkills()
{
	return Skills;
}

int PlayerMonster::getSkill(int NoSkill)
{
	if (NoSkill == 0)
		return Skills[NoSkill];
	else if (NoSkill == 1)
		return Skills[NoSkill];
	else if (NoSkill == 2)
		return Skills[NoSkill];
	else if (NoSkill == 3)
		return Skills[NoSkill];
	else
		return 0;
}

int PlayerMonster::getPPOfSkill(int PP) {
	if (PP == 0)
		return PPOfSkills[PP];
	else if (PP == 1)
		return PPOfSkills[PP];
	else if (PP == 2)
		return PPOfSkills[PP];
	else if (PP == 3)
		return PPOfSkills[PP];
	else
		return 0;
}

int* PlayerMonster::getPPOfSkills()
{
	return PPOfSkills;
}

int PlayerMonster::getStatusEffect()
{
	return StatusEffect;
}

void PlayerMonster::DecreasePP(int PP) {
	this->PPOfSkills[PP]--;
}

void PlayerMonster::tulisPM() {
	printf("\nNomor monster: %d", MonsterNumber);
	printf("\nNama monster: %s", Name);
	printf("\nUmur monster: %d", CurAge);
	printf("\nLevel monster: %d", CurLevel);
	printf("\nCurrent Exp monster: %d", CurExp);
	printf("\nExp Max monster: %d", ExpMax);	
	printf("\nTotal Exp monster: %d", TotalExp);
	printf("\nIncHP monster: %d", IncHP);
	printf("\nHP monster: %d", HP);
	printf("\nIncAttack monster: %d", IncAttack);
	printf("\nAttack monster: %d", Attack);
	printf("\nIncDefense monster: %d", IncDefense);
	printf("\nDefense monster: %d", Defense);
	printf("\nIncSpeed monster: %d", IncSpeed);
	printf("\nSpeed monster: %d", Speed);
	printf("\nSkill Monster:{%d,%d,%d,%d}", Skills[0], Skills[1], Skills[2], Skills[3]);
	printf("\nPP of Skills monster: {%d,%d,%d,%d}", PPOfSkills[0],PPOfSkills[1],PPOfSkills[2],PPOfSkills[3]);
	printf("\nEffect Type: %d", StatusEffect);	
	printf("\nNama Effect: %s", getStatusEffectName());
	printf("\nSkill 1: %d", getSkill(0));
	printf("\nSkill 1: %d", getSkill(1));
	printf("\nSkill 1: %d", getSkill(2));
	printf("\nSkill 1: %d", getSkill(3));
}

void PlayerMonster::IncAge (int N) {
	this->CurAge += N;
}

void PlayerMonster::ChangeHP (int N) {
	this->HP = N;
}

char* PlayerMonster::getStatusEffectName() {
	if (StatusEffect == 0) {
		NameOfStatusEffect[0] = 'N';
		NameOfStatusEffect[1] = 'o';
		NameOfStatusEffect[2] = 'E';
		NameOfStatusEffect[3] = 'f';
		NameOfStatusEffect[4] = 'f';
		NameOfStatusEffect[5] = 'e';
		NameOfStatusEffect[6] = 'c';
		NameOfStatusEffect[7] = 't';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 1) {
		NameOfStatusEffect[0] = 'P';
		NameOfStatusEffect[1] = 'a';
		NameOfStatusEffect[2] = 'r';
		NameOfStatusEffect[3] = 'a';
		NameOfStatusEffect[4] = 'l';
		NameOfStatusEffect[5] = 'y';
		NameOfStatusEffect[6] = 's';
		NameOfStatusEffect[7] = '\0';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 2) {
		NameOfStatusEffect[0] = 'P';
		NameOfStatusEffect[1] = 'o';
		NameOfStatusEffect[2] = 'i';
		NameOfStatusEffect[3] = 's';
		NameOfStatusEffect[4] = 'o';
		NameOfStatusEffect[5] = 'n';
		NameOfStatusEffect[6] = '\0';
		NameOfStatusEffect[7] = '0';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 3) {
		NameOfStatusEffect[0] = 'B';
		NameOfStatusEffect[1] = 'a';
		NameOfStatusEffect[2] = 'd';
		NameOfStatusEffect[3] = 'P';
		NameOfStatusEffect[4] = 'o';
		NameOfStatusEffect[5] = 'i';
		NameOfStatusEffect[6] = 's';
		NameOfStatusEffect[7] = 'o';
		NameOfStatusEffect[8] = 'n';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 4) {
		NameOfStatusEffect[0] = 'B';
		NameOfStatusEffect[1] = 'u';
		NameOfStatusEffect[2] = 'r';
		NameOfStatusEffect[3] = 'n';
		NameOfStatusEffect[4] = '\0';
		NameOfStatusEffect[5] = '\0';
		NameOfStatusEffect[6] = '\0';
		NameOfStatusEffect[7] = '\0';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 5) {
		NameOfStatusEffect[0] = 'F';
		NameOfStatusEffect[1] = 'r';
		NameOfStatusEffect[2] = 'e';
		NameOfStatusEffect[3] = 'e';
		NameOfStatusEffect[4] = 'z';
		NameOfStatusEffect[5] = 'e';
		NameOfStatusEffect[6] = '\0';
		NameOfStatusEffect[7] = '\0';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
	else if (StatusEffect == 6) {
		NameOfStatusEffect[0] = 'S';
		NameOfStatusEffect[1] = 'l';
		NameOfStatusEffect[2] = 'e';
		NameOfStatusEffect[3] = 'e';
		NameOfStatusEffect[4] = 'p';
		NameOfStatusEffect[5] = '\0';
		NameOfStatusEffect[6] = '\0';
		NameOfStatusEffect[7] = '\0';
		NameOfStatusEffect[8] = '\0';
		NameOfStatusEffect[9] = '\0';
		NameOfStatusEffect[10] = '\0';
		NameOfStatusEffect[11] = '\0';
		return NameOfStatusEffect;
	}
}
void PlayerMonster::ChangeEffect(int i) {
    StatusEffect = i;
}
void PlayerMonster::ChangeNumberMonster(int i) {
    MonsterNumber = i;
}