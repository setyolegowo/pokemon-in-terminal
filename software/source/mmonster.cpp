#include "monster.h"
#include <stdio.h>
using namespace std;

int main () {
	
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
	//tabelMonster = new Monster[MaxMonsterList];
	int nMonster = 0;
	
	FILE * data;
	data = fopen("../executable/monster/monster.txt", "r");
	while (!feof(data)) {
		fgets(getInfo, 60, data);
		sscanf (getInfo,"%d %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&noMonster, nameMonster, &Elemen1, &Elemen2, &HPMon, &AttackMon, &DefenseMon, &SpeedMon, &defaultLevelMon, &defaultSkillMon[0], &defaultSkillMon[1], &defaultSkillMon[2], &defaultSkillMon[3], &isCombinedMon, &NextEvolutionLevelMon, &NextEvoNoMon);
		Monster SMonster(noMonster, nameMonster, Elemen1, Elemen2, HPMon, AttackMon, DefenseMon, SpeedMon, defaultLevelMon, defaultSkillMon, isCombinedMon, NextEvolutionLevelMon, NextEvoNoMon);
		//printf("\n\nNomor: %d\nNama: %s\nElemen: %d\nElemen2: %d\nHP: %d\nAttack: %d\nDefense %d\nSpeed: %d\nDefault Level: %d\nDefault Skill: {%d,%d,%d,%d}\nIsCombine: %d\nNextEvoLevel: %d\nNextEvoNo: %d\n", SMonster.getMonsterNumber(), SMonster.getSpesies(), SMonster.getElemen0(), SMonster.getElemen1(), SMonster.getHP(), SMonster.getAttack(), SMonster.getDefense(), SMonster.getSpeed(), SMonster.getDefaultLevel(), SMonster.getDefaultSkills1(), SMonster.getDefaultSkills2(), SMonster.getDefaultSkills3(), SMonster.getDefaultSkills4(), SMonster.getIsCombined(), SMonster.getNextEvolutionLevel(), SMonster.getNextEvoNo());	
		nMonster++;
		SMonster.tulisMonster();
	}
	
	printf("\n\n\t\tJUMLAH MONSTER YANG ADA: %d", nMonster);
	getchar();
	return 0;
}