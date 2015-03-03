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
 
#include "monster.h"


//Default constructor belum dibuat
Monster::Monster(void) : MaxSpesiesLength(60), MaxMove(4) {
		Age = 0;
        MonsterNumber = 0;
        Elemen0 = Normal;
        Elemen1 = Normal;
        HP = 0;
        Attack = 0;
        Defense = 0;
        Speed = 0;
        DefaultLevel = 0;        
        IsCombined = 0;
        NextEvolutionLevel = 0;
        NextEvoNo = 0;
		DefaultSkills = new unsigned int[MaxMove];
		DefaultSkills[0] = 0;
		DefaultSkills[1] = 0;
		DefaultSkills[2] = 0;
		DefaultSkills[3] = 0;
		Spesies = new char [MaxSpesiesLength];
		Spesies[0] = 'U';
		Spesies[1] = 'n';
		Spesies[2] = 'k';
		Spesies[3] = 'n';
		Spesies[4] = 'o';
		Spesies[5] = 'w';
		Spesies[6] = 'n';
		Spesies[7] = '\0';
}

//Constructor dengan Parameter
Monster::Monster (unsigned int _MonsterNumber, char* _Spesies, ElemenType _Elemen0, ElemenType _Elemen1, unsigned int _HP, unsigned int _Attack, unsigned int _Defense, unsigned int _Speed, unsigned int _DefaultLevel, unsigned int* _DefaultSkills, unsigned int _IsCombined, unsigned int _NextEvolutionLevel, unsigned int _NextEvoNo): MaxSpesiesLength(60), MaxMove(4) {
        Age = 0;
        MonsterNumber = _MonsterNumber;
        Elemen0 = _Elemen0;
        Elemen1 = _Elemen1;
        HP = _HP;		
        Attack = _Attack;
        Defense = _Defense;
        Speed = _Speed;
        DefaultLevel = _DefaultLevel;        
        IsCombined = _IsCombined;
        NextEvolutionLevel = _NextEvolutionLevel;
        NextEvoNo = _NextEvoNo;		
		int i;
		Spesies = new char[MaxSpesiesLength];
		for (i=0;i<MaxSpesiesLength;i++) {
			this->Spesies[i] = _Spesies[i];
		}	
		
		DefaultSkills = new unsigned int[MaxMove];
		for (i=0;i<MaxMove;i++) {
			this->DefaultSkills[i] = _DefaultSkills[i];
		}			
}

//Copy Constructor
Monster::Monster(const Monster& M): MaxSpesiesLength(M.MaxSpesiesLength), MaxMove(M.MaxMove) {
    this->Age = M.Age;
    this->MonsterNumber = M.MonsterNumber;       
    this->Elemen0 = M.Elemen0;
    this->Elemen1 = M.Elemen1;
    this->HP = M.HP;
    this->Attack = M.Attack;
    this->Defense = M.Defense;
    this->Speed = M.Speed;
    this->DefaultLevel = M.DefaultLevel;
    this->IsCombined = M.IsCombined;
    this->NextEvolutionLevel = M.NextEvolutionLevel;
    this->NextEvoNo = M.NextEvoNo;
	
	//this->MaxSpesiesLength = M.MaxSpesiesLength;
	Spesies = new char[MaxSpesiesLength];
	for (int i=0;i<MaxSpesiesLength;i++) {
		this->Spesies[i] = M.Spesies[i];
	}
	
	//this->MaxMove = M.MaxMove;
	DefaultSkills = new unsigned int[MaxMove];
	for (int i=0;i<MaxMove;i++) {
		this->DefaultSkills[i] = M.DefaultSkills[i];
	}
	
}


//Operator Assignment
Monster Monster::operator= (const Monster& M) {
	//this->MaxSpesiesLength = M.MaxSpesiesLength;
    //this->MaxMove = M.MaxMove;

    delete [] Spesies;
    delete [] DefaultSkills;
    this->Spesies = new char[M.MaxSpesiesLength];
    this->DefaultSkills = new unsigned int[M.MaxMove];
    
    this->Age = M.Age;
    this->MonsterNumber = M.MonsterNumber;       
    this->Elemen0 = M.Elemen0;
    this->Elemen1 = M.Elemen1;
    this->HP = M.HP;
    this->Attack = M.Attack;
    this->Defense = M.Defense;
    this->Speed = M.Speed;
    this->DefaultLevel = M.DefaultLevel;
    this->IsCombined = M.IsCombined;
    this->NextEvolutionLevel = M.NextEvolutionLevel;
    this->NextEvoNo = M.NextEvoNo;
	
	for (int i=0;i<MaxSpesiesLength;i++) {
		this->Spesies[i] = M.Spesies[i];
	}
		
	for (int i=0;i<MaxMove;i++) {
		this->DefaultSkills[i] = M.DefaultSkills[i];
	}
	int sukses = 1;
	if (sukses == 1) {
		throw 1;
		return *this;		
	}
	else
		throw 0;
}


