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
 * Nama File            : listofitem.cpp
 * Bahasa               : C++
 * Compiler             : g++
 * Tanggal Diperbaharui : Selasa, 5 Maret 2013
 * Deskripsi            : 
 * - 
 */

#include <iostream>
#include <fstream>
#include "listofmonster.h"

using std::ifstream;
using std::string;
using std::list;
using std::cout;
using std::endl;

ListOfMonster::ListOfMonster() : MaxMonsterList(200), MaxLevelMonster(100), MinLevelMonster(1) {    
	char getInfo[60];
	unsigned int noMonster;
	char nameMonster[20];
	ElemenType Elemen1;
	ElemenType Elemen2;
	unsigned int HPMon;
	unsigned int AttackMon;
	unsigned int DefenseMon;
	unsigned int SpeedMon;
	unsigned int defaultLevelMon;
	unsigned int defaultSkillMon[4];	
	unsigned int isCombinedMon;
	unsigned int NextEvolutionLevelMon;
	unsigned int NextEvoNoMon;
		
	tabelMonster.clear();
	nMonster = 0;

	FILE * data;
	data = fopen("../executable/monster/monster.txt", "r");	
	while (!feof(data)) {		
		printf("aaaaaa\n");		
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		Monster SMonster(noMonster, nameMonster, Elemen1, Elemen2, HPMon, AttackMon, DefenseMon, SpeedMon, defaultLevelMon, defaultSkillMon, isCombinedMon, NextEvolutionLevelMon, NextEvoNoMon);		
		tabelMonster.push_back(SMonster);				
		nMonster++;
		//SMonster.tulisMonster();				
	}
}

ListOfMonster::~ListOfMonster() {
    tabelMonster.clear();
    tabelMonster.~list();
	nMonster = 0;
}


ListOfMonster::ListOfMonster(const ListOfMonster& LM) : MaxMonsterList(LM.MaxMonsterList), MaxLevelMonster(LM.MaxLevelMonster), MinLevelMonster(LM.MinLevelMonster) {  
	list<Monster>::iterator it;
    list<Monster> tTabel;
	
    this->nMonster = LM.nMonster;
    tTabel = LM.tabelMonster;
    it = tTabel.begin();
    while(it != tTabel.end())
    {
        tabelMonster.push_back(*it);
    }
}

ListOfMonster ListOfMonster::operator=(const ListOfMonster& LM) {
	list<Monster>::iterator it;
    list<Monster> tTabel;
	
	this->tabelMonster.clear();
    tTabel = LM.tabelMonster;
    it = tTabel.begin();    
//    this->nMonster = LM.nMonster;
    while(it != tTabel.end())
    {
        this->tabelMonster.push_back(*it);
    }
    
    return *this;
}

int ListOfMonster::getNMonster () {
	return nMonster;
}

Monster& ListOfMonster::getMonster(int i)
{
    list<Monster>::iterator it;
	it = tabelMonster.begin();
	if(i == 1)
		return *it;
	else {
		advance(it,i-1);
		return *it;
	}
}

/*
void ListOfMonster::LookUpTableMonster() {
	char getInfo[60];
	unsigned int noMonster;
	char nameMonster[20];
	ElemenType Elemen1;
	ElemenType Elemen2;
	unsigned int HPMon;
	unsigned int AttackMon;
	unsigned int DefenseMon;
	unsigned int SpeedMon;
	unsigned int defaultLevelMon;
	unsigned int defaultSkillMon[4];	
	unsigned int isCombinedMon;
	unsigned int NextEvolutionLevelMon;
	unsigned int NextEvoNoMon;
	FILE * data;
	FILE * datamonster;
	data = fopen("monster.txt", "r");
	datamonster = fopen("datamonster.txt", "w");
	while (!feof(data)) {
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		fprintf(datamonster, "Nomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n\n", noMonster, nameMonster, Elemen1, Elemen2, HPMon, AttackMon, DefenseMon, SpeedMon, defaultLevelMon, defaultSkillMon[0], defaultSkillMon[1], defaultSkillMon[2], defaultSkillMon[3], isCombinedMon, NextEvolutionLevelMon, NextEvoNoMon);
	}
}
*/