//Destructor
Monster::~Monster() {
	delete [] Spesies;
	delete [] DefaultSkills;
}


unsigned int Monster::getMonsterNumber()
{
	return MonsterNumber;
}
char* Monster::getSpesies()
{
	return Spesies;
}

ElemenType Monster::getElemen0()
{
	return Elemen0;
}

ElemenType Monster::getElemen1()
{
	return Elemen1;
}

unsigned int Monster::getHP()
{
	return HP;
}

unsigned int Monster::getAttack()
{
	return Attack;
}

unsigned int Monster::getDefense()
{
	return Defense;
}

unsigned int Monster::getSpeed()
{
	return Speed;
}

unsigned int Monster::getDefaultLevel()
{
	return DefaultLevel;
}

unsigned int Monster::getDefaultSkills1()
{
	return DefaultSkills[0];
}

unsigned int Monster::getDefaultSkills2()
{
	return DefaultSkills[1];
}

unsigned int Monster::getDefaultSkills3()
{
	return DefaultSkills[2];
}

unsigned int Monster::getDefaultSkills4()
{
	return DefaultSkills[3];
}

unsigned int Monster::getIsCombined()
{
	return IsCombined;
}

unsigned int Monster::getNextEvolutionLevel()
{
	return NextEvolutionLevel;
}

unsigned int Monster::getNextEvoNo()
{
	return NextEvoNo;
}

void Monster::tulisMonster () {
	printf("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\nNama ELEMEN 2: %s\nNama ELEMEN 1: %s", MonsterNumber, Spesies, Elemen0, Elemen1, HP, Attack, Defense, Speed, DefaultLevel, DefaultSkills[0], DefaultSkills[1], DefaultSkills[2], DefaultSkills[3], IsCombined, NextEvolutionLevel, NextEvoNo, getNameElemen2(), getNameElemen1());	
}

char* Monster::getNameElemen1() {
	if (Elemen0 == 0 || Elemen0 == 255) {
		NameOfElemen1[0] = '_';
		NameOfElemen1[1] = 'N';
		NameOfElemen1[2] = 'U';
		NameOfElemen1[3] = 'L';
		NameOfElemen1[4] = 'L';
		NameOfElemen1[5] = '\0';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 1) {
		NameOfElemen1[0] = 'P';
		NameOfElemen1[1] = 's';
		NameOfElemen1[2] = 'y';
		NameOfElemen1[3] = 'c';
		NameOfElemen1[4] = 'h';
		NameOfElemen1[5] = 'i';
		NameOfElemen1[6] = 'c';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
 		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 2) {
		NameOfElemen1[0] = 'F';
		NameOfElemen1[1] = 'i';
		NameOfElemen1[2] = 'g';
		NameOfElemen1[3] = 'h';
		NameOfElemen1[4] = 't';
		NameOfElemen1[5] = '\0';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 3) {
		NameOfElemen1[0] = 'N';
		NameOfElemen1[1] = 'o';
		NameOfElemen1[2] = 'r';
		NameOfElemen1[3] = 'm';
		NameOfElemen1[4] = 'a';
		NameOfElemen1[5] = 'l';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 4) {
		NameOfElemen1[0] = 'W';
		NameOfElemen1[1] = 'a';
		NameOfElemen1[2] = 't';
		NameOfElemen1[3] = 'e';
		NameOfElemen1[4] = 'r';
		NameOfElemen1[5] = '\0';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 5) {
		NameOfElemen1[0] = 'G';
		NameOfElemen1[1] = 'r';
		NameOfElemen1[2] = 'a';
		NameOfElemen1[3] = 's';
		NameOfElemen1[4] = 's';
		NameOfElemen1[5] = '\0';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	else if (Elemen0 == 6) {
		NameOfElemen1[0] = 'G';
		NameOfElemen1[1] = 'r';
		NameOfElemen1[2] = 'o';
		NameOfElemen1[3] = 'u';
		NameOfElemen1[4] = 'n';
		NameOfElemen1[5] = 'd';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 7) {		
		NameOfElemen1[0] = 'F';
		NameOfElemen1[1] = 'l';
		NameOfElemen1[2] = 'y';
		NameOfElemen1[3] = 'i';
		NameOfElemen1[4] = 'n';
		NameOfElemen1[5] = 'g';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 8) {
		NameOfElemen1[0] = 'I';
		NameOfElemen1[1] = 'c';
		NameOfElemen1[2] = 'e';
		NameOfElemen1[3] = '\0';
		NameOfElemen1[4] = '\0';
		NameOfElemen1[5] = '\0';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 9) {
		NameOfElemen1[0] = 'E';
		NameOfElemen1[1] = 'l';
		NameOfElemen1[2] = 'e';
		NameOfElemen1[3] = 'c';
		NameOfElemen1[4] = 't';
		NameOfElemen1[5] = 'r';
		NameOfElemen1[6] = 'i';
		NameOfElemen1[7] = 'c';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
	
	else if (Elemen0 == 10) {
		NameOfElemen1[0] = 'D';
		NameOfElemen1[1] = 'r';
		NameOfElemen1[2] = 'a';
		NameOfElemen1[3] = 'g';
		NameOfElemen1[4] = 'o';
		NameOfElemen1[5] = 'n';
		NameOfElemen1[6] = '\0';
		NameOfElemen1[7] = '\0';
		NameOfElemen1[8] = '\0';
		NameOfElemen1[9] = '\0';
		NameOfElemen1[10] =  '\0';
		return NameOfElemen1;
	}
}

char* Monster::getNameElemen2() {
	if (Elemen1 == 0 || Elemen1 == 255) {
		NameOfElemen2[0] = '_';
		NameOfElemen2[1] = 'N';
		NameOfElemen2[2] = 'U';
		NameOfElemen2[3] = 'L';
		NameOfElemen2[4] = 'L';
		NameOfElemen2[5] = '\0';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 1) {
		NameOfElemen2[0] = 'P';
		NameOfElemen2[1] = 's';
		NameOfElemen2[2] = 'y';
		NameOfElemen2[3] = 'c';
		NameOfElemen2[4] = 'h';
		NameOfElemen2[5] = 'i';
		NameOfElemen2[6] = 'c';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 2) {
		NameOfElemen2[0] = 'F';
		NameOfElemen2[1] = 'i';
		NameOfElemen2[2] = 'g';
		NameOfElemen2[3] = 'h';
		NameOfElemen2[4] = 't';
		NameOfElemen2[5] = '\0';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 3) {
		NameOfElemen2[0] = 'N';
		NameOfElemen2[1] = 'o';
		NameOfElemen2[2] = 'r';
		NameOfElemen2[3] = 'm';
		NameOfElemen2[4] = 'a';
		NameOfElemen2[5] = 'l';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 4) {
		NameOfElemen2[0] = 'W';
		NameOfElemen2[1] = 'a';
		NameOfElemen2[2] = 't';
		NameOfElemen2[3] = 'e';
		NameOfElemen2[4] = 'r';
		NameOfElemen2[5] = '\0';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 5) {
		NameOfElemen2[0] = 'G';
		NameOfElemen2[1] = 'r';
		NameOfElemen2[2] = 'a';
		NameOfElemen2[3] = 's';
		NameOfElemen2[4] = 's';
		NameOfElemen2[5] = '\0';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	else if (Elemen1 == 6) {
		NameOfElemen2[0] = 'G';
		NameOfElemen2[1] = 'r';
		NameOfElemen2[2] = 'o';
		NameOfElemen2[3] = 'u';
		NameOfElemen2[4] = 'n';
		NameOfElemen2[5] = 'd';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 7) {
		NameOfElemen2[0] = 'F';
		NameOfElemen2[1] = 'l';
		NameOfElemen2[2] = 'y';
		NameOfElemen2[3] = 'i';
		NameOfElemen2[4] = 'n';
		NameOfElemen2[5] = 'g';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 8) {
		NameOfElemen2[0] = 'I';
		NameOfElemen2[1] = 'c';
		NameOfElemen2[2] = 'e';
		NameOfElemen2[3] = '\0';
		NameOfElemen2[4] = '\0';
		NameOfElemen2[5] = '\0';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 9) {
		NameOfElemen2[0] = 'E';
		NameOfElemen2[1] = 'l';
		NameOfElemen2[2] = 'e';
		NameOfElemen2[3] = 'c';
		NameOfElemen2[4] = 't';
		NameOfElemen2[5] = 'r';
		NameOfElemen2[6] = 'i';
		NameOfElemen2[7] = 'c';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
	
	else if (Elemen1 == 10) {
		NameOfElemen2[0] = 'D';
		NameOfElemen2[1] = 'r';
		NameOfElemen2[2] = 'a';
		NameOfElemen2[3] = 'g';
		NameOfElemen2[4] = 'o';
		NameOfElemen2[5] = 'n';
		NameOfElemen2[6] = '\0';
		NameOfElemen2[7] = '\0';
		NameOfElemen2[8] = '\0';
		NameOfElemen2[9] = '\0';
		NameOfElemen2[10] =  '\0';
		return NameOfElemen2;
	}
}

unsigned int Monster::getDefaultSkills(int NoSkill) {
	return DefaultSkills[NoSkill];
